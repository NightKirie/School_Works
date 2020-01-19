using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class ScoreLabel : MonoBehaviour {

	public void setLabel(Player player)
    {
        transform.GetComponent<Text>().text = "金錢: " + player.getMoney() + "\n分數:" + player.getscore();
    }
}
