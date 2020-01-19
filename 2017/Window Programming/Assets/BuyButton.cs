using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
public class BuyButton : MonoBehaviour {
    public GameSystem gameSystem;
	public void buyButtonClick()
    {
        if(transform.GetComponent<Button>().interactable == true) gameSystem.buyButtonClick();
        transform.GetComponent<Button>().interactable = false;
    }
}
