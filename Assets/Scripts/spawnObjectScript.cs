using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.MagicLeap;
using UnityEngine.Networking;
using static UnityEngine.XR.MagicLeap.MLAnchors.NativeBindings;


// This class is responsible for spawning objects and targets in the scene, and moving the selected object based on the user's hand gestures.
public class SpawnObjectOnTrigger : MonoBehaviour
{
    // Class to store object path data consisting of position and timestamp
    [System.Serializable]
    public class ObjectPathData
    {
        public Vector3 position;
        public float timestamp;

        public ObjectPathData(Vector3 position, float timestamp)
        {
            this.position = position;
            this.timestamp = timestamp;
        }
    }

    private MLAnchors.Request _mlAnchorsRequest;
    private MLAnchors.Request.Params _anchorRequestParams;
    private Dictionary<string, GameObject> _gameObjectsByAnchorId = new Dictionary<string, GameObject>();

    private List<ObjectPathData> objectPath = new List<ObjectPathData>();

    // Serialized variables to assign in the Unity editor
    [SerializeField] private GameObject[] objectPrefabs; // Array to hold object prefabs
    [SerializeField] private GameObject[] targetPrefabs; // Array to hold target prefabs
    [SerializeField] private GameObject fillerTargetPrefab; //Used as an alternative to the colored one
    [SerializeField] private GameObject eaglePrefab; // Assign in Unity editor
    [SerializeField] private GameObject objectPadPrefab;
    [SerializeField] private GameObject successParticle;

    [SerializeField] AudioClip successSound;

    [SerializeField] private ActionBasedController controller;
    [SerializeField] private bool reverseRotation = false;
    //End of Serialized variables 

    [SerializeField] private GameObject chicken;

    private GameObject target;

    private Direction[] availableDirections = { Direction.Right, Direction.Left, Direction.Up, Direction.Down };
    private Direction targetDirection = Direction.Left;

    private List<GameObject> spawnedTargets = new List<GameObject>(); // List to hold spawned targets

    private string[] birdTags = { "Red", "Blue", "Yellow" };
    private string levelTag = "Red";

    private Vector3 nestSize = new Vector3(0.5f, 0.5f, 0.5f);
    private LevelType currentLevelType = LevelType.Basic;

    private Camera mainCamera;
    private Vector3 targetPosition;

    private MagicLeapInputs mlInputs;
    private MagicLeapInputs.ControllerActions controllerActions;
    private GameObject selectedObject;
    private GameObject spawnedObject;

    private GameObject spawnedPadObject;

    // Variables related to object spawning and interaction
    private Vector3 initialSpawnLocation;
    private bool initialSpawnLocationSet = false;
    private bool resetStarted = false;

    private Transform previousControllerTransform;
    private float initialObjectDistance;

    private float spawnDistance = 1.0f; // 20 cm in front of the user's main camera

    //Gamification variables
    private int currentLevel = 1;
    private int levelCounter = 0;
    private float levelStartTime;

    [SerializeField] private float smoothness = 5.0f;

    private bool isTriggerPressed = false;

    private float reachDistance = 5f; // The maximum interaction distance. You can adjust this to your needs.


    [SerializeField] private GameObject breadcrumbPrefab;


    private void UpdateTargetPosition()
    {
        RaycastHit hit;
        if (Physics.Raycast(controller.transform.position, controller.transform.forward, out hit, reachDistance))
        {
            Vector3 directionToHitPoint = (hit.point - controller.transform.position).normalized;
            // Maintain the bird at a certain distance (for example, the initial distance) from the controller
            targetPosition = controller.transform.position + directionToHitPoint * initialObjectDistance;
        }
        else
        {
            targetPosition = controller.transform.position + controller.transform.forward * initialObjectDistance;
        }
    }

