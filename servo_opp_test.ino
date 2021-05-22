#include <Servo.h>

Servo myservo1;
Servo myservo2;// create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val  ;    // variable to read the value from the analog pin
int val2 ;
void setup()
{
  myservo1.attach(9);// attaches the servo on pin 9 to the servo object
    myservo2.attach(10);  // attaches the servo on pin 10 to the servo object
}

void loop()
{ val=90;// make it vertical initially
 delay(2000);
  val = analogRead(potpin);// reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo1.write(val);// sets the servo position according to the scaled value
  delay(15);
 val2=90;
  val2 = map(val2, 1023,0,180,0); // Scale it in the opposite direction
  myservo2.write(val2);
    delay(15);
  // waits for the servo to get there
}
