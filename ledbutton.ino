int LED = 7;
int button = 8;
int d;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(button,INPUT);
  
}

void loop() {
  Serial.begin(9600);
  d = digitalRead(button);
  if(d==0)
  {
    digitalWrite(LED,HIGH);
    Serial.println("LED is ON");
  }
  else
  {
    digitalWrite(LED,LOW);
    Serial.println("LED is OFF");
  }
}
