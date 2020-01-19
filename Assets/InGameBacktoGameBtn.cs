using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class InGameBacktoGameBtn : MonoBehaviour {

    public GameObject InGame;
    public GameObject PauseMenu;
    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;


    //click to back to game
    public void BacktoGame()
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }
    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        InGame.SetActive(true);
        PauseMenu.SetActive(false);
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
