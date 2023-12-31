﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ChickenCamera : MonoBehaviour
{
    public Vector3 offset;
    public Transform target;
    public float SmoothSpeed = 1.0f;


    void Update()
    {
        Vector3 DesiredPosition = target.position + offset;
        Vector3 SmoothPosition = Vector3.Lerp(transform.position, DesiredPosition, SmoothSpeed * Time.deltaTime);
        transform.position = SmoothPosition;
        transform.LookAt(target);
    }
}
