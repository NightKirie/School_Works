using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Player : MonoBehaviour
{
    public Camera maincamera;
    public Sprite player1_1, player1_2, player1_Still;
    public Sprite player2_1, player2_2, player2_Still;

    int money;
    int score;
    double[][] player_moveroadx = new double[26][]
    {
        new double[]{ -13.58, -14.38, -17.37, -19.5},             // position 0~1  player1_moveroadx[0] ~ [3]
        new double[]{ -19.03 },                                 // position 1~2  player1_moveroadx[4]
        new double[]{ -10.05, -10.51, -13.43},                 // position 2~3  player1_moveroadx[5] ~ [7]
        new double[]{ -19.41, -20.94 },                          // position 3~4  player1_moveroadx[8] ~ [9]
        new double[]{ -17.62, -18.35 },                          // position 4~5  player1_moveroadx[10] ~ [11]

        new double[]{ -18.88 },                                 // position 5~6  player1_moveroadx[12]
        new double[]{ -15.76 },                                 // position 6~7  player1_moveroadx[13]
        new double[]{ -13.04, -10.12, -8.73, 5.88 },           // position 7~8  player1_moveroadx[14] ~ [17]
        new double[]{ 12.85, 19.09, 13.84 },                     // position 8~9  player1_moveroadx[18] ~ [20]
        new double[]{ 23.6 },                                  // position 9~10  player1_moveroadx[21]

        new double[]{ 29.25, 26.59, 20.68 },                    // position 10~11  player1_moveroadx[22] ~ [24]
        new double[]{ 6.13 },                                   // position 11~12  player1_moveroadx[25]
        new double[]{ 5.6 },                                   // position 12~13  player1_moveroadx[26]
        new double[]{ 5.27 },                                   // position 13~14  player1_moveroadx[27]
        new double[]{ 5.54, 25.8, 29.05, 18.36 },              // position 14~15  player1_moveroadx[28] ~ [31]

        new double[]{ 9.19, 4.61, 4.68, 0.69, 0.62, -5.23 },     // position 15~16  player1_moveroadx[32] ~ [37]
        new double[]{ -13.67 },                                 // position 16~17  player1_moveroadx[38]
        new double[]{ -23.77, -23.24},                          // position 17~18  player1_moveroadx[39] ~ [40]
        new double[]{ -29.02, -29.42 },                           // position 18~19  player1_moveroadx[41] ~ [42]
        new double[]{ -18.66 },                                  // position 19~20  player1_moveroadx[43]

        new double[]{ -14.01 },                                 // position 20~21  player1_moveroadx[44]
        new double[]{ -11.55, -11.95, -23.24 },                 // position 21~22  player1_moveroadx[45] ~ [47]
        new double[]{ -32.41, -31.74 },                          // position 22~23  player1_moveroadx[48] ~ [49]
        new double[]{ -21.51 },                                 // position 23~24  player1_moveroadx[50]
        new double[]{ -19.12 },                                 // position 24~25  player1_moveroadx[51]

        new double[]{ -4.17, -0.45, 0.01 }                     // position 25~0  player1_moveroadx[52] ~ [54]
    };

    double[][] player_moveroadz = new double[26][]
    {
        new double[]{1.06, 3.32, 1.92, 5.64},          // position 0~1  player1_moveroadz[0] ~ [3]
        new double[]{10.29 },                          // position 1~2  player1_moveroadz[4]
        new double[]{13.88, 19.06, 19.26},             // position 2~3  player1_moveroadz[5] ~ [7]
        new double[]{16.07, 20.39 },                   // position 3~4  player1_moveroadz[8] ~ [9]
        new double[]{21.19, 23.25 },                   // position 4~5  player1_moveroadz[10] ~ [11]

        new double[]{25.91 },                          // position 5~6  player1_moveroadz[12]
        new double[]{26.84 },                          // position 6~7  player1_moveroadz[13]
        new double[]{ 27.9, 26.04, 26.9, 23.25 },     // position 7~8  player1_moveroadz[14] ~ [17]
        new double[]{26.77, 25.11, 11.43 },            // position 8~9  player1_moveroadz[18] ~ [20]
        new double[]{7.31 },                          // position 9~10  player1_moveroadz[21]

        new double[]{ 4.99, 0.21, -0.79 },               // position 10~11  player1_moveroadz[22] ~ [24]
        new double[]{-1.32 },                           // position 11~12  player1_moveroadz[25]
        new double[]{-8.83 },                          // position 12~13  player1_moveroadz[26]
        new double[]{-13.41 },                         // position 13~14  player1_moveroadz[27]
        new double[]{ -16.33, -18.52, -20.25, -23.44 }, // position 14~15  player1_moveroadz[28] ~ [31]

        new double[]{ -25.63, -20.65, -16.86, -16.46, -19.65, -21.64 },      // position 15~16  player1_moveroadz[32] ~ [37]
        new double[]{-21.57 },                                             // position 16~17  player1_moveroadz[38]
        new double[]{ -22.04, -24.36},                                      // position 17~18  player1_moveroadz[39] ~ [40]
        new double[]{ -24.29, -16.25 },                                       // position 18~19  player1_moveroadz[41] ~ [42]
        new double[]{-16.58 },                                                // position 19~20  player1_moveroadz[43]

        new double[]{-14.72 },                                             // position 20~21  player1_moveroadz[44]
        new double[]{ -12.4, -9.41, -8.61 },                                 // position 21~22  player1_moveroadz[45] ~ [47]
        new double[]{ -7.88, -4.42 },                                       // position 22~23  player1_moveroadz[48] ~ [49]
        new double[]{-4.69 },                                              // position 23~24  player1_moveroadz[50]
        new double[]{-4.49 },                                              // position 24~25  player1_moveroadz[51]

        new double[]{ -5.95, -2.36, 1.89 }                                    // position 25~0  player1_moveroadz[52] ~ [54]
    };
    public bool moving = false;
    private int player1PrevLoc = 0;
    private int player2PrevLoc = 0;

    public void Awake()
    {
        score = 0;
        money = 100;
    }
    public void move(int locate, int player)
    {
        if (player == 1)
        {
            StartCoroutine(movingAnimation(locate, player1PrevLoc, player));
        }
        else
        {
            StartCoroutine(movingAnimation(locate, player2PrevLoc, player));
        }
    }
    IEnumerator movingAnimation(int locate, int prevLocate, int player)
    {
        moving = true;
        if(player == 1)
            GetComponent<SpriteRenderer>().sprite = player1_1;
        else
            GetComponent<SpriteRenderer>().sprite = player2_1;

        int frame = 0;
        int templocate = locate;
        if (locate < prevLocate)
            templocate = locate + 26;
        for (int startLoc = prevLocate; startLoc < templocate; ++startLoc)
        {
            if (startLoc >= 26) {
                startLoc = 0;
                templocate = locate;
            }
            for (int i = 0; i < player_moveroadx[startLoc].Length; ++i)
            {
                Vector3 targetPos = new Vector3((float)player_moveroadx[startLoc][i], transform.position.y, (float)player_moveroadz[startLoc][i]);
                while (transform.position != targetPos)
                {
                    yield return new WaitForSeconds(0.01f);
                    Vector3 cameraPos = maincamera.transform.position;
                    ++frame;
                    if(player == 1)
                    {
                        if (GetComponent<SpriteRenderer>().sprite == player1_1 && frame % 20 == 10)
                            GetComponent<SpriteRenderer>().sprite = player1_2;
                        else if (GetComponent<SpriteRenderer>().sprite == player1_2 && frame % 20 == 0)
                            GetComponent<SpriteRenderer>().sprite = player1_1;
                    }
                    else
                    {
                        if (GetComponent<SpriteRenderer>().sprite == player2_1 && frame % 20 == 10)
                            GetComponent<SpriteRenderer>().sprite = player2_2;
                        else if (GetComponent<SpriteRenderer>().sprite == player2_2 && frame % 20 == 0)
                            GetComponent<SpriteRenderer>().sprite = player2_1;
                    }
                        
                    transform.position = Vector3.MoveTowards(transform.position, targetPos, 10 * Time.deltaTime);
                    cameraPos = new Vector3(transform.position.x, maincamera.transform.position.y, transform.position.z);
                    cameraPos.x = Mathf.Clamp(cameraPos.x, -45 + cameraPos.y / Mathf.Sqrt(3) * maincamera.aspect, 45 - cameraPos.y / Mathf.Sqrt(3) * maincamera.aspect);
                    cameraPos.y = Mathf.Clamp(cameraPos.y, 15f, 40f);
                    cameraPos.z = Mathf.Clamp(cameraPos.z, -30 + cameraPos.y / Mathf.Sqrt(3), 30 - cameraPos.y / Mathf.Sqrt(3));
                    maincamera.transform.position = cameraPos;
                }
            }
        }
        moving = false;
        if (player == 1)
        {
            player1PrevLoc = locate;
            GetComponent<SpriteRenderer>().sprite = player1_Still;
        }
        else
        {
            player2PrevLoc = locate;
            GetComponent<SpriteRenderer>().sprite = player2_Still;
        }
    }


    public void buySomething(int cost)
    {
        money -= cost;
    }
    public void addmoney()
    {
        money += 15;
    }
    public void addScore(int addscore)
    {
        score += addscore;
    }
    public int getMoney()
    {
        return money;
    }
    public int getscore()
    {
        return score;
    }
}

