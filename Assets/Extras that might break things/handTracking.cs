using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR;
using UnityEngine.XR.MagicLeap;
using UnityEngine.SceneManagement;


using HandGestures = UnityEngine.XR.MagicLeap.InputSubsystem.Extensions.DeviceFeatureUsages.HandGesture;
using GestureClassification = UnityEngine.XR.MagicLeap.InputSubsystem.Extensions.MLGestureClassification;
using MLHeadTracking = UnityEngine.XR.MagicLeap.InputSubsystem.Extensions.MLHeadTracking;
using UnityEngine.XR.Interaction.Toolkit;
using UnityEngine.XR.InteractionSubsystems;


public class handTracking : MonoBehaviour
{


    [SerializeField] GameObject[] nest;
    [SerializeField] GameObject[] item;

    //Grabbed from MeshingExample in order to try instantiating object
    [SerializeField, Space, Tooltip("Prefab to shoot into the scene.")]
    private GameObject _shootingPrefab = null;
    private const float SHOOTING_FORCE = 300.0f;

    //For hands
    private InputDevice leftHandDevice;
    private InputDevice rightHandDevice;


    private MagicLeapInputs mlInputs;
    private MagicLeapInputs.ControllerActions controllerActions;
    private XRRayInteractor xRRayInteractor;
    private XRInputSubsystem inputSubsystem;
    private Camera _camera = null;


    private GameObject itemBeingMoved;

    private bool preRenderHandUpdate = true;

    bool isHolding = false;

    int handUsed = -1; //left is 0, right is 1

    // Start is called before the first frame update

    void Awake()
    {
        _camera = Camera.main;

    }
    void Start()
    {
        //Used for controller 

        xRRayInteractor = FindObjectOfType<XRRayInteractor>();

        mlInputs = new MagicLeapInputs();
        mlInputs.Enable();
        controllerActions = new MagicLeapInputs.ControllerActions(mlInputs);

        controllerActions.Trigger.performed += OnTriggerDown;
        controllerActions.Bumper.performed += OnBumperDown;
        controllerActions.Menu.performed += OnMenuDown;


        //Used for Handtracking
        if (!MLPermissions.CheckPermission(MLPermission.HandTracking).IsOk)
        {
            Debug.LogError($"You must include the {MLPermission.HandTracking} permission in the AndroidManifest.xml to run this example.");
            enabled = false;
            return;
        }

        GestureClassification.StartTracking();

        InputSubsystem.Extensions.MLHandTracking.StartTracking();
        InputSubsystem.Extensions.MLHandTracking.SetPreRenderHandUpdate(preRenderHandUpdate);


    }

    // Update is called once per frame
    void Update()
    {

        if (!leftHandDevice.isValid || !rightHandDevice.isValid)
        {
            List<InputDevice> foundDevices = new List<InputDevice>();
            InputDevices.GetDevices(foundDevices);

            foreach (InputDevice device in foundDevices)
            {
                if (device.name == GestureClassification.LeftGestureInputDeviceName)
                {
                    leftHandDevice = device;
                    continue;
                }

                if (device.name == GestureClassification.RightGestureInputDeviceName)
                {
                    rightHandDevice = device;
                    continue;
                }


            }
            return;
        }

        if (leftHandDevice.isValid)
        {
            leftHandDevice.TryGetFeatureValue(HandGestures.GestureTransformPosition, out Vector3 leftPos);
            GestureClassification.TryGetHandPosture(leftHandDevice, out GestureClassification.PostureType leftPosture);

            updateHandling(leftPos, leftPosture, 0);
        }

        if (rightHandDevice.isValid)
        {
            rightHandDevice.TryGetFeatureValue(HandGestures.GestureTransformPosition, out Vector3 rightPos);
            GestureClassification.TryGetHandPosture(rightHandDevice, out GestureClassification.PostureType rightPosture);

            updateHandling(rightPos, rightPosture, 1);
        }


    }

    private void OnBumperDown(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
    }