    void Start()
    {
        mainCamera = Camera.main;
        mlInputs = new MagicLeapInputs();
        mlInputs.Enable();
        controllerActions = new MagicLeapInputs.ControllerActions(mlInputs);

        controllerActions.Trigger.performed += OnTriggerDown;
        controllerActions.Trigger.canceled += OnTriggerUp;
        controllerActions.Menu.performed += Menu_Performed;
        controllerActions.Bumper.performed += HandleOnBumper;
        controllerActions.TouchpadTouch.performed += TouchpadTouch_performed;

        levelStartTime = Time.time;

        MLSegmentedDimmer.Activate();


        //Initialize Magic leap Spatial Anchor Requests
        _mlAnchorsRequest = new MLAnchors.Request();

        //Get the user's current Localization Info and debugs it
        MLResult mlResult = MLAnchors.GetLocalizationInfo(out MLAnchors.LocalizationInfo info);
        Debug.Log("Localization Info " + info);


    }


    void Update()
    {
        if (selectedObject == null || resetStarted)
        {
            //Check to make sure we are not prevented from updating
            return;
        }

        MoveObject();
        CheckObjectTargetInteraction();

        StorePreviousControllerTransform(); //Used to track controller transform

    }

    private void TouchpadTouch_performed(InputAction.CallbackContext obj)
    {
        Debug.LogError("TouchpadTouch_performed");
        LevelCompleted();
    }
    private void Menu_Performed(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
        Debug.LogError("Menu_Performed");
        

    }
    private void OnTriggerDown(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
        Debug.LogError("OnTriggerDown");
        isTriggerPressed = true;
        if (!resetStarted)
        {
            RaycastSelectObject();
        }

    }

    private void OnTriggerUp(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
        Debug.LogError("OnTriggerUp");
        isTriggerPressed = false;
        UnselectObject();

    }
    private void HandleOnBumper(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
        Debug.LogError("HandleOnBumper");
        if (!resetStarted)
            SpawnObjectAndTarget();
    }

    /*TODO: 
     * 1. Create conditions for spawning
     * 2. Collisions based on tags etc. 
     * 3. Reset everything
     * 
     *  How I'm thinking about doing it
     *  - make everything based on arrays so that we simply check each array rather than anything else
     * 
     */

    public void InitiateAssessment()
    {
        // Check if the initial spawn location is set, if not, set it
        if (!initialSpawnLocationSet)
        {
            initialSpawnLocation = mainCamera.gameObject.transform.position + (mainCamera.gameObject.transform.forward * spawnDistance) - new Vector3(0, 0.1f, 0);
            //            initialSpawnLocation = mainCamera.gameObject.transform.position + (mainCamera.gameObject.transform.forward * spawnDistance);
            initialSpawnLocationSet = true;
        }

        SpawnChicken(initialSpawnLocation - mainCamera.transform.up * 0.2f);
        SpawnObjectAndTarget();

    }

    public void SpawnObjectAndTarget()
    {

        if (objectPrefabs == null || objectPrefabs.Length == 0 || targetPrefabs == null || targetPrefabs.Length == 0)
        {
            Debug.LogError("Object prefab or target prefab is not assigned.");
            return;
        }

        //The intention here is to check what kind of level we are on, and instantiate based on that
        int randomIndex = Random.Range(0, objectPrefabs.Length); //We make a random index to know which target and object we are pursuing
        levelTag = birdTags[randomIndex]; //Why? so that then we can easily compare what we intend to check for?

        int directionIndex = Random.Range(0, availableDirections.Length);
        targetDirection = GenerateRandomDirection();
    
        // Check if the initial spawn location is set, if not, set it
        if (!initialSpawnLocationSet)
        {
            initialSpawnLocation = mainCamera.gameObject.transform.position + (mainCamera.gameObject.transform.forward * spawnDistance) - new Vector3(0, 0.1f, 0);
            //            initialSpawnLocation = mainCamera.gameObject.transform.position + (mainCamera.gameObject.transform.forward * spawnDistance);
            initialSpawnLocationSet = true;
        }

        float randomDistance = Random.Range(-0.05f, 0.05f);

        //Creating the level based on conditions

        switch (currentLevelType)
        {
            case LevelType.Basic:
                reverseRotation = false;
                CreateBasicLevel(randomIndex, targetDirection);
                break;

            case LevelType.Inverted:
                reverseRotation = true; 
                CreateBasicLevel(randomIndex, targetDirection);
                break;

            case LevelType.ColorMatch:
                reverseRotation = false;

                CreateFourNestLevel(randomIndex, targetDirection);
                //we want 4 nests, only one being the target color
                break;

            case LevelType.ColorMatchReverse:
                reverseRotation = true; 
                CreateFourNestLevel(randomIndex, targetDirection);
                break;

            case LevelType.RandomEagle:
                reverseRotation = false;
                CreateFourNestLevel(randomIndex, targetDirection);
                // 30% chance to spawn an eagle
                if (Random.Range(0f, 1f) < 0.3f)
                {
                    GameObject eagle = Instantiate(eaglePrefab, initialSpawnLocation, Quaternion.identity);
                    eagle.transform.localScale = new Vector3(0.3f, 0.3f, 0.3f);
                }
                break;
        }

        InstantiateObjectPad();

    }

