#include <Servo.h>             //Servo library

#define IR  13
#define PIR 10

//int servo1Pos;
//int servo2Pos;

Servo servo_test;
Servo servo_test1;//initialize a servo object for the connected servo  
                 
 
void setup() 
{ 
  servo_test.attach(7); 
  servo_test1.attach(8); // attach the signal pin of servo to pin9 of arduino

}
void loop() 
{ 
   int x = digitalRead(IR);

   if (x == 1) {
      servo_test.write(90);    
      servo_test1.write(90);   
      delay(20);
  }
   
  else{
      servo_test.write(0);    
      servo_test1.write(0);   
      delay(20);
  }
} 
