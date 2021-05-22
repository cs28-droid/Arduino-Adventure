#include <Keyboard.h>

int in1 = 3;
int in2 = 5;
int in3 = 6;
int in4 = 9;
//int ena = 10;
//int enb = 11;

void setup()
{
  Serial.begin(9600);

  //pinMode(ena, OUTPUT);
  //pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);


}


void loop()
{
  motorDirection();
  
}

void motorDirection()
{
  char i;
  i = Serial.read();

//  analogWrite(ena, 255);
//  analogWrite(enb, 255);

  if (i == 'w')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);
  }
  else if (i == 's')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);
  }
  else if (i == 'a')
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(2000);
  }
  else if (i == 'd')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(2000);
  }
  else if (i == 'q')
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    delay(2000);
  }
}
