﻿using UnityEngine;
using System.Collections;

public class CameraRotate : MonoBehaviour {
    int speed = 30;
	// Use this for initialization
	void Start () {
	
	}
	
	// Update is called once per frame
	void Update () {
        transform.Rotate(Vector3.up * Time.deltaTime * speed, Space.World);
	}
}
