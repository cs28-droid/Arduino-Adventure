#include <Adafruit_ADXL345_U.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <ESP8266WiFi.h>

const char* ssid = "";
const char* password = "";
const char* host = "maker.ifttt.com";

Adafruit_ADXL345_Unified test_one = Adafruit_ADXL345_Unified();

float a0,b0,c0;

void setup()
{
  
  Serial.begin(115200);

  test_one.begin(); 
  
  sensors_event_t test_two;
  
  test_one.getEvent(&test_two);
  
  a0 = test_two.acceleration.x;
  b0 = test_two.acceleration.y;
  c0 = test_two.acceleration.z;
  
  Serial.print(a0);
  Serial.print(",");
  Serial.print(b0);
  Serial.print(",");
  Serial.print(c0);
   Serial.println("Email from the Node Mcu");
    delay(100);

    Serial.print("Connecting to ");
    Serial.println(ssid);
    
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
  
    Serial.println("");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

}

void loop() 
{
  WiFiClient client; 
           const int httpPort = 80;  
            if (!client.connect(host, httpPort)) {  
                  Serial.println("connection failed");  
            return;}

  float a1;
  float b1;
  float c1;

  sensors_event_t test_three;
  
  test_one.getEvent(&test_three);



  a1 = test_three.acceleration.x;
  b1 = test_three.acceleration.y;
  c1 = test_three.acceleration.z;
 Serial.print("X: "); Serial.print(test_three.acceleration.x); Serial.print("  ");
 Serial.print("Y: "); Serial.print(test_three.acceleration.y); Serial.print("  ");
 Serial.print("Z: "); Serial.print(test_three.acceleration.z); Serial.print("  ");Serial.println("m/s^2 ");
   float d=sqrt((a1*a1 + b1*b1 + c1*c1)/9.8);
  Serial.println(d);
    if (d>9.8)
  {
    Serial.println("Fall Detected");
     String url = "/trigger/oj/with/key/oL9P27Tn_nhEhCTZNlWSaHUtIQLhSbyRm2vgPg7Hm9a"; 

   
                    Serial.print("Requesting URL: ");
                    Serial.println(url);
                 
                       client.print(String("GET ") + url + " HTTP/1.1\r\n" +

               "Host: " + host + "\r\n" +

               "User-Agent: BuildFailureDetectorESP32\r\n" +

               "Connection: close\r\n\r\n");
  }
}
