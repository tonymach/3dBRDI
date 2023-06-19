using UnityEngine;
using System.Collections;

public class GameManager
{


    public enum LevelType
    {
        Basic, // Initial simple level
        Inverted, // Level with inverted controls
        ColorMatch, // Level where the color of the bird and eggs should match
        RandomEagle // Level where an eagle can appear randomly
    }

    public enum Direction
    {
        Right,
        Left,
        Up,
        Down
    }


    private void ShowSuccessFeedback(GameObject targetObject) //attaches success particles to gameobject
    {
        // Attach the particle system to the target
        if (successParticle != null)
        {
            ParticleSystem particles = targetObject.AddComponent<ParticleSystem>();
            particles.Stop(); // Stop the particle system by default

            var mainModule = particles.main;
            mainModule.duration = 2f;
            particles.GetComponent<Renderer>().material = successParticle.GetComponent<Renderer>().material; // Copy the material from the successParticle
            float sizeMultiplier = 0.2f; // Change this value to adjust the size
            mainModule.startSizeMultiplier = successParticle.GetComponent<ParticleSystem>().main.startSizeMultiplier * sizeMultiplier;

            particles.Play();
        }

        if (successSound != null)
        {
            AudioSource audioSource = targetObject.AddComponent<AudioSource>(); // Add an AudioSource component to the target
            audioSource.clip = successSound;
            audioSource.playOnAwake = false;
            audioSource.spatialBlend = 1f; // Set the AudioSource to 3D sound
            audioSource.Play(); // Play the success sound
        }
    }



    private void updateLevel()
    {
        levelCounter++;
        // If the counter reaches 15, move to the next level and reset the counter
        if (levelCounter >= 5)
        {
            currentLevel++;
            levelCounter = 0;
            // Reset the score when moving to the next level
            if (currentLevel <= 3)
            {
                score = 0;
                levelStartTime = Time.time;
            }
        }

        switch (currentLevel)
        {
            case 1:
                currentLevelType = LevelType.Basic;
                break;
            case 2:
                currentLevelType = LevelType.Inverted;
                break;
            case 3:
                currentLevelType = LevelType.ColorMatch;
                break;
            case 4:
                currentLevelType = LevelType.RandomEagle;
                break;
            case 5:
                currentLevelType = LevelType.Basic;
                break;
        }


    }


}