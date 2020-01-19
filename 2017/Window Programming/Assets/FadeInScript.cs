using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FadeInScript : MonoBehaviour {

    private CanvasGroup fadeGroup;
    private float fadeInDuration = 2;
    private bool gameStarted;
    // Use this for initialization
    void Start()
    {
        fadeGroup = FindObjectOfType<CanvasGroup>();
        fadeGroup.alpha = 1;
    }

    // Update is called once per frame
    void Update()
    {
        if (Time.timeSinceLevelLoad <= fadeInDuration)
        {
            fadeGroup.alpha = 1 - (Time.timeSinceLevelLoad / fadeInDuration);
        }
        else if (!gameStarted)
        {
            fadeGroup.alpha = 0;
            gameStarted = true;
        }

        if (gameStarted)
        {
            fadeGroup.blocksRaycasts = false;
        }
    }
}
