using UnityEngine;
using UnityEngine.XR.MagicLeap;

public class meshVisualizer : MonoBehaviour
{

#if UNITY_EDITOR || UNITY_MAGICLEAP || UNITY_ANDROID
    [SerializeField, Tooltip("The MeshingSubsystemComponent from which to get update on mesh types.")]
    private MeshingSubsystemComponent _meshingSubsystemComponent;

    [SerializeField, Tooltip("The type of mesh to render.")]
    private MeshingSubsystemComponent.MeshType _meshType;

    [SerializeField, Tooltip("The material to apply to the mesh.")]
    private Material _coloredMaterial = null;

    /// <summary>
    /// Register for new and updated fragments.
    /// </summary>
    void Start()
    {
        _meshingSubsystemComponent.meshAdded += HandleOnMeshReady;
        _meshingSubsystemComponent.meshUpdated += HandleOnMeshReady;
        SetVisualizationMode(_meshType);
    }

    /// <summary>
    /// Unregister callbacks.
    /// </summary>
    void OnDestroy()
    {
        _meshingSubsystemComponent.meshAdded -= HandleOnMeshReady;
        _meshingSubsystemComponent.meshUpdated -= HandleOnMeshReady;
    }

    /// <summary>
    /// Developers should clear mesh data when changing the mesh type at runtime.
    /// </summary>
    public void SetVisualizationMode(MeshingSubsystemComponent.MeshType type)
    {
        _meshingSubsystemComponent.requestedMeshType = type;
        _meshingSubsystemComponent.DestroyAllMeshes();
        _meshingSubsystemComponent.RefreshAllMeshes();
    }

    /// <summary>
    /// Handles the MeshReady event, which tracks and assigns the correct mesh renderer materials.
    /// </summary>
    /// <param name="meshId">Id of the mesh that got added / upated.</param>
    private void HandleOnMeshReady(UnityEngine.XR.MeshId meshId)
    {
        if (_meshingSubsystemComponent.meshIdToGameObjectMap.ContainsKey(meshId))
        {
            MeshRenderer meshRenderer =
                _meshingSubsystemComponent.meshIdToGameObjectMap[meshId].GetComponent<MeshRenderer>();
            meshRenderer.enabled = true;
            meshRenderer.material = _coloredMaterial;
        }
    }
#endif
}