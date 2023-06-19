using UnityEngine;
using UnityEngine.SceneManagement;

public class CollisionHandler : MonoBehaviour
{

    private float levelLoadDelay = 2f;
    [SerializeField] AudioClip success;
    [SerializeField] AudioClip failure;

    [SerializeField] ParticleSystem failureParticles;
    [SerializeField] ParticleSystem successParticles;

    AudioSource audioSource;

    bool isTransitioning;
    bool collisionsDisabled = false;


    private void Start()
    {
        audioSource = GetComponent<AudioSource>();
        isTransitioning = false;
    }

    private void Update()
    {
        RespondToDebugKeys();
    }

    void RespondToDebugKeys()
    {
        if (Input.GetKey(KeyCode.L)) {
            ToNextLevel();
        }
        else if(Input.GetKey(KeyCode.C))
        {
            collisionsDisabled = !collisionsDisabled;
        }

    }

    void OnCollisionEnter(Collision other)
    {

        if (!isTransitioning && !collisionsDisabled)
        {
            switch (other.gameObject.tag)
            {
                case "friendly":
                    Debug.Log("friendly");
                    break;
                case "finished":
                    Debug.Log("finished");
                    StartSuccessSequence();
                    break;
                default:
                    Debug.Log("blown up");
                    StartCrashSequence();
                    break;
            }

        }

    }

    void StartSuccessSequence()
    {
        DisableControls();
        audioSource.PlayOneShot(success);
        successParticles.Play();    
        Invoke("ToNextLevel", levelLoadDelay);
    }

    void DisableControls()
    {
        audioSource.Stop();
        GetComponent<Movement>().enabled = false;
        isTransitioning = true;
    }

    void StartCrashSequence()
    {
        DisableControls();
        audioSource.PlayOneShot(failure);
        failureParticles.Play();
        Invoke("ReloadLevel", levelLoadDelay);
    }

    void ToNextLevel()
    {

        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex;
        int nextSceneIndex = currentSceneIndex + 1;

        if(nextSceneIndex == SceneManager.sceneCountInBuildSettings)
        {
            nextSceneIndex = 0;
        }

        SceneManager.LoadScene(nextSceneIndex);
    }

    void ReloadLevel()
    {
        int currentSceneIndex = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(currentSceneIndex);
    }

}
