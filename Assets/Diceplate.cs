﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Diceplate : MonoBehaviour {
    public Camera maincamera;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		transform.position = new Vector3(maincamera.transform.position.x, maincamera.transform.position.y - 20, maincamera.transform.position.z);
    }
}
