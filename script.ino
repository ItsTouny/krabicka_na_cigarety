#include <Servo.h>
#include <LiquidCrystal.h>


Servo servo;
Servo servo2;
int servoPin = 9;
int servoPin2 =11;
int butPin = 2;
int butPin2 = 3;
int butPress =3;
bool isPressed = false;
bool isPressed2 = false;
bool isTurned = false;
unsigned long currentMillis = millis();
unsigned long targetSeconds = currentMillis/1000 + 5;
const int rs = 10, en = 8, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // put your setup code here, to run once:
  servo.attach(servoPin);
  servo2.attach(servoPin2);
  pinMode(butPin,INPUT_PULLUP);
  pinMode(butPin2,INPUT_PULLUP);
  Serial.begin(9600);
  servo.write(179);
  servo2.write(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = digitalRead(butPin);
  currentMillis = millis();
  unsigned long currentSeconds = currentMillis / 1000;
  
  if(reading == LOW && butPress != 0 && isPressed == false && currentSeconds > targetSeconds){
    isPressed = true;
    butPress--;
    currentSeconds = currentMillis / 1000;
    targetSeconds = currentSeconds +5;
    servo.write(90);
    delay(2000);
    servo2.write(60);
    delay(2000);
    servo2.write(0);
    delay(1000);
    servo.write(179);
  }else if(reading == HIGH){
    isPressed = false;
  }
}