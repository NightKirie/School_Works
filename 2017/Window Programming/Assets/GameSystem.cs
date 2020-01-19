using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameSystem : MonoBehaviour
{
    public Player player1;
    public Player player2;
    public Camera maincamera;
    public GameObject Turnblank;
    public GameObject GameoverUI;
    public GameObject GameP1Win;
    public GameObject GameP2Win;
    public GameObject GameDraw;
    public GameObject Player1GameOverScore;
    public GameObject Player2GameOverScore;
    public GameObject GameUI;
    public MapInformation mapinformation;
    public ScoreLabel scoreLabel1;
    public ScoreLabel scoreLabel2;

    

    int whichPlayer = 1;
    int player1Locate = 0;
    int player2Locate = 0;
    int days = 1;
    int[] mapcost = new int[]
    {
        -50,
        50,0,0,120,100,
        50,50,150,0,0,
        70,0,0,60,0,
        0,0,0,30,100,
        0,100,0,0,50
    };
    int[] mapscore = new int[]
    {
        0,
        10,7,5,15,13,
        8,12,20,7,6,
        12,8,9,11,7,
        10,7,9,8,13,
        8,15,6,6,12
    };
    public void Awake()
    {
        player1.transform.position = new Vector3(0, 0, 0);
        player2.transform.position = new Vector3(0, 0, 0);
    }
    public void LetPlayerMove(int diceNumber)
    {
        if (whichPlayer == 1)
        {
            player1.addScore(diceNumber);
            refleshMoney();
            player1Locate = player1Locate + diceNumber;
            if (player1Locate > 25) player1Locate -= 26;
            player1.move(player1Locate, whichPlayer);
            StartCoroutine(showMapInformation(player1, player1Locate));
        }
        else
        {
            player2.addScore(diceNumber);
            refleshMoney();
            player2Locate = player2Locate + diceNumber;
            if (player2Locate > 25) player2Locate -= 26;
            player2.move(player2Locate, whichPlayer);
            StartCoroutine(showMapInformation(player2, player2Locate));
        }
    }

    IEnumerator showMapInformation(Player player, int locate)
    {
        yield return new WaitUntil(() => player.moving == false);
        mapinformation.changeInformation(locate, judgeHaveEnoughMoney(whichPlayer));
    }
    public void changePlayer()
    {
        if (whichPlayer == 1)
        {
            Turnblank.GetComponent<Text>().text = "Day:" + days + "\n歲星的回合";
            maincamera.transform.position = new Vector3(player2.transform.position.x, maincamera.transform.position.y, player2.transform.position.z);
            whichPlayer = 2;
            if (days > 1) player2.addmoney();
            refleshMoney();
        }
        else
        {
            days++;
            if(days > 10)
            {
                GameOver();
                return;
            }
            Turnblank.GetComponent<Text>().text = "Day:" + days +"\n小滿的回合";
            maincamera.transform.position = new Vector3(player1.transform.position.x, maincamera.transform.position.y, player1.transform.position.z);
            whichPlayer = 1;
            if (days > 1) player1.addmoney();
            refleshMoney();
        }
    }
    public bool judgeHaveEnoughMoney(int whichplayer)
    {
        if (whichplayer == 1)
        {
            if (player1.getMoney() < mapcost[player1Locate]) return false;
            else return true;
        }
        else
        {
            if (player2.getMoney() < mapcost[player2Locate]) return false;
            else return true;
        }
    }

    public void buyButtonClick()
    {
        if (whichPlayer == 1)
        {
            player1.addScore(mapscore[player1Locate]);
            player1.buySomething(mapcost[player1Locate]);
            refleshMoney();
        }
        else
        {
            player2.addScore(mapscore[player2Locate]);
            player2.buySomething(mapcost[player2Locate]);
            refleshMoney();
        }
    }

    public void refleshMoney()
    {
        scoreLabel1.setLabel(player1);
        scoreLabel2.setLabel(player2);
    }

    public void GameOver()
    {
        GameUI.SetActive(false);
        Player1GameOverScore.GetComponent<Text>().text = "分數:" + player1.getscore() + "\n金錢:" + player1.getMoney() + "÷10\nーーーーーーー\n總分:" + (player1.getMoney()/10 + player1.getscore());
        Player2GameOverScore.GetComponent<Text>().text = "分數:" + player2.getscore() + "\n金錢:" + player2.getMoney() + "÷10\nーーーーーーー\n總分:" + (player2.getMoney()/10 + player2.getscore());
        GameoverUI.SetActive(true);
        if(player1.getMoney()/10 + player1.getscore() > player2.getMoney()/10 + player2.getscore()){
            //Player1 win
            GameP1Win.SetActive(true);
        }
        else if(player1.getMoney()/10 + player1.getscore() < player2.getMoney()/10 + player2.getscore())
        {
            //Player2 win
            GameP2Win.SetActive(true);
        }
        else
        {
            //draw
            GameDraw.SetActive(true);
        }
    }
}
