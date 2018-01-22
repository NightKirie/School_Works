#include <WiFiClient.h>
#include <LWiFi.h>
#include <task.h>
#include <math.h>
#include <FreeRTOS.h>


#define SSID "2scream"
#define PASSWD "2017scream"
#define TCP_IP "192.168.0.101"
#define TCP_PORT 5000

static bool timetogo = false; //false for waiting for start, true for can remote

//wificlient connect between car and wifiserver
WiFiClient wifiClient;
static char buf[128], buf_send[128];
static char client_ID[] = "NightKirie", Team[] = "A", BaseA = 'C', BaseB = 'C';
static int step = 0, check = 0, hp = 0;
static char *recv_ID, *recv_buf, *recv_mod;
const int index = 2;

enum MotorPinID
{
    L_F = 0,
    L_B,
    R_F,
    R_B,
    NUM_OF_MOTOR_PIN
};

class point
{
    public:
        point(int x = -1, int y = -1){
            this->x = x;
            this->y = y;
        }
        int x, y;
};

//Dst1 for first destination(may not be my treasure)
point DstPos, MyPos, lighthouse[3], MyDir, LastPos;
const point TeamAPos(96, 96), TeamBPos(480, 480);

// Pin assignment
static const uint8_t motorPins[NUM_OF_MOTOR_PIN] = {14, 15, 16, 17};  //  L_F, L_B, R_F, R_B

void reg_ID() {
    strcpy(buf, "Register");
    strcat(buf, Team);
    strcat(buf, "|");
    strcat(buf, client_ID);
    wifiClient.write(buf, strlen(buf));
    wifiClient.flush();
}

void send_mes(char ID[], char mes[]) {
    sprintf(buf, "%s|%s", ID, mes);
    wifiClient.write(buf, strlen(buf));
    wifiClient.flush();
}

void setup() {
    int motorpins = 0;
    int status = WL_IDLE_STATUS;
    while (motorpins < NUM_OF_MOTOR_PIN) {
        pinMode(motorPins[motorpins], OUTPUT);
        motorpins++;
    }
    Serial.begin(115200);
    while (!Serial)
        ;
    // set WiFi
    WiFi.begin(SSID, PASSWD);
    while (status != WL_CONNECTED) {
        // Connect failed, blink 0.5 second to indicate
        // the board is retrying.
        delay(500);
        WiFi.begin(SSID, PASSWD);
        status = WiFi.begin(SSID, PASSWD);
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(SSID);
    }

    // Conenct to AP successfully
    while (!wifiClient.connect(TCP_IP, TCP_PORT)) {
        Serial.print("Attempting to connect to SERVER: ");
        Serial.println(TCP_IP);
    }
    reg_ID();
    xTaskCreate(
            askPos,          /* Task function. */
            "askPos",        /* String with name of task. */
            10000,           /* Stack size in words. */
            NULL,            /* Parameter passed as input of the task */
            1,               /* Priority of the task. */
            NULL);           /* Task handle. */
}


void askPos( void * parameter ) {
    while (1) {
        //read message from server
        if (wifiClient.available())
        {
            for (int i = 0; i < 128 && buf[i-1] != '\r'; i++)
            {
                buf[i] = wifiClient.read();
            }
            recv_ID = strtok(buf, "|");
            recv_buf= strtok(NULL,"|");
            if (!strcmp(recv_ID, "Master")) {   //From Master
                if (!strncmp(recv_buf, "Start",5))
                { //Start
                    timetogo = true;
                    step = 0;
                }
                else if (!strcmp(recv_buf, "Done"))
                { //End
                    timetogo = false;
                }
                else { //Something else
                    recv_mod = strtok(recv_buf, ":");
                    if (!strncmp(recv_mod, "POS", 3)) {
                        recv_mod = strtok(NULL, "\n");
                        //            Serial.println(recv_mod);
                        sscanf(recv_mod, "(%d, %d)BaseA:%cBaseB:%cTowers:(%d, %d)(%d, %d)(%d, %d)Blood:%d", &MyPos.x, &MyPos.y, &BaseA, &BaseB, &lighthouse[0].x, &lighthouse[0].y, &lighthouse[1].x, &lighthouse[1].y, &lighthouse[2].x, &lighthouse[2].y, &hp);
                    }
                    //          Serial.println("========================");
                              Serial.println(lighthouse[0].x);
                              Serial.println(lighthouse[0].y);
                              Serial.println(lighthouse[1].x);
                              Serial.println(lighthouse[1].y);
                              Serial.println(lighthouse[2].x);
                              Serial.println(lighthouse[2].y);
                    //          Serial.println(hp);
                    //          Serial.println("========================");
                    DstPos.x = lighthouse[index].x;
                    DstPos.y = lighthouse[index].y;

                }
            }
            if(timetogo == true){
                send_mes("Position", "");
                if(BaseA == 'O')
                    DstPos = TeamAPos;
                else if(BaseB == 'O')
                    DstPos = TeamBPos;
                else{
                    DstPos = lighthouse[0];
                }
            }
        }
    }
    vTaskDelete(NULL);
}

void freeze(int t) {
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void forward(int t) {
    analogWrite(motorPins[L_F], 255);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 255);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void backward(int t) {
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 255);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 255);
    delay(t);
}
void left(int t) {
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 255);
    analogWrite(motorPins[R_F], 255);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void right(int t) {
    analogWrite(motorPins[L_F], 255);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 255);
    delay(t);
}
void slightly_left(int t) {
    analogWrite(motorPins[L_F], 255);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 255);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void slightly_right(int t) {
    analogWrite(motorPins[L_F], 255);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 150);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}

void loop()
{
    //it can't decide which destination to go
    if(timetogo){
        point LastPos(MyPos.x, MyPos.y);
        forward(100);
        freeze(0);
        double DstDegree = atan2(DstPos.x - MyPos.x, DstPos.y - MyPos.y);
        double MyDegree = atan2(MyPos.x - LastPos.x, MyPos.y - LastPos.y);
        double Degree = MyDegree - DstDegree;
        if(BaseA == 'O' && abs(MyPos.x - TeamAPos.x) < 30 && abs(MyPos.y - TeamAPos.y) < 30)
            freeze(3000);
        else if(BaseB == 'O' && abs(MyPos.x - TeamBPos.x) < 30 && abs(MyPos.y - TeamBPos.y) < 30)
            freeze(3000);
        else if(Degree < -0.05 || Degree > PI + 0.05){
            if(Degree < -PI/2 || Degree > -PI*3/2){
                right(300);
            }
            else{
                slightly_right(75);
            }
        }
        else if(Degree > 0.05){
            if(Degree > PI/2){
                left(300);
            }
            else{
                slightly_left(75);
            }
        }
        else
            freeze(100);
    }
}
