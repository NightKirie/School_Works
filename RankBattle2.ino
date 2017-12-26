#include <WiFiClient.h>
#include <LWiFi.h>
#include <task.h>
#include <math.h>
#include <FreeRTOS.h>


#define SSID "1scream2.4G"
#define PASSWD "2017scream"
#define TCP_IP "192.168.0.50"
//#define TCP_IP_PHONE "192.168.0.31"
#define TCP_PORT 5000   

static bool timetogo = false; //false for waiting for start, true for can remote
WiFiClient wifiClient;
WiFiClient wifiClientPh;
static char buf[64],bufPh[64],buf_send[64],buf_phsend[64];
static char client_ID[] = "NightKirie",Team[] = "DWLT";
static int messageLen,phmessageLen;
static int MyPosX, MyPosY, Dst1PosX = -1, Dst1PosY = -1, Dst2PosX = -1, Dst2PosY = -1, treasure[4][2] = {0}, step = 0;
//Dst1 for first destination(may not be my treasure), Dst2 for my treasure
static char *recv_ID, *recv_buf, *recv_mod, *recv_name;

xTaskHandle xaskPos;

enum MotorPinID {
    L_F = 0,
    L_B,
    R_F,
    R_B,
    NUM_OF_MOTOR_PIN
};
enum UltrasonicPinID {
    U_F = 0,
    U_L,
    U_R,
    NUM_OF_ULTRASONIC_PIN
};

/* Pin assignment */
static const uint8_t usTrigPins[NUM_OF_ULTRASONIC_PIN] = {2, 4, 6};  // F, L, R
static const uint8_t usEchoPins[NUM_OF_ULTRASONIC_PIN] = {3, 5, 7};  // F, L, R
static const uint8_t motorPins[NUM_OF_MOTOR_PIN] = {14, 15, 16, 17};  //  L_F, L_B, R_F, R_B

void setup(){
    int motorpins = 0;
    while(motorpins < NUM_OF_MOTOR_PIN){
        pinMode(motorPins[motorpins],OUTPUT);
        motorpins++;
    }
    int status = WL_IDLE_STATUS;
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
        status =  WiFi.begin(SSID, PASSWD);
        Serial.print("Attempting to connect to SSID: ");
        Serial.println(SSID);
        Serial.println(status);
    }
    
    // Conenct to AP successfully
    while (!wifiClient.connect(TCP_IP, TCP_PORT)){
    //delay(300);
        Serial.print("Attempting to connect to SERVER: ");
        Serial.println(TCP_IP);
    }
    /*while (!wifiClientPh.connect(TCP_IP_PHONE, TCP_PORT)){
        delay(300);
        Serial.print("Attempting to connect to PHONE SERVER: ");
        Serial.println(TCP_IP_PHONE);
    }*/
    reg_ID();
    //delay(1000);
    xTaskCreate(
                    askPos,          /* Task function. */
                    "askPos",        /* String with name of task. */
                    10000,            /* Stack size in words. */
                    NULL,             /* Parameter passed as input of the task */
                    1,                /* Priority of the task. */
                    &xaskPos);            /* Task handle. */
}  
double ultrasonicGetDistance(uint8_t trig, uint8_t echo){
    double duration;
    vTaskSuspend(xaskPos);
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH, 20000L);
    vTaskResume(xaskPos);
    return duration / 29 / 2;
}
void reg_ID(){
    strcpy(buf,"Register|");
    strcat(buf,client_ID);
    wifiClient.write(buf, strlen(buf));
    wifiClient.flush();
}

/*void send_phone(int x,int y){
    sprintf(buf_phsend,"(%d,%d)",x,y);
    wifiClientPh.write(buf_phsend, strlen(buf_phsend));
    wifiClientPh.flush();
}*/

void send_mes(char ID[],char mes[]){
    sprintf(buf,"%s|%s",ID,mes);
    wifiClient.write(buf, strlen(buf));
    wifiClient.flush();
}