    private void OnMenuDown(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
    }


    private void OnTriggerDown(UnityEngine.InputSystem.InputAction.CallbackContext callbackContext)
    {
        if (xRRayInteractor.TryGetCurrentUIRaycastResult(out UnityEngine.EventSystems.RaycastResult result))
        {
            return;
        }

        // Create the object and necessary components and position it one meter along the camera's forward direction.
        GameObject spawnedObject = Instantiate(_shootingPrefab);

        spawnedObject.SetActive(true);
        spawnedObject.transform.localScale = new Vector3(0.1f, 0.1f, 0.1f);
        float distance = 1.0f; // One meter distance
        spawnedObject.transform.position = _camera.gameObject.transform.position + (_camera.gameObject.transform.forward * distance);
    }


    void updateHandling(Vector3 loc, GestureClassification.PostureType gesture, int handBeingUsed)
    {
        if(gesture == GestureClassification.PostureType.Pinch || gesture == GestureClassification.PostureType.Grasp)
        {
            if (isHolding && handBeingUsed == handUsed) //If we are already holding object with pinch then keep moving object
            {
                    Debug.Log("Moving Object");
                    MoveObject(loc, itemBeingMoved); //This only moves the item if 
                    return;

 
            }

            else //We are pinching but not holding object, check if we can hold object
            {

                for (int i = 0; i < item.Length; i++)
                {
                    GameObject tempItem = item[i];


                    if (PointInOABB(loc, tempItem.GetComponent<BoxCollider>())){ //If we are able to, pick up object
                    Debug.Log("Picking up");
                        itemBeingMoved = tempItem;
                    PickUp(handBeingUsed);
                    return;

                    }

                }
            }
        }
        else if (gesture == GestureClassification.PostureType.Open && handBeingUsed == handUsed) //We are not pinching and therefore are not/should not be holding object
        {
            if (isHolding)
            {
                LetGo();
                return;
            }
        }

    }

    void PickUp(int handBeingUsed)
    {
        handUsed = handBeingUsed;
        if (!isHolding)
        {
            isHolding = true;
        }
    }

    void MoveObject(Vector3 itemCenter,GameObject item)
    {
        if(isHolding)
        {
            item.transform.position = itemCenter; //Move item based on hand location
        }
    }

    void LetGo()
    {
        if (isHolding)
        {
            //If we are holding the object we want to change values to not holding anymore


                for (int i = 0; i < nest.Length; i++)
                {
                    GameObject currentShelf = nest[i];
                    Debug.Log("Not holding anymore");

                    isHolding = false;
                    handUsed = -1;
                    checkCollision(itemBeingMoved.transform.position, currentShelf.GetComponent<BoxCollider>(), currentShelf, itemBeingMoved);

                }



        }
    }

    void checkCollision(Vector3 point, BoxCollider box, GameObject target, GameObject toBePlaced)
    {
        if (!isHolding)
        {
           if (PointInOABB(point, box))
            {
                toBePlaced.GetComponent<Renderer>().enabled = false;
                target.GetComponent<Renderer>().enabled = false;

                Debug.Log("Congratulations");
                
            }
        }
    }

    bool PointInOABB(Vector3 point, BoxCollider box)
    {
        point = box.transform.InverseTransformPoint(point) - box.center;

        float halfX = (box.size.x * 0.5f);
        float halfY = (box.size.y * 0.5f);
        float halfZ = (box.size.z * 0.5f);
        if (point.x < halfX && point.x > -halfX &&
           point.y < halfY && point.y > -halfY &&
           point.z < halfZ && point.z > -halfZ)
            return true;
        else
            return false;
    }

    void Reset()
    {

        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex;
        int nextSceneIndex = currentSceneIndex + 1;

        if (nextSceneIndex == SceneManager.sceneCountInBuildSettings)
        {
            nextSceneIndex = 0;
        }

        SceneManager.LoadScene(nextSceneIndex);
    }



}
