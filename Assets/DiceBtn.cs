using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class DiceBtn : MonoBehaviour {

    public Transform dice;
    public Camera maincamera;
    public Transform button;
    public AudioSource btnFX;
    public AudioClip hoverOnFX;
    public AudioClip clickFX;

    public void CreateDice()
    {
        StartCoroutine(AfterFXEnd());
        AfterFXEnd();
    }

    IEnumerator AfterFXEnd()
    {
        yield return new WaitUntil(() => !btnFX.isPlaying);
        if(button.GetComponent<Button>().interactable == true)
        {
            Transform t = Instantiate(dice);
            t.position = new Vector3(maincamera.transform.position.x, 10, maincamera.transform.position.z);
            t.gameObject.SetActive(true);
        }
        button.GetComponent<Button>().interactable = false;
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
