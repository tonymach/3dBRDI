using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BreadcrumbManager : MonoBehaviour
{
    public GameObject breadcrumbPrefab; // Assign in Unity editor
    public GameObject objectToTrack; // Assign the object to track
    public float breadcrumbSpacing = 0.1f; // Distance between breadcrumbs
    public float breadcrumbDuration = 1f; // Duration each breadcrumb exists before disappearing

    private Vector3 lastBreadcrumbPosition;

    private void Start()
    {
        if (objectToTrack != null)
        {
            lastBreadcrumbPosition = objectToTrack.transform.position;
        }
    }

    private void Update()
    {
        if (objectToTrack != null)
        {
            // Check if the object has moved more than breadcrumbSpacing from the last breadcrumb
            if (Vector3.Distance(objectToTrack.transform.position, lastBreadcrumbPosition) >= breadcrumbSpacing)
            {
                SpawnBreadcrumb();
            }
        }
    }

    private void SpawnBreadcrumb()
    {
        GameObject breadcrumb = Instantiate(breadcrumbPrefab, objectToTrack.transform.position, Quaternion.identity);
        breadcrumb.transform.localScale = new Vector3(0.01f, 0.01f, 0.01f);
        Destroy(breadcrumb, breadcrumbDuration);
        lastBreadcrumbPosition = objectToTrack.transform.position;
    }


}