    private void CreateBasicLevel(int index, Direction direction)
    {
        /*
         * Takes in the current selected bird and target, generates it in a random location
         */

        spawnedObject = Instantiate(objectPrefabs[index]);
        spawnedObject.transform.localScale = new Vector3(2f, 2f, 2f);
        spawnedObject.transform.position = initialSpawnLocation;

        var tempTarget = Instantiate(targetPrefabs[index]);
        tempTarget.transform.localScale = nestSize;
        var offset = SetTargetPosition(spawnedObject, direction);
        tempTarget.transform.position = offset;


        GameObject breadcrumbManagerObject = new GameObject("BreadcrumbManager");
        BreadcrumbManager breadcrumbManager = breadcrumbManagerObject.AddComponent<BreadcrumbManager>();
        breadcrumbManager.breadcrumbPrefab = breadcrumbPrefab;
        breadcrumbManager.breadcrumbPrefab.transform.localScale = new Vector3(0.1f, 0.1f, 0.1f);
        breadcrumbManager.objectToTrack = spawnedObject;


        spawnedTargets.Add(tempTarget);




    }


    void CreateFourNestLevel(int index, Direction direction)
    {

        /*
         *  Takes in the current selected bird and target, generates it in a random location and fills the other 3 locations
         */

        spawnedObject = Instantiate(objectPrefabs[index]);
        spawnedObject.transform.localScale = new Vector3(2f, 2f, 2f);
        spawnedObject.transform.position = initialSpawnLocation;

        List<Direction> remainingDirections = new List<Direction>(availableDirections);
        remainingDirections.Remove(direction);


        // Instantiate the correct target in the selected direction
        GameObject correctTarget = Instantiate(targetPrefabs[index]);
        correctTarget.transform.localScale = nestSize;
        var offset = SetTargetPosition(spawnedObject, direction);
        correctTarget.transform.position = offset;
        spawnedTargets.Add(correctTarget);


        for (int i = 0; i < remainingDirections.Count; i++)
        {
            GameObject wrongTarget = Instantiate(fillerTargetPrefab);
            wrongTarget.transform.localScale = nestSize / 2f ;
            var wrongTargetOffset = SetTargetPosition(spawnedObject, remainingDirections[i]);
            wrongTarget.transform.position = wrongTargetOffset;
            spawnedTargets.Add(wrongTarget);
        }


        GameObject breadcrumbManagerObject = new GameObject("BreadcrumbManager");
        BreadcrumbManager breadcrumbManager = breadcrumbManagerObject.AddComponent<BreadcrumbManager>();
        breadcrumbManager.breadcrumbPrefab = breadcrumbPrefab;
        breadcrumbManager.breadcrumbPrefab.transform.localScale = new Vector3(0.1f, 0.1f, 0.1f);
        breadcrumbManager.objectToTrack = spawnedObject;

    }

    private void InstantiateObjectPad()
    {
        spawnedPadObject = Instantiate(objectPadPrefab);
        spawnedPadObject.transform.localScale = new Vector3(1.5f, 1.5f, 1.5f);
        spawnedPadObject.transform.position = initialSpawnLocation - mainCamera.transform.up * 0.1f;
    }

    public void SpawnChicken(Vector3 spawnPosition)
    {
        // Instantiate the chicken
        GameObject chickenInstance = Instantiate(chicken, spawnPosition, Quaternion.identity);
        chickenInstance.transform.localScale = new Vector3(0.8f, 0.8f, 0.8f);

        // Add a Rigidbody component to enable physics
        Rigidbody rb = chickenInstance.AddComponent<Rigidbody>();

        // Set physics properties (optional)
        rb.mass = 1f; // adjust mass
        rb.drag = 0.5f; // adjust drag
        rb.angularDrag = 0.05f; // adjust angular drag

        // Add force to the chicken (optional)
        rb.AddForce(Vector3.up * 5f, ForceMode.Impulse); // launches the chicken upwards
    }

