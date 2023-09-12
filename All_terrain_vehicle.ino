#define BLYNK_TEMPLATE_ID "TMPLCXRSe4AL"
#define BLYNK_TEMPLATE_NAME "CAR"
#define BLYNK_AUTH_TOKEN "OWdQDs0yUvYvH-TGipwPyPufz2vRrndy"
#include <WiFi.h>
#include <WiFiClient.h>

#include <BlynkSimpleEsp32.h>
char auth[] = "OWdQDs0yUvYvH-TGipwPyPufz2vRrndy";
char ssid[] = "RedmiNote9ProMax";
char pass[] = "Joelg12345@J";


int leftMotorPin1 = 2;
int leftMotorPin2 = 4;
int rightMotorPin1 = 32;
int rightMotorPin2 = 33;
int ena = 12;
int enb = 13;
int mspeed;
void setup() {

  pinMode(leftMotorPin1, OUTPUT);
  pinMode(leftMotorPin2, OUTPUT);
  pinMode(rightMotorPin1, OUTPUT);
  pinMode(rightMotorPin2, OUTPUT);
  pinMode(ena,OUTPUT);
  pinMode(enb,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop() {
    Blynk.run();
 
}
   
   BLYNK_WRITE(V0) {
 int mspeed = param.asInt();
 analogWrite(ena,mspeed);
 analogWrite(enb,mspeed);
   }

   BLYNK_WRITE(V1) {
 int pinValue1 = param.asInt();
  // set motor direction based on value from Blynk app
  if (pinValue1 == 0) {
      digitalWrite(leftMotorPin1, HIGH);
      digitalWrite(leftMotorPin2, LOW);
      digitalWrite(rightMotorPin1, HIGH);
      digitalWrite(rightMotorPin2, LOW);
    } 
    else if  (pinValue1 == 3) {
      digitalWrite(leftMotorPin1, LOW);
      digitalWrite(leftMotorPin2, HIGH);
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, HIGH);
    } 
    else{
      digitalWrite(leftMotorPin1, LOW);
      digitalWrite(leftMotorPin2, LOW);
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, LOW);
    } 
   }

   BLYNK_WRITE(V2) {
    int pinValue1 = param.asInt();
  // set motor direction based on value from Blynk app
    if (pinValue1 == 0) {
      digitalWrite(leftMotorPin1, LOW);
      digitalWrite(leftMotorPin2, HIGH);
      digitalWrite(rightMotorPin1, HIGH);
      digitalWrite(rightMotorPin2, LOW);
    }
    else if (pinValue1 == 3){
      digitalWrite(leftMotorPin1, HIGH);
      digitalWrite(leftMotorPin2, LOW);
      digitalWrite(rightMotorPin1, LOW);
      digitalWrite(rightMotorPin2, HIGH);
    }
    else  {
    digitalWrite(leftMotorPin1, LOW);
    digitalWrite(leftMotorPin2, LOW);
    digitalWrite(rightMotorPin1, LOW);
    digitalWrite(rightMotorPin2, LOW);
  }
}
