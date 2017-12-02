//add the servo libary
#include <Servo.h>

Servo servo1;

int joyY = 1;
int joyX = 2;
int ledPin = 13;

signed short joyValX;
signed short joyValY;

void setup ()
{
  servo1.attach(3);
  Serial.begin(9600);
  servo1.write(0);
  delay(1000);
}

void loop ()
{
  joyValX = analogRead(joyX);
  
  joyValX = map(joyValX, 0, 1023, 0, 180);
  servo1.write(joyValX);

  // used to control the values sent by the joystick on the serial monitor  
  Serial.print("X:\n");
  Serial.println(joyValX);
  Serial.print("\n");

  Serial.print("Y:\n");
  Serial.println(joyValY);
  Serial.print("\n\n");
  delay(15);
}