    private Direction GenerateRandomDirection()
    {
        int randomValue = Random.Range(0, 4);

        switch (randomValue)
        {
            case 0:
                return Direction.Right;
            case 1:
                return Direction.Left;
            case 2:
                return Direction.Up;
            case 3:
                return Direction.Down;
            default:
                return Direction.Right;
        }
    }

    private Vector3 SetTargetPosition(GameObject spawnedObject, Direction direction)
    {
        int randomDirection = Random.Range(0, 4);

        Vector3 offset = Vector3.zero;
        float targetDistance = 0.4f;

        switch (direction)
        {
            case Direction.Right:
                offset = mainCamera.transform.right * targetDistance;
                break;
            case Direction.Left:
                offset = -mainCamera.transform.right * targetDistance;
                break;
            case Direction.Up:
                offset = Vector3.up * targetDistance;
                break;
            case Direction.Down:
                offset = Vector3.down * targetDistance;
                break;
        }

        return spawnedObject.transform.position + offset;
    }

    private void CheckObjectTargetInteraction()
    {
        if (selectedObject != null)
        {
            float interactionDistance = 0.1f; // The distance to interact with the target
            foreach (GameObject target in spawnedTargets)
            {
                if (Vector3.Distance(selectedObject.transform.position, target.transform.position) <= interactionDistance)
                {
                    // If it's color match level check if the tags match
                    if (currentLevelType == LevelType.ColorMatch && selectedObject.tag != target.tag)
                    {
                        // Failed condition, handle it here
                    }
                    else
                    {
                        LevelCompleted();
                        break;
                    }
                }
            }
        }
    }


    private void LevelCompleted() //LevelCompleted
    {
        levelStartTime = Time.time;
        UpdateLevel();
        ShowSuccessFeedback(spawnedTargets[0]); //Real target is always the first in the index
        SendObjectPathData(levelCounter.ToString(), currentLevelType.ToString(), "Alpha", objectPath);

        resetStarted = true;
        Invoke("ResetScene", 2f);
    }

    private void ShowSuccessFeedback(GameObject targetObject) //attaches success particles to gameobject
    {
        // Attach the particle system to the target
        if (successParticle != null)
        {
            ParticleSystem particles = targetObject.AddComponent<ParticleSystem>();
            particles.Stop(); // Stop the particle system by default

            var mainModule = particles.main;
            mainModule.duration = 2f;
            particles.GetComponent<Renderer>().material = successParticle.GetComponent<Renderer>().material; // Copy the material from the successParticle
            float sizeMultiplier = 0.2f; // Change this value to adjust the size
            mainModule.startSizeMultiplier = successParticle.GetComponent<ParticleSystem>().main.startSizeMultiplier * sizeMultiplier;

            particles.Play();
        }

        if (successSound != null)
        {
            AudioSource audioSource = targetObject.AddComponent<AudioSource>(); // Add an AudioSource component to the target
            audioSource.clip = successSound;
            audioSource.playOnAwake = false;
            audioSource.spatialBlend = 1f; // Set the AudioSource to 3D sound
            audioSource.Play(); // Play the success sound
        }
    }


    private void UpdateLevel()
    { 
        levelCounter++;
        // If the counter reaches 15, move to the next level and reset the counter
        if (levelCounter >= 10)
        {
            currentLevel++;
            levelCounter = 0;
        }

        switch (currentLevel)
        {
            case 1:
                currentLevelType = LevelType.Basic;
                break;
            case 2:
                currentLevelType = LevelType.Inverted;
                break;
            case 3:
                currentLevelType = LevelType.ColorMatch;
                break;
            case 4:
                currentLevelType = LevelType.ColorMatchReverse;
                break;
            case 5:
                currentLevelType = LevelType.RandomEagle;
                break;
            case 6:
                currentLevelType = LevelType.Basic;
                break;
        }


}