void askPos( void * parameter ){
    while(1){
        if ((messageLen = wifiClient.available()) > 0) {
            int i = 0;
            do{
                buf[i++] = wifiClient.read();
            }while(i<64 && buf[i-1]!='\r'); 
            buf[i-1] = '\0';
            recv_ID = strtok(buf,"|");
            //Serial.print(recv_ID);
            //Serial.print(":");
            recv_buf = strtok(NULL,"|");
            //Serial.println(recv_buf);
            if(!strcmp(recv_ID, "Master")){     //From Master
                if(!strcmp(recv_buf, "Start")){     //Start
                    timetogo = true;
                    send_mes("Treasure","");
                }
                else if(!strcmp(recv_buf, "Done")){     //End
                    timetogo = false;
                }
                else{ //Something else
                    recv_mod = strtok(recv_buf,":");
                    if(!strcmp(recv_mod, "Treasure")){  //get treasure position
                        recv_mod = strtok(NULL, ":");
                        sscanf(recv_mod, "(%d, %d)(%d, %d)(%d, %d)(%d, %d)", &treasure[0][0], &treasure[0][1], &treasure[1][0], &treasure[1][1], &treasure[2][0], &treasure[2][1], &treasure[3][0], &treasure[3][1]);
                        if(MyPosX >= 192 && MyPosX <= 256 && MyPosY <=192){
                            Dst1PosX = treasure[0][0];
                            Dst1PosY = treasure[0][1];
                        }
                        else if(MyPosX >= 256 && MyPosY >= 192 && MyPosY <= 256){
                            Dst1PosX = treasure[1][0];
                            Dst1PosY = treasure[1][1];
                        }
                        else if(MyPosX >= 192 && MyPosX <= 256 && MyPosY >= 256){
                            Dst1PosX = treasure[2][0];
                            Dst1PosY = treasure[2][1];
                        }
                        else if(MyPosX <= 192 && MyPosY >= 192 && MyPosY <= 256){
                            Dst1PosX = treasure[3][0];
                            Dst1PosY = treasure[3][1];
                        }
                    }
                    else if(!strcmp(recv_mod, "False")){    //get false
                        recv_mod = strtok(NULL, ":\0");
                        sscanf(recv_mod, "%c", recv_name);
                        char *name = "(";
                        char *dst1posx, *dst1posy;
                        sprintf(dst1posx, "%d", Dst1PosX);
                        sprintf(dst1posy, "%d", Dst1PosY);
                        strcat(name, dst1posx);
                        strcat(name, ", ");
                        strcat(name, dst1posy);
                        strcat(name, ")");
                        send_mes(recv_name, name);
                    }
                    else if(!strcmp(recv_mod, "POS")){
                        recv_mod = strtok(NULL, ":\0");
                        sscanf(recv_mod, "(%d,%d)", &MyPosX, &MyPosY);
                    }
                }
            }
            else{   //get my treasure position
               sscanf(recv_buf, "(%d, %d)", &Dst2PosX, &Dst2PosY); 
               
               //for stop to go to real position
               Dst1PosX = -1;
               Dst1PosY = -1;
            }
            Serial.println(recv_ID);
            Serial.println(recv_buf);
            Serial.println(recv_mod);
            Serial.println(Dst1PosX);
            Serial.println(Dst1PosY);
            //send_phone(MyPosX,MyPosY); 
            send_mes("Position","");
        }
    }
   
    //Serial.println("Ending task 1");
    vTaskDelete( NULL );
   
}
void freeze(int t){
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void forward(int t){
    analogWrite(motorPins[L_F], 150);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 150);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void backward(int t){
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 150);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 150);
    delay(t);
}
void left(int t){
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 150);
    analogWrite(motorPins[R_F], 150);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void right(int t){
    analogWrite(motorPins[L_F], 150);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 150);
    delay(t);
}
void slightly_left(int t){
    analogWrite(motorPins[L_F], 0);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 150);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void slightly_right(int t){
    analogWrite(motorPins[L_F], 150);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 0);
    analogWrite(motorPins[R_B], 0);
    delay(t);
} 
void ultrasonictest(int t, double df, double dl, double dr){
    Serial.print("front: ");
    Serial.println(df);
    Serial.print("left: ");
    Serial.println(dl);
    Serial.print("right: ");
    Serial.println(dr);
    delay(t);
}

//for remote
/*void remoteCommand()
  {
  if(timetogo == true){
// Stop moving
if (bufPh[1] == 'E') {
freeze(0);
}
else{
switch (bufPh[0]) {
case 'F':   // Forward
forward(0);
break;
case 'B':   // Backward
backward(0);
break;
case 'L':   // Turn left
left(0);
break;
case 'R':   // Turn right
right(0);
break;
case 'Z':   // Report ultrasonic distance and color
//    reportUltrasonic();
//reportColorSensor();
break;
}
}
}
else if(timetogo == false){
freeze(0);
}
}*/

void loop(){   
    double df, dl, dr;
    df = ultrasonicGetDistance(usTrigPins[U_F], usEchoPins[U_F]);
    dl = ultrasonicGetDistance(usTrigPins[U_L], usEchoPins[U_L]);
    dr = ultrasonicGetDistance(usTrigPins[U_R], usEchoPins[U_R]);
    //for remote
    /*if ((phmessageLen = wifiClientPh.available()) > 0) {
      bufPh[0] = wifiClientPh.read();
      bufPh[1] = wifiClientPh.read();
      remoteCommand();
      }*/

    //ultrasonic testing
    //ultrasonictest(1000, df, dl, dr);

    //for self-moving
    if(timetogo == true){   //for game start
        if(step == 0 && Dst1PosX != -1){
            
            step = 1;
        }
        else if(step == 1 && Dst2PosX != -1){
            
        }
    }
    else if(timetogo == false){     //for game end
        freeze(0);
    }
} 
