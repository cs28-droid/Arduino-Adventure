int buttonPin1 = 2; 
int buttonPin2 = 3; 
int greenLedPin = 6;
redLedPin = 7; 
int buttonStatus1 = 0;
int buttonStatus2 = 0;

void setup() {
pinMode(motorPin, OUTPUT);
pinMode(greenLedPin, OUTPUT); pinMode(redLedPin, OUTPUT);
pinMode(buttonPin1, INPUT);
pinMode(buttonPin2, INPUT);
}
void loop() {
buttonStatus1 = digitalRead(buttonPin1);
buttonStatus2 = digitalRead(buttonPin2);

if (buttonStatus1 == HIGH && buttonStatus2 == LOW) { 
digitalWrite(greenLedPin, HIGH); 
digitalWrite(redLedPin, LOW); 

if (buttonStatus1 == LOW && buttonStatus2 == HIGH) { 
digitalWrite(motorPin, LOW); 
digitalWrite(greenLedPin, LOW); 
digitalWrite(redLedPin, HIGH); 
}
}
