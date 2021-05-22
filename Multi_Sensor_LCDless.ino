#include <SimpleDHT.h>

#define LDR_SENSOR      A1
#define TRIG            A2
#define ECHO            A3
#define IR_SENSOR       A4
#define HT_SENSOR       A5
#define HT_LED          8
#define IR_LED          9
#define LED         10
#define BUZZER          11
#define LDR_LED         12
#define POW_LED         13


SimpleDHT11 dht11(HT_SENSOR);
void setup() {
  Serial.begin(9600);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
 }
void loop() {  

  digitalWrite(POW_LED,HIGH);
  ir_Readings();  
  us_Readings();  
  LDR_Readings(); 
  ht_Readings();
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

void LDR_Readings() {
  int x = digitalRead(LDR_SENSOR);
  Serial.print("LDR=");
  Serial.print(x);
  Serial.print("\t");
  //LDR Sensor input condition for Led to glow
  if (x == 1) {
    digitalWrite(LDR_LED, HIGH);
  }
  else {
    digitalWrite(LDR_LED, LOW);
  }
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
    digitalWrite(LED, HIGH);
    tone(BUZZER, 2000);
  }
  else {
    digitalWrite(LED, LOW);
    noTone(BUZZER);
  }
  delay(10);
}
