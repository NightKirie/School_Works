using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameScript : MonoBehaviour {

    public GameObject InGame;
    public GameObject PauseMenu;
	
	// Update is called once per frame
	void Update () {
        //press ESC for pause or unpause the game
        if (Input.GetKeyDown(KeyCode.Escape))   
        {
            if (InGame.activeSelf)   //if game is not pause, than pause
            {
                GamePause();
            }
            else                //if game is pause, than unpause
            {
                BacktoGame();
            }
        }
	}

    //for game pause
    public void GamePause() 
    {
        InGame.SetActive(false);
        PauseMenu.SetActive(true);
        Time.timeScale = 0f;
    }

    //for back to game
    public void BacktoGame()   
    {
        InGame.SetActive(true);
        PauseMenu.SetActive(false);
        Time.timeScale = 1f;
    }

}
