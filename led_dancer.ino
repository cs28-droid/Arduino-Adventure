int soundsensor = 3;
int led = 5;              
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int led6 = 10;

void setup()
{ 
  pinMode (soundsensor, INPUT);
  pinMode (led, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (led4, OUTPUT);
  pinMode (led5, OUTPUT);
  pinMode (led6, OUTPUT);
}

void loop()
{
  int sensorvalue = digitalRead (soundsensor);            //if the sound intensity is higher than threshold which is set by us, 
                                                          //then sensor would return the value as 1
  if (sensorvalue == 1)                                    
  {
    digitalWrite(led, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
  }
  
  else
  {
    digitalWrite(led, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    digitalWrite(led6, LOW);
  }
  
}
