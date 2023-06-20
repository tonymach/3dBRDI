using UnityEngine;
using UnityEngine.XR.MagicLeap;
using UnityEngine.XR.ARFoundation;

public class PlaneDetection : MonoBehaviour
{

    private ARPlaneManager planeManager;
    private readonly MLPermissions.Callbacks permissionCallbacks = new MLPermissions.Callbacks();

    private void Awake()
    {
        // subscribe to permission events
        permissionCallbacks.OnPermissionGranted += PermissionCallbacks_OnPermissionGranted;
        permissionCallbacks.OnPermissionDenied += PermissionCallbacks_OnPermissionDenied;
        permissionCallbacks.OnPermissionDeniedAndDontAskAgain += PermissionCallbacks_OnPermissionDenied;

    }

    private void OnDestroy()
    {
        // unsubscribe from permission events
        permissionCallbacks.OnPermissionGranted -= PermissionCallbacks_OnPermissionGranted;
        permissionCallbacks.OnPermissionDenied -= PermissionCallbacks_OnPermissionDenied;
        permissionCallbacks.OnPermissionDeniedAndDontAskAgain -= PermissionCallbacks_OnPermissionDenied;
    }

    private void Start()
    {
        // make sure the plane manager is disabled at the start of the scene before permissions are granted
        planeManager = FindObjectOfType<ARPlaneManager>();
        if (planeManager == null)
        {
            Debug.LogError("Failed to find ARPlaneManager in scene. Disabling Script");
            enabled = false;
        }
        else
        {
            planeManager.enabled = false;
        }

        // request spatial mapping permission for plane detection
        MLPermissions.RequestPermission(MLPermission.SpatialMapping, permissionCallbacks);
    }

    private void Update()
    {
        if (planeManager.enabled)
        {
            PlanesSubsystem.Extensions.Query = new PlanesSubsystem.Extensions.PlanesQuery
            {
                Flags = planeManager.requestedDetectionMode.ToMLQueryFlags() | PlanesSubsystem.Extensions.MLPlanesQueryFlags.Polygons | PlanesSubsystem.Extensions.MLPlanesQueryFlags.Semantic_Floor,
                BoundsCenter = Camera.main.transform.position,
                BoundsRotation = Camera.main.transform.rotation,
                BoundsExtents = Vector3.one * 10f,
                MaxResults = 100,
                MinPlaneArea = 0.04f
            };
        }
    }

    // if permission denied, disable plane manager
    private void PermissionCallbacks_OnPermissionDenied(string permission)
    {
        Debug.LogError($"Failed to create Planes Subsystem due to missing or denied {MLPermission.SpatialMapping} permission. Please add to manifest. Disabling script.");
        planeManager.enabled = false;
    }

    // if permission granted, enable plane manager
    private void PermissionCallbacks_OnPermissionGranted(string permission)
    {
        if (permission == MLPermission.SpatialMapping)
        {
            planeManager.enabled = true;
            Debug.Log("Plane manager is active");
        }
    }
}