    private void ResetScene() //Resets everything
    {
        // Reset the object and pad
        Destroy(spawnedObject);
        Destroy(spawnedPadObject);

        // Reset the selected object if it exists
        if (selectedObject != null)
            Destroy(selectedObject);

        // Iterate through the spawnedTargets list and destroy each GameObject
        foreach (GameObject target in spawnedTargets)
        {
            Destroy(target);
        }

        // Clear the spawnedTargets list
        spawnedTargets.Clear();

        // Spawn new object and target
        SpawnObjectAndTarget();

        // Clear the object path data
        objectPath.Clear();

        previousControllerTransform = null;

        lastControllerPosition = Vector3.zero;

        resetStarted = false;
    }


    /*
     * Object Manipulation
     */


    private void RaycastSelectObject()
    {
        RaycastHit hit;

        // Cast a ray from the controller's current position in the direction it's facing
        if (Physics.Raycast(controller.transform.position, controller.transform.forward, out hit))
        {
            // Check if the hit object is of interest based on its tag
            if (IsTagInArray(hit.collider.gameObject.tag, birdTags))
            {
                selectedObject = hit.collider.gameObject;
                initialObjectDistance = Vector3.Distance(selectedObject.transform.position, controller.transform.position);

                // Set the target position to the hit position
                targetPosition = hit.point;
            }
        }
        else
        {
            selectedObject = null;
        }
    }


    private bool IsTagInArray(string tag, string[] tagArray)
    {
        foreach (string t in tagArray)
        {
            if (tag.Equals(t))
            {
                return true;
            }
        }
        return false;
    }

    private void UnselectObject()
    {
        Debug.LogError("UnselectObject");
        previousControllerTransform = null;
        lastControllerPosition = Vector3.zero;
        selectedObject = null;
    }


    private Vector3 lastControllerPosition;

    private void MoveObject()
    {
        if (selectedObject != null)
        {
            if (isTriggerPressed)
            {
                // Update target position
                UpdateTargetPosition();

                // If reverse is on
                if (reverseRotation)
                {
                    MoveInReverse();
                }
                // If reverse is off
                else
                {
                    MoveNormally();
                }
            }
            else // If the trigger is not pressed
            {
                // Reset last controller position
                lastControllerPosition = Vector3.zero;
            }

            // Log the new object path data
            objectPath.Add(new ObjectPathData(selectedObject.transform.position, Time.time));
        }
    }

    private void MoveNormally()
    {
        // Smoothly move the bird towards the target position
        selectedObject.transform.position = targetPosition;

        // Rotate the bird to align with the controller's forward direction
        Vector3 controllerForward = -controller.transform.forward; // Added a negative so the bird ends up facing the user
        controllerForward.y = 0f; // Ignore vertical component to ensure the bird stays upright
        Quaternion targetRotation = Quaternion.LookRotation(controllerForward, Vector3.up);
        selectedObject.transform.rotation = targetRotation;
    }

    private void MoveInReverse()
    {
        // If it's the first frame the trigger is pressed, store the controller's position and exit the function early
        if (lastControllerPosition == Vector3.zero)
        {
            lastControllerPosition = targetPosition;
            return;
        }

        // Calculate the change in controller's position
        Vector3 controllerMovement = targetPosition - lastControllerPosition;

        // Update the last controller position
        lastControllerPosition = targetPosition;

        // Move the bird in the opposite direction of the controller's movement
        selectedObject.transform.position -= controllerMovement;

        // Rotate the bird to align with the opposite of the controller's forward direction
        Vector3 controllerBackward = -controller.transform.forward;
        controllerBackward.y = 0f; // Ignore vertical component to ensure the bird stays upright
        Quaternion targetRotation = Quaternion.LookRotation(controllerBackward, Vector3.up);
        selectedObject.transform.rotation = Quaternion.Lerp(selectedObject.transform.rotation, targetRotation, smoothness * Time.deltaTime);
    }


    //Nothing needed to change here

    /*  
     *  Data gathering functions
     */

    private void StorePreviousControllerTransform()
    {
        if (previousControllerTransform == null)
        {
            previousControllerTransform = new GameObject("PreviousControllerTransform").transform;
        }

        previousControllerTransform.position = controller.transform.position;
        previousControllerTransform.rotation = controller.transform.rotation;
    }



