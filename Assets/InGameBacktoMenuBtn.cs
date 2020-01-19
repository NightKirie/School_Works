using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class InGameBacktoMenuBtn : MonoBehaviour {

    public GameObject InGame;
    public GameObject PauseMenu;
    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;


    //click to back to menu
    public void BacktoMenu()
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }
    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        SceneManager.LoadScene("Menu");
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
