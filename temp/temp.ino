/*
 * Helmetech prototype
 * 
 * Turns on led1 if temperature is lower than a value, led2 if it's between two values and led3 if it's over a specific value.
 * Also prints the temperature every 8 seconds.
 * Reads the value of the gas sensor and a led turns on and off repetitively for 
 * 3 seconds with a speed that depends on the air quality. 
 * 
 * Athanasios Bolatoglou 8160087
 * Aggelos Lagounaris 8160056
 * Panagiotis Papalexiou 8160101
 */


#include <LiquidCrystal.h>

float temp;

int LED1 = 13;
int LED2 = 12;
int LED3 = 11;
int LED4 = 10;
int t1=250;
int t2=500;
int sensorValue;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A0);       // read analog input pin 0
  temp = analogRead(A1);              // 1
  temp = temp * 0.48828125;
  Serial.print("TEMPERATURE: ");
  Serial.print(temp);
  Serial.print("*C");
  Serial.println();
  if (temp > 35) {
      digitalWrite(LED3, HIGH);
      delay(3000);
      digitalWrite(LED3, LOW);
  } else if(temp<35 and temp>25){
      digitalWrite(LED2, HIGH);
      delay(3000);
      digitalWrite(LED2, LOW);
  } else {
      digitalWrite(LED1, HIGH);
      delay(3000);
      digitalWrite(LED1, LOW);
  }
  
  Serial.print("AirQua=");
  Serial.print(sensorValue, DEC);               // prints the value read
  Serial.println(" PPM");
  if (sensorValue > 150 and sensorValue < 300) {
    Serial.print("Hazardous gas above average level");
    Serial.println();
  
    digitalWrite(LED4, HIGH);
    delay(t2);
    digitalWrite(LED4, LOW);
    delay(t2);
    digitalWrite(LED4, HIGH);
    delay(t2);
    digitalWrite(LED4, LOW);
    delay(t2);
    digitalWrite(LED4, HIGH);
    delay(t2);
    digitalWrite(LED4, LOW);
    
  } else if(sensorValue >= 300) {
    Serial.print("Hazardous gas high, consider leaving the building or use mask");
    Serial.println();
    
    digitalWrite(LED4, HIGH);
    delay(t1);
    digitalWrite(LED4, LOW);
    delay(t1);
    digitalWrite(LED4, HIGH);
    delay(t1);
    digitalWrite(LED4, LOW);
    delay(t1);
    digitalWrite(LED4, HIGH);
    delay(t1);
    digitalWrite(LED4, LOW);
    delay(t1);
    digitalWrite(LED4, HIGH);
    delay(t1);
    digitalWrite(LED4, LOW);
    delay(t1);
    digitalWrite(LED4, HIGH);
    delay(t1);
    digitalWrite(LED4, LOW);
  }
}
