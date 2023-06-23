using System;
using UnityEngine;
using UnityEngine.XR.MagicLeap;


public class VoiceIntents : MonoBehaviour
{
    private bool HasBeenActivated = false;

    public SpawnObjectOnTrigger spawnObjectOnTrigger;

    private readonly MLPermissions.Callbacks permissionCallbacks = new MLPermissions.Callbacks();
    // voice intents configuration instance (needs to be assigned in Inspector)
    public MLVoiceIntentsConfiguration VoiceIntentsConfiguration;

    // subscribe to permission events
    private void Awake()
    {
        permissionCallbacks.OnPermissionGranted += OnPermissionGranted;
        permissionCallbacks.OnPermissionDenied += OnPermissionDenied;
        permissionCallbacks.OnPermissionDeniedAndDontAskAgain += OnPermissionDenied;
    }

    // unsubscribe from permission events
    private void OnDestroy()
    {
        permissionCallbacks.OnPermissionGranted -= OnPermissionGranted;
        permissionCallbacks.OnPermissionDenied -= OnPermissionDenied;
        permissionCallbacks.OnPermissionDeniedAndDontAskAgain -= OnPermissionDenied;
    }

    // request permission for voice input at start
    private void Start()
    {
        MLPermissions.RequestPermission(MLPermission.VoiceInput, permissionCallbacks);
    }

    // on voice permission denied, disable script
    private void OnPermissionDenied(string permission)
    {
        Debug.LogError($"Failed to initialize voice intents due to missing or denied {MLPermission.VoiceInput} permission. Please add to manifest. Disabling script.");
        enabled = false;
    }

    // on voice permission granted, initialize voice input
    private void OnPermissionGranted(string permission)
    {
        if (permission == MLPermission.VoiceInput)
            InitializeVoiceInput();
    }


    // check if voice commands setting is enabled, then set up voice intents
    private void InitializeVoiceInput()
    {
        bool isVoiceEnabled = MLVoice.VoiceEnabled;

        // if voice setting is enabled, try to set up voice intents
        if (isVoiceEnabled)
        {
            Debug.Log("Voice commands setting is enabled");
            var result = MLVoice.SetupVoiceIntents(VoiceIntentsConfiguration);
            if (result.IsOk)
            {
                MLVoice.OnVoiceEvent += MLVoiceOnOnVoiceEvent;
            }
            else
            {
                Debug.LogError("Voice could not initialize:" + result);
            }
        }

        // if voice setting is disabled, open voice settings so user can enable it
        else
        {
            Debug.Log("Voice commands setting is disabled - opening settings");
            UnityEngine.XR.MagicLeap.SettingsIntentsLauncher.LaunchSystemVoiceInputSettings();
            Application.Quit();
        }
    }

    private void MLVoiceOnOnVoiceEvent(in bool wasSuccessful, in MLVoice.IntentEvent voiceEvent)
    {
        if (wasSuccessful)
        {
            if (spawnObjectOnTrigger == null)
            {
                Debug.LogError("SpawnObjectOnTrigger reference is null.");
                return;
            }
            if (voiceEvent.EventID == 1) //1 as in begin
            {
                Debug.Log("Starting Assessment");
                if (!HasBeenActivated)
                {
                    spawnObjectOnTrigger.InitiateAssessment();
                    HasBeenActivated = true;
                }
            }
            if (voiceEvent.EventID == 0) //As it stop or false
            {
                Debug.Log("Ending Assessment");
                //spawnObjectOnTrigger.SpawnObjectAndTarget();

            }
            if (voiceEvent.EventID == 2) //As it stop or false
            {
                Debug.Log("Reset Scene");
                spawnObjectOnTrigger.ResetScene();

            }
            if (voiceEvent.EventID == 3) //As it stop or false
            {
                Debug.Log("Skipping Level");
                spawnObjectOnTrigger.LevelCompleted();

            }
        }
    }

}
