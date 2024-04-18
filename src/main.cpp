#include <Arduino.h>

int buttonPin = 2;
int lightSensorPin = A0;
int buttonState = 0;
int buzzerPin = 3;
int relayPin = 7;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  int value = analogRead(lightSensorPin);
  Serial.println(value);

  // When the lights turn off, begin capturing photos on the Raspberry Pi
  if (value < 200) {
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(relayPin, LOW);
    digitalWrite(buzzerPin, LOW);
  }
  //Serial.println(value);

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(relayPin, HIGH);
    digitalWrite(buzzerPin, HIGH);
  }

  delay(100);
}
