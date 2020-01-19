using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class StartBtn : MonoBehaviour {

    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;

    //click start button to start the game
    public void StartGame() 
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }
    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        SceneManager.LoadScene("Game");
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
