using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TutorialtoMenuBtn : MonoBehaviour {

    public GameObject Menu;
    public GameObject Tutorial;
    public GameObject ParticleSystem;
    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;

    //click on to back from tutorial to menu
    public void BackToMenu()
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }
    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        Menu.SetActive(true);
        Tutorial.SetActive(false);
        ParticleSystem.SetActive(true);
    }

    //mouse hover on sound
    public void HoverOnSound()
    {
        btnFX.PlayOneShot(hoverOnFX);
    }

    //mouse click on sound
    public void ClickSound()
    {
        btnFX.PlayOneShot(clickFX);
    }
}
