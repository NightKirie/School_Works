using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MapUI : MonoBehaviour {

    public GameObject mapUI;
    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;
    public GameObject Dicebutton;
    public GameObject NextturnButton;

    public void BacktoGame()
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }

    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        mapUI.SetActive(false);
        Dicebutton.SetActive(false);
        NextturnButton.SetActive(true);
        Time.timeScale = 1f;
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
