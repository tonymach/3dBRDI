using UnityEngine;
using System.Collections;

public class Cockatoo : MonoBehaviour {
    Animator cockatoo;
    IEnumerator coroutine;
	// Use this for initialization
	void Start () {
        cockatoo = GetComponent<Animator>();
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKey(KeyCode.S))
        {
            cockatoo.SetBool("idle", true);
            cockatoo.SetBool("walking", false);
            cockatoo.SetBool("eating", false);
        }
        if (Input.GetKey(KeyCode.W))
        {
            cockatoo.SetBool("walking", true);
            cockatoo.SetBool("idle", false);
            cockatoo.SetBool("eating", false);
        }
        if (Input.GetKey(KeyCode.F))
        {
            cockatoo.SetBool("eating", true);
            cockatoo.SetBool("idle", false);
            cockatoo.SetBool("walking", false);
            StartCoroutine("idle");
        }
        if (Input.GetKey(KeyCode.Space))
        {
            cockatoo.SetBool("takeoff", true);
            cockatoo.SetBool("idle",false);
            cockatoo.SetBool("walking", false);
            StartCoroutine("flying");
        }
        if (Input.GetKey(KeyCode.Space))
        {
            cockatoo.SetBool("landing", true);
            cockatoo.SetBool("flying", false);
            StartCoroutine("idle");
        }
        if (Input.GetKey(KeyCode.Keypad0))
        {
            cockatoo.SetBool("death", true);
            cockatoo.SetBool("idle", false);
            cockatoo.SetBool("walking", false);
        }
        if (Input.GetKey(KeyCode.E))
        {
            cockatoo.SetBool("jumping", true);
            cockatoo.SetBool("idle", false);
            StartCoroutine("idle");
        }
	}
    IEnumerator idle()
    {
        yield return new WaitForSeconds(0.2f);
        cockatoo.SetBool("idle", true);
        cockatoo.SetBool("eating", false);
        cockatoo.SetBool("landing", false);
        cockatoo.SetBool("jumping", false);
    }
    IEnumerator flying()
    {
        yield return new WaitForSeconds(0.8f);
        cockatoo.SetBool("flying", true);
        cockatoo.SetBool("takeoff", false);
        cockatoo.SetBool("landing", false);
    }
}
