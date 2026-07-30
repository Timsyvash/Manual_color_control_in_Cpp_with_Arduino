#include <Arduino.h>

const short red_pin = 9;
const short green_pin = 10;
const short blue_pin = 11;
const short pot_pin = A1;

unsigned long last_time = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  pinMode(pot_pin, INPUT);
}

void loop()
{
  if (millis() - last_time >= 500)
  {
    last_time = millis();

    short pot_val = analogRead(pot_pin);

    short val = map(pot_val, 0, 1023, 0, 255);
    short constrain_val = constrain(val, 0, 255);

    Serial.print("Value potentiometr: ");
    Serial.println(constrain_val);

    analogWrite(red_pin, constrain_val);
    analogWrite(green_pin, constrain_val);
    analogWrite(blue_pin, constrain_val);
  }
}
