using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DiceControl : MonoBehaviour {
    private Rigidbody rd;
    public GameSystem gameSystem;
    bool hasShowNum = false;
    int diceNumber;
	// Use this for initialization
	void Start () {
        //rd.transform.position = new Vector3(camera.transform.position.x, camera.transform.position.y-5, camera.transform.position.z);
        rd = GetComponent<Rigidbody>();
        //rd.AddForce(new Vector3(Random.Range(-100, 100), Random.Range(-100, 100), Random.Range(-100, 100)));
        rd.AddTorque(new Vector3(Random.Range(-2000, 2000), Random.Range(-2000, 2000), Random.Range(-2000, 2000)));
	}
	
	// Update is called once per frame
	void Update () {
        if (rd.IsSleeping() && hasShowNum == false)
        {
            hasShowNum = true;
            //Debug.Log(rd.transform.eulerAngles);
            if (rd.transform.eulerAngles.x < 105 && rd.transform.eulerAngles.x > 75)
            {
                Debug.Log("dice is 1");
                diceNumber = 1;
            }
            else if ((rd.transform.eulerAngles.x < 15 || rd.transform.eulerAngles.x > 345) && rd.transform.eulerAngles.z > 255 && rd.transform.eulerAngles.z < 285)
            {
                Debug.Log("dice is 2");
                diceNumber = 2;
            }
            else if ((rd.transform.eulerAngles.x < 15 || rd.transform.eulerAngles.x > 345) && (rd.transform.eulerAngles.z < 15 || rd.transform.eulerAngles.z > 345))
            {
                Debug.Log("dice is 3");
                diceNumber = 3;
            }
            else if (rd.transform.eulerAngles.z < 205 && rd.transform.eulerAngles.z > 165)
            {
                Debug.Log("dice is 4");
                diceNumber = 4;
            }
            else if ((rd.transform.eulerAngles.x < 15 || rd.transform.eulerAngles.x > 345) && rd.transform.eulerAngles.z < 105 && rd.transform.eulerAngles.z > 75)
            {
                Debug.Log("dice is 5");
                diceNumber = 5;
            }
            else if (rd.transform.eulerAngles.x > 255 && rd.transform.eulerAngles.x < 285)
            {
                Debug.Log("dice is 6");
                diceNumber = 6;
            }
            StartCoroutine("pause");
        }
    }

    IEnumerator pause()
    {
        yield return new WaitForSeconds(1.0f);
        Destroy(rd.transform.gameObject);
        Debug.Log("hello");
        gameSystem.LetPlayerMove(diceNumber);
    }
}
