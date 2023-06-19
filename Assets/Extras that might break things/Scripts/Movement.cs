using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] float mainThrust = 1000f;
    [SerializeField] float rotationTrhust = 100f;
    [SerializeField] AudioClip mainThrustAudio;


    [SerializeField] ParticleSystem mainThrustParticles;
    [SerializeField] ParticleSystem leftThrustParticles;
    [SerializeField] ParticleSystem rightThrustParticles;

    Rigidbody rigidBody;
    AudioSource audioSource;


    // Start is called before the first frame update
    void Start()
    {
        rigidBody = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();
    }

    // Update is called once per frame
    void Update()
    {
        ProcessThurst();
        ProcessRotation();
    }


    //Checks and processes Input
    void ProcessThurst()
    {
        if (Input.GetKey(KeyCode.Space) || Input.GetKey(KeyCode.W))
        {
            startThursting();

        }

        else
        {
            stopThrusting();

        }
    }

    void startThursting()
    {
        rigidBody.AddRelativeForce(Vector3.up * mainThrust * Time.deltaTime);
        if (!audioSource.isPlaying)
        {
            audioSource.PlayOneShot(mainThrustAudio);

        }
        if (!mainThrustParticles.isPlaying)
        {
            mainThrustParticles.Play();
        }
    }

    void stopThrusting()
    {
        if (audioSource.isPlaying)
        {
            audioSource.Stop();
        }
        if (mainThrustParticles.isPlaying)
        {
            mainThrustParticles.Stop();

        }
    }

    void ProcessRotation()
    {
        if (Input.GetKey(KeyCode.LeftArrow) || Input.GetKey(KeyCode.A))
        {
            RotateLeft();
        }
        else if (Input.GetKey(KeyCode.RightArrow) || Input.GetKey(KeyCode.D))
        {
            RotateRight();
        }
        else
        {
            stopRotationThrusters();
        }
    }


    void stopRotationThrusters() {
        leftThrustParticles.Stop();
        rightThrustParticles.Stop();
    }


    void RotateLeft()
    {
        if (!rightThrustParticles.isPlaying)
        {
            rightThrustParticles.Play();

        }

        ApplyRotation(rotationTrhust);
    }

    void RotateRight()
    {
        if (!leftThrustParticles.isPlaying)
        {
            leftThrustParticles.Play();

        }
        ApplyRotation(-rotationTrhust);

    }

    void ApplyRotation(float rotationThisFrame)
    {
        rigidBody.freezeRotation = true; //freezing rotaiotn so taht we can manually rotating.
        transform.Rotate(Vector3.forward * rotationThisFrame * Time.deltaTime);
        rigidBody.freezeRotation = false;
    }

}
