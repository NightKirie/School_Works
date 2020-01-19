using UnityEngine;

public class MainCamera : MonoBehaviour
{

    public float cameraMoveAmount;
    public float cameraZoomAmount;

    Vector3 cameraPos;
    Camera camera;
    private float moveBorder = 10;
    private float screenWidthQuarter = Screen.width / 4;
    private float screenHeightQuarter = Screen.height / 4;
    // Use this for initialization


    // Update is called once per frame
    void Update()
    {
        camera = GetComponent<Camera>();
        cameraPos = transform.position;

        cameraMove();
        cameraZoom();

        cameraPos.x = Mathf.Clamp(cameraPos.x, -45 + cameraPos.y / Mathf.Sqrt(3) * camera.aspect, 45 - cameraPos.y / Mathf.Sqrt(3) * camera.aspect);
        cameraPos.y = Mathf.Clamp(cameraPos.y, 15f, 40f);
        cameraPos.z = Mathf.Clamp(cameraPos.z, -30 + cameraPos.y / Mathf.Sqrt(3), 30 - cameraPos.y / Mathf.Sqrt(3));

        

        transform.position = cameraPos;

    }

    private void cameraMove()
    {
        //going up
        if (Input.GetKey("w") || Input.mousePosition.y > Screen.height - moveBorder)
        {
            cameraPos.z += Time.deltaTime * cameraMoveAmount;
        }

        //going down
        if (Input.GetKey("s") || Input.mousePosition.y < moveBorder)
        {
            cameraPos.z -= Time.deltaTime * cameraMoveAmount;
        }

        //going left
        if (Input.GetKey("a") || Input.mousePosition.x < moveBorder)
        {
            cameraPos.x -= Time.deltaTime * cameraMoveAmount;
        }

        //going right
        if (Input.GetKey("d") || Input.mousePosition.x > Screen.width - moveBorder)
        {
            cameraPos.x += Time.deltaTime * cameraMoveAmount;
        }
    }

    private void cameraZoom()
    {
        cameraPos.y -= Input.GetAxis("Mouse ScrollWheel") * cameraZoomAmount * Time.deltaTime;
    }
}
