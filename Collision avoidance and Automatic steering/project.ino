#include <NewPing.h>

#include <NewPing.h>

#include<LiquidCrystal.h>

#include <NewPing.h>

#define TRIGGER_PIN1 12

#define ECHO_PIN1 13

#define TRIGGER_PIN2 10

#define ECHO_PIN2 11

#define MAX_DISTANCE 40

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);

NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);

int hallPin = 28;
int hallState = 1;
int E1 = 44;
int E2 = 45;
int motor1Pin1 = 2; // pin 2 on L293D
int motor1Pin2 = 3;
int motor2Pin1= 9;
int motor2Pin2= 8;
int distance1, distance2, minRange;
LiquidCrystal lcd(7, 6, 22, 23, 24, 25);
 
void setup() {
 Serial.begin (9600);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);  
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    lcd.begin(16,2);
    pinMode(hallPin, INPUT);
}


void loop() {

delay(50);

unsigned int uS1 = sonar1.ping();
unsigned int uS2 = sonar2.ping();


pinMode(ECHO_PIN1,OUTPUT);
pinMode(ECHO_PIN2,OUTPUT);

digitalWrite(ECHO_PIN1,LOW);
digitalWrite(ECHO_PIN2,LOW);

pinMode(ECHO_PIN1,INPUT);
pinMode(ECHO_PIN2,INPUT);



distance1 = uS1 / US_ROUNDTRIP_CM;

distance2 = uS2 / US_ROUNDTRIP_CM;

int hallState= digitalRead(hallPin);

if (distance1  >3 && distance1 < 15 )
{ 
  analogWrite(E1,0); 
 analogWrite(E2, 255);
  digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor1Pin2, HIGH);
   digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor2Pin2, HIGH);
   lcd.setCursor(4,0);
  lcd.print(" OBSTACLE ");
   lcd.setCursor(2,1);
  lcd.print("TO ur RIGHT "); 
 Serial.println("US1="); 
 Serial.print(distance1);
 Serial.println(" cm-----firstone");
Serial.println();
Serial.println();
if (hallState == LOW)
{
  analogWrite(E1,0); 
  analogWrite(E2, 255);
   digitalWrite(motor1Pin1, HIGH); // set pin 2 on L293D low
   digitalWrite(motor1Pin2, HIGH);
   digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor2Pin2, HIGH);
  
}
}
else if 
( distance2  > 3 && distance2 < 15)
{
analogWrite(E2, 80);
analogWrite(E1, 255);
  digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D lo
  digitalWrite(motor2Pin2, HIGH);
digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor1Pin2, HIGH);
   lcd.setCursor(4,0);
  lcd.print(" OBSTACLE ");
   lcd.setCursor(2,1);
  lcd.print("  TO ur LEFT ");
Serial.println("US2=");
 Serial.print(distance2);
 Serial.println(" cm------secondone");
Serial.println();
Serial.println();
 delay(250);
if (hallState == LOW)
{
   digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor1Pin2, HIGH);
   digitalWrite(motor2Pin1, HIGH); // set pin 2 on L293D low
   digitalWrite(motor2Pin2, HIGH);
  
}
}
else 
{
  analogWrite(E1, 255);
  analogWrite(E2, 255);
  digitalWrite(motor2Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor2Pin2, HIGH);
  digitalWrite(motor1Pin1, LOW); // set pin 2 on L293D low
   digitalWrite(motor1Pin2, HIGH);

}
}

