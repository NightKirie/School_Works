using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class NextTurnBtn : MonoBehaviour {

    public GameObject Dicebutton;
    public GameObject NextturnButton;
    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;

    public void NextTurn()
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }

    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        Dicebutton.SetActive(true);
        Dicebutton.GetComponent<Button>().interactable = true;
        NextturnButton.SetActive(false);
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
