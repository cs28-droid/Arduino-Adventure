const int trigPin = 9;
const int echoPin = 10;

const int led = 8;
const int led1 = 7;
const int led2 = 6;
const int led3 = 5;
const int led4 = 4;

long duration;
int distance;

void setup() {
  
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(led, OUTPUT);
pinMode(led1, OUTPUT);
pinMode(led2, OUTPUT);
pinMode(led3, OUTPUT);
pinMode(led4, OUTPUT);
Serial.begin(9600); 

digitalWrite(led,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);

}

void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;

if (distance < 10)

{ 
digitalWrite(led,HIGH);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);
}

if (distance >= 10 and distance <11)

{ 
digitalWrite(led1,HIGH);
digitalWrite(led,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);


}
if (distance >= 11 and distance <12)

{ 
digitalWrite(led2,HIGH);
digitalWrite(led,LOW);
digitalWrite(led1,LOW);
digitalWrite(led3,LOW);
digitalWrite(led4,LOW);


}

if (distance >=12 and distance <13)

{ 
digitalWrite(led3,HIGH);
digitalWrite(led,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led4,LOW);

}

if (distance >= 13) {


digitalWrite(led4,HIGH);
digitalWrite(led,LOW);
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);

}


Serial.print("Distance: ");
Serial.println(distance);




}
