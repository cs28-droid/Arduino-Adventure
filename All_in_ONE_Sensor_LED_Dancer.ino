#include <SimpleDHT.h>

#define GAS_SENSOR      A1
#define TRIG            A2
#define ECHO            A3
#define IR_SENSOR       A4
#define HT_SENSOR       A5
#define HT_LED          8
#define IR_LED          9
#define ULT_LED         10
#define BUZZER          11
#define GAS_LED         12
#define POW_LED         13

int soundsensor = 7;
int led[] = {1,2,3,4,5,6}; //defined arrays and list
int numled = 6;

int dGas = 400;


SimpleDHT11 dht11(HT_SENSOR);

void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode (soundsensor, INPUT);
  for(int i=0; i<numled;i++)
      pinMode(led[i],OUTPUT);
 }
void loop() {  

  digitalWrite(POW_LED,HIGH);
  ir_Readings();  
  us_Readings();  
  GAS_Readings(); 
  ht_Readings();

  int sensorvalue = digitalRead (soundsensor);    

    if (sensorvalue == 1)                                    
  {
     for(int i=0;i<numled;i++){
      digitalWrite(led[i],HIGH);
     }
  }
  
  else
  {
     for(int i=0;i<numled;i++){
      digitalWrite(led[i],LOW);
     }
  }
}

void ir_Readings() {
  int x = digitalRead(IR_SENSOR);
  Serial.print("IR=");
  Serial.print(!x);
  Serial.print("\t");

  if (x == 0) {
    digitalWrite(IR_LED, HIGH);
  }
  else {
    digitalWrite(IR_LED, LOW);
  }
}

void us_Readings() {
  long  duration;
  int distance;
  duration = time_Measurement(duration);
  distance = (int)duration * (0.0343) / 2;
  if (distance > 99 || distance < 0)
    distance = 0;
  display_distance(distance);
}

void GAS_Readings() {
  
  int x = analogRead(GAS_SENSOR);
  Serial.print("GS=");
  Serial.print(x);
  Serial.print("\t");
   if (x >= dGas+100 && x < dGas+200){
      digitalWrite(GAS_LED, HIGH);
      //tone(BUZZER, 1000);
   }
   else {
    digitalWrite(GAS_LED, LOW);
    //noTone(BUZZER);
  }
  delay(10);
}

void ht_Readings() {
  
  byte temperature = 0;
  byte humidity = 0;
  dht11.read(&temperature, &humidity, NULL);
  Serial.print("HT=");
  Serial.print(temperature);
  Serial.print("*C,");
  Serial.print(humidity);
  Serial.print("%");
  Serial.println();
  
  if (temperature > 38 || humidity > 37)
    digitalWrite(HT_LED, HIGH);
  else
    digitalWrite(HT_LED, LOW);
  delay(500);
}
int time_Measurement(int duration)
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  return duration;
}
void display_distance(int distance)
{
 
  Serial.print("US=");
  Serial.print(distance);
  Serial.print("cm");
  Serial.print("\t");
  if (1 <= distance && distance <= 10) {
    digitalWrite(ULT_LED, HIGH);
    tone(BUZZER, 2000);
  }
  else {
    digitalWrite(ULT_LED, LOW);
    noTone(BUZZER);
  }
  delay(10);
}
