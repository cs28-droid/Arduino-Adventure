int buttonPin1 = 8; 

int in1 = 3;
int in2 = 5;
int in3 = 6;
int in4 = 9;
int ena = 10;
int enb = 11;


int buttonStatus1 = 0;

void setup() {
  pinMode(ena, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  pinMode(buttonPin1, INPUT);

}
void loop() {
buttonStatus1 = digitalRead(buttonPin1);

if (buttonStatus1 == LOW) { 
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
}
if (buttonStatus1 == HIGH) { 
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
}
}
