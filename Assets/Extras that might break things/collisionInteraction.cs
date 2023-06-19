using System.Collections.Generic;
using UnityEngine;
using UnityEngine.XR;
using UnityEngine.XR.MagicLeap;

public class collisionInteraction : MonoBehaviour
{
    private InputDevice leftHandDevice;
private InputDevice rightHandDevice;

void Start()
{
    // Check Hand Tracking Permissions before starting Gesture Classification
    if (MLPermissions.CheckPermission(MLPermission.HandTracking).IsOk)
    {
        InputSubsystem.Extensions.MLGestureClassification.StartTracking();
    }
}

void Update()
{
    //Do not continue if the gesture devices have not been initialized
    if (GesturesInitialized() == false)
    {
        return;
    }

    // Query the Input Devices for the detected postures
    leftHandDevice.TryGetFeatureValue(
        InputSubsystem.Extensions.DeviceFeatureUsages.HandGesture.GesturePosture, out uint leftPostureInt);
    rightHandDevice.TryGetFeatureValue(
        InputSubsystem.Extensions.DeviceFeatureUsages.HandGesture.GesturePosture, out uint rightPostureInt);

    // Convert the uints into a Posture Type
    InputSubsystem.Extensions.MLGestureClassification.PostureType leftHandPostureType =
        (InputSubsystem.Extensions.MLGestureClassification.PostureType)leftPostureInt;

    InputSubsystem.Extensions.MLGestureClassification.PostureType rightHandPostureType =
        (InputSubsystem.Extensions.MLGestureClassification.PostureType)rightPostureInt;

    // Write the detected posture into the Debug Log
    Debug.Log("Left Hand Posture: " + leftHandPostureType + " Right Hand Posture: " + rightHandPostureType);
}

/// Finds the gesture input devices and checks if Gestures have been initialized.
private bool GesturesInitialized()
{
    if (!leftHandDevice.isValid || !rightHandDevice.isValid)
    {
        Debug.Log("Looking for Left Hand Gesture Device...");
        leftHandDevice = GetInputDeviceByName(InputSubsystem.Extensions.MLGestureClassification.LeftGestureInputDeviceName);
        rightHandDevice = GetInputDeviceByName(InputSubsystem.Extensions.MLGestureClassification.RightGestureInputDeviceName);
        return false;
    }

    if (!leftHandDevice.TryGetFeatureValue(InputSubsystem.Extensions.DeviceFeatureUsages.HandGesture.GesturesEnabled,
            out bool gesturesEnabled) || gesturesEnabled == false)
    {
        Debug.Log("Gestures are Disabled");
        return false;
    }

    return true;
}

/// Simple method that returns an input device with a given name.
/// Use InputDevice.isValid to verify that an input device was found.
private InputDevice GetInputDeviceByName(string deviceName)
{
    List<UnityEngine.XR.InputDevice> devices = new List<UnityEngine.XR.InputDevice>();
    InputDevices.GetDevices(devices);
    foreach (UnityEngine.XR.InputDevice device in devices)
    {
        if (device.name == deviceName)
        {
            return device;
        }
    }

    return new InputDevice();
}
}