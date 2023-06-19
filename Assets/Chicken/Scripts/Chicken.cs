using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Chicken : MonoBehaviour
{
    private Animator chicken;
    public float gravity = 1.0f;
    private Vector3 moveDirection = Vector3.zero;
    CharacterController characterController;

    void Start()
    {
        chicken = GetComponent<Animator>();
        characterController = GetComponent<CharacterController>();
    }

    void Update()
    {
        characterController.Move(moveDirection * Time.deltaTime);
        moveDirection.y -= gravity * Time.deltaTime;

        if (chicken.GetCurrentAnimatorStateInfo(0).IsName("fly"))
        {
            chicken.SetBool("takeoff", false);
            chicken.SetBool("landing", false);
        }
        if (chicken.GetCurrentAnimatorStateInfo(0).IsName("idle"))
        {
            chicken.SetBool("randomwalk", false);
            chicken.SetBool("laydown", false);
            chicken.SetBool("getup", false);
            chicken.SetBool("landing", false);
            chicken.SetBool("takeoff", false);
            chicken.SetBool("fly", false);
        }
        if (chicken.GetCurrentAnimatorStateInfo(0).IsName("walk"))
        {
            chicken.SetBool("laydown", false);
            chicken.SetBool("getup", false);
        }
        if (chicken.GetCurrentAnimatorStateInfo(0).IsName("randomwalk"))
        {
            chicken.SetBool("laydown", false);
            chicken.SetBool("getup", false);
        }
        if ((Input.GetKeyUp(KeyCode.W))||(Input.GetKeyUp(KeyCode.A))||(Input.GetKeyUp(KeyCode.D))||(Input.GetKeyUp(KeyCode.S))||(Input.GetKeyUp(KeyCode.R))||(Input.GetKeyUp(KeyCode.E)))
        {
            chicken.SetBool("idle", true);
            chicken.SetBool("walk", false);
            chicken.SetBool("turnleft", false);
            chicken.SetBool("turnright", false);
            chicken.SetBool("walkslow", false);
            chicken.SetBool("scratch", false);
            chicken.SetBool("randomwalk", false);
            chicken.SetBool("eat", false);
        }
        if (Input.GetKeyDown(KeyCode.W))
        {
            chicken.SetBool("walk", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("getup", false);
        }
        if (Input.GetKeyDown(KeyCode.A))
        {
            chicken.SetBool("turnleft", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("randomwalk", false);
            chicken.SetBool("flyleft", true);
            chicken.SetBool("fly", false);
        }
        if (Input.GetKeyUp(KeyCode.A))
        {
            chicken.SetBool("flyleft", false);
            chicken.SetBool("fly", true);
        }
        if (Input.GetKeyDown(KeyCode.D))
        {
            chicken.SetBool("turnright", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("randomwalk", false);
            chicken.SetBool("flyright", true);
            chicken.SetBool("fly", false);
        }
        if (Input.GetKeyUp(KeyCode.D))
        {
            chicken.SetBool("flyright", false);
            chicken.SetBool("fly", true);
        }
        if (Input.GetKeyDown(KeyCode.F))
        {
            chicken.SetBool("randomwalk", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("walk", false);
            chicken.SetBool("eat", false);
        }
        if (Input.GetKeyDown(KeyCode.S))
        {
            chicken.SetBool("walkslow", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("walk", false);
        }
        if (Input.GetKeyDown(KeyCode.R))
        {
            chicken.SetBool("scratch", true);
            chicken.SetBool("idle", false);
        }
        if (Input.GetKeyDown("down"))
        {
            chicken.SetBool("laydown", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("walk", false);
            chicken.SetBool("randomwalk", false);
        }
        if (Input.GetKeyDown("up"))
        {
            chicken.SetBool("idle2", false);
            chicken.SetBool("getup", true);
        }
        if (Input.GetKeyDown(KeyCode.E))
        {
            chicken.SetBool("eat", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("randomwalk", false);
        }
        if (Input.GetKeyDown(KeyCode.Space))
        {
            chicken.SetBool("takeoff", true);
            chicken.SetBool("idle", false);
            chicken.SetBool("fly", false);
            chicken.SetBool("flyleft", false);
            chicken.SetBool("flyright", false);
            chicken.SetBool("landing", true);
        }
    }
}
