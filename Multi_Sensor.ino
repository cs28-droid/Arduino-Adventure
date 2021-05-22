#include <SimpleDHT.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);//lcd(RS,En,D4,D5,D6,D7)   
/*
   Uncomment when using GAS Sensor
*/
//#define GAS_SENSOR      A1
/*
   Uncomment when using LDR Sensor
*/
#define LDR_SENSOR      A1
//ultrasonic sensor(pins:2)
#define ULT_TRIG        A2
#define ULT_ECHO        A3
#define IR_SENSOR       A4//Ir sensor(pins:1)
#define HT_SENSOR       A5//humidity and temperature sensor(pins:1)
//leds(pins:5)
#define HT_LED          8
#define IR_LED          9
#define ULT_LED         10
#define BUZZER          11// for ultrasonic sensor
//#define GAS_LED       12
#define LDR_LED         12
#define PIR_LED         13
// create a dht11 object
SimpleDHT11 dht11(HT_SENSOR);
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  // set sensor pins as inputs
  /*for (int i = PIR_SENSOR; i <= HT_SENSOR; i++)
    pinMode(i, INPUT);
  //set trigger pin as output
  pinMode(ULT_TRIG, OUTPUT);
  // set led pins as output
  for (int i = HT_LED; i <= PIR_LED; i++)
    pinMode(i, OUTPUT);
  // print sensor name on the LCD*/
  lcd.setCursor(0, 0);
  lcd.print("IS=  ");
  lcd.print("US=   ");
  //lcd.print("GS=   ");
  lcd.print("LDR=  ");
  lcd.setCursor(0, 1);
  lcd.print("PS=  ");
  lcd.print("HS=   ,   ");
}
void loop() {
  
  
  ir_Readings();
  
  us_Readings();
  //read values from gas sensor
  //gas_Readings();
  //read values from LDR sensor
  LDR_Readings();
  //read analog values from pir sensor
//  pir_Readings();
  // read temp and humidity from ht sensor
  ht_Readings();
}
void ir_Readings() {
  int x = digitalRead(IR_SENSOR);
  lcd.setCursor(3, 0);
  lcd.print(!x);
  Serial.print("IR=");
  Serial.print(!x);
  Serial.print("\t");
  //IR Sensor input condition for Led to glow
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
  if (distance > 99 || distance < 0)//If distance is negative or greater than 99, then always show distance =0
    distance = 0;
  display_distance(distance);
}
//uncomment when using GAS Sensor
/*void gas_Readings() {
  int x = analogRead(GAS_SENSOR);
  lcd.setCursor(14, 0);
  lcd.print(x);
  Serial.print("GS=");
  Serial.print(x);
  Serial.print("\t");
   //Gas Sensor input condition for Led to glow
  if (x >= 60)
    digitalWrite(9, HIGH);
  else
    digitalWrite(9, LOW);
  }*/
//uncomment when using LDR Sensor
void LDR_Readings() {
  int x = digitalRead(LDR_SENSOR);
  lcd.setCursor(15, 0);
  lcd.print(x);
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
/*void pir_Readings() {
  int x = digitalRead(PIR_SENSOR);
  lcd.setCursor(3, 1);
  lcd.print(x);
  Serial.print("PS=");
  Serial.print(x);
  Serial.print("\t");
  ////PIR Sensor input condition for Led to glow
  if (x == 1) {
    digitalWrite(PIR_LED, HIGH);
  }
  else {
    digitalWrite(PIR_LED, LOW);
  }
}*/
void ht_Readings() {
  byte temperature = 0;
  byte humidity = 0;
  dht11.read(&temperature, &humidity, NULL);// <simpledht> library function to read temperature and humidity
  lcd.setCursor(8, 1);
  lcd.print((int)temperature);
  lcd.print("*");//temperature in degree
  lcd.setCursor(12, 1);
  lcd.print((int)humidity);
  lcd.print("%");
  Serial.print("HT=");
  Serial.print(temperature);
  Serial.print("*C,");
  Serial.print(humidity);
  Serial.print("%");
  Serial.println();
  //Temperature and humidity conditions for Led to glow
  if (temperature > 38 || humidity > 37)
    digitalWrite(HT_LED, HIGH);
  else
    digitalWrite(HT_LED, LOW);
  delay(500);
}
int time_Measurement(int duration)
{
  digitalWrite(ULT_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULT_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULT_TRIG, LOW);
  duration = pulseIn(ULT_ECHO, HIGH);
  return duration;
}
void display_distance(int distance)
{
  lcd.setCursor(8, 0);
  if (distance < 10) {
    lcd.print(0);
  }
  lcd.print(distance);
  Serial.print("US=");
  Serial.print(distance);
  Serial.print("\t");
  //distance condition for Led to glow
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