    [System.Serializable]
    public class ExperimentData
    {
        public string trial;
        public string condition;
        public string participantId;
        public List<float> x_positions;
        public List<float> y_positions;
        public List<float> z_positions;
        public List<float> timestamps; // Add this line to include timestamps in your ExperimentData

    }

    private IEnumerator SendObjectPathDataCoroutine(string trial, string condition, string participantId, List<SpawnObjectOnTrigger.ObjectPathData> objectPath)
    {
        Debug.Log("Starting SendObjectPathDataCoroutine");

        // Create lists to hold the x, y, and z positions
        List<float> x_positions = new List<float>();
        List<float> y_positions = new List<float>();
        List<float> z_positions = new List<float>();
        List<float> timestamps = new List<float>(); // Add this line to create a list for timestamps


        // Populate the position lists
        foreach (SpawnObjectOnTrigger.ObjectPathData pathData in objectPath)
        {
            x_positions.Add(pathData.position.x);
            y_positions.Add(pathData.position.y);
            z_positions.Add(pathData.position.z);
            timestamps.Add(pathData.timestamp); // Add this line to populate the timestamp list

        }

        // Create a new instance of ExperimentData
        ExperimentData data = new ExperimentData();
        data.trial = trial;
        data.condition = condition;
        data.participantId = participantId;
        data.x_positions = x_positions;
        data.y_positions = y_positions;
        data.z_positions = z_positions;
        data.timestamps = timestamps; // Add this line to add timestamps to your ExperimentData

        // Convert the data to JSON
        string json = JsonUtility.ToJson(data);

        Debug.Log("JSON data: " + json);

        // Create a new UnityWebRequest and assign the target URL
        using (UnityWebRequest www = new UnityWebRequest("https://brdiserver.onrender.com/postdata", UnityWebRequest.kHttpVerbPOST))
        {
            byte[] bodyRaw = System.Text.Encoding.UTF8.GetBytes(json);
            www.uploadHandler = new UploadHandlerRaw(bodyRaw);
            www.downloadHandler = new DownloadHandlerBuffer();
            www.SetRequestHeader("Content-Type", "application/json");

            Debug.Log("Sending request");
            yield return www.SendWebRequest();

            if (www.result == UnityWebRequest.Result.ConnectionError || www.result == UnityWebRequest.Result.ProtocolError)
            {
                Debug.LogError("Error in request: " + www.error);
            }
            else
            {
                Debug.Log("Response: " + www.downloadHandler.text);
            }
        }
    }


    public void SendObjectPathData(string trial, string condition, string participantId, List<SpawnObjectOnTrigger.ObjectPathData> objectPath)
    {
        Debug.Log("SendObjectPathDataCoroutine started");
        StartCoroutine(SendObjectPathDataCoroutine(trial, condition, participantId, objectPath));
    }


}


public enum LevelType
{
    Basic, // Initial simple level
    Inverted, // Level with inverted controls
    ColorMatch, // Level where the color of the bird and eggs should match
    ColorMatchReverse,
    RandomEagle // Level where an eagle can appear randomly
}

public enum Direction
{
    Right,
    Left,
    Up,
    Down
}



/*  As of May, 2023: The purpose of this script is to create a multi-level game featuring targets, represented to the user as bird nests, and birds of various types, which serve as the objects.
Initially, a nest is instantiated either above, below, left, or right of the bird. The user is then tasked with moving the bird to the nest. This basic scenario is repeated ten times.
In the next level, the nest remains randomly positioned around the bird, but the controls are completely inverted. This condition is again repeated ten times.
In the subsequent level, nests are generated in all four directions (up, down, left, and right). Each bird is a different color, and so are the eggs in the nests. The user's task is to match the bird color to the color of the eggs in the nest. If the user places the bird in the wrong nest, it's considered a failed condition, but if they match correctly, it's a success. This condition is repeated ten times, then it repeats again with inverted controls.
In the following level, we return to the original simple condition. However, a surprise awaits the user: on three random trials out of ten, when the user is about to place the bird in the nest, an eagle appears in the nest and a new nest appears on the opposite side. For instance, if the original nest was on the left, the new one would be on the right, and vice versa for up and down.
This script is designed for a cognitive assessment tool in augmented reality, specifically for the Unity engine.
*/

