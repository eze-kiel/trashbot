//add the servo libary
#include <Servo.h>

Servo servo1;
Servo servo2;

int joyY = 1;
int joyX = 2;
int ledPinGreen = 4;
int ledPinRed = 2;
int initialLed = 7;

signed short joyValX;
signed short joyValY;

void setup ()
{
  servo1.attach(3);
  servo2.attach(6);
  
  pinMode(initialLed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinRed, OUTPUT);

  digitalWrite(initialLed, HIGH);
  servo1.write(0);
  servo2.write(0);
  delay(1000);
  servo1.write(89);
  servo2.write(89);

  delay(800);
  digitalWrite(initialLed, LOW);


}

void loop ()
{
  joyValX = analogRead(joyX);
  joyValY = analogRead(joyY);

  if ((joyValX > 540 || joyValX < 490) || (joyValY > 550 || joyValY < 480))
  {
    digitalWrite(ledPinGreen, HIGH);
    digitalWrite(ledPinRed, LOW);
  }
  else
  {
    digitalWrite(ledPinGreen, LOW);
    digitalWrite(ledPinRed, HIGH);
  }

  joyValX = map(joyValX, 0, 1023, 0, 180);
  servo1.write(joyValX);

  joyValY = map(joyValY, 0, 1023, 0, 180);
  servo2.write(joyValY);

  delay(15);
}
