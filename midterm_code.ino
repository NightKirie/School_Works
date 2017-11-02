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
int step = 0;

double ultrasonicGetDistance(uint8_t trig, uint8_t echo){
    double duration;
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH, 5000000L);
    return duration / 29 / 2;
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
    analogWrite(motorPins[L_F], 120);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 150);
    analogWrite(motorPins[R_B], 0);
    delay(t);
}
void slightly_right(int t){
    analogWrite(motorPins[L_F], 150);
    analogWrite(motorPins[L_B], 0);
    analogWrite(motorPins[R_F], 120);
    analogWrite(motorPins[R_B], 0);
    delay(t);
} 
void ultrasonictest(int t, float df, float dl, float dr){
    Serial.println(df);
    Serial.println(dl);
    Serial.println(dr);
    delay(t);
}

void setup(){ 
    int motorpins = 0;
    while(motorpins < NUM_OF_MOTOR_PIN){
        pinMode(motorPins[motorpins],OUTPUT);
        motorpins++;
    }
    Serial.begin(9600);
    while (!Serial)
        ;
}
void loop(){
    double df, dl, dr;
    df = ultrasonicGetDistance(usTrigPins[U_F], usEchoPins[U_F]);
    dl = ultrasonicGetDistance(usTrigPins[U_L], usEchoPins[U_L]);
    dr = ultrasonicGetDistance(usTrigPins[U_R], usEchoPins[U_R]);
    //ultrasonictest(1000, df, dl, dr);

    if(step == 0){
        step = 1;
        forward(0);
    }
    else if(df < 5 && step == 1){
        if(dl < 20 && dr < 20){
            freeze(100);
            right(700);
            freeze(100);
        }
        else if(dr > 25){
            forward(100);
            freeze(100);
            right(370);
            freeze(100);
            forward(100);
            freeze(100);
        }
        else if(dl > 25){
            forward(100);
            freeze(100);
            left(370);
            freeze(100);
            forward(100);
            freeze(100);
        }
    }
    else if(dr > 25){
        forward(340);
        freeze(100);
        right(370);
        freeze(100);
        forward(300);
        freeze(100);
    }
    else if(dl < 8.5 && dr < 20){
        slightly_right(15);
    }
    else if(dr < 8.5 && dl < 20){
        slightly_left(15);
    }
    else if(dr < 5 || dr > 3000){
        backward(200);
        freeze(50);
        left(50);
    }
    else if(dl < 5 || dl > 3000){
        backward(200);
        freeze(50);
        right(50);
    }
    else{
        forward(0);
    }
}
