#include <DHT.h>
#include <DHT_U.h>

dht DHT;

#define DHT11_PIN 2     

float hum; 
float temp; 

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int chk = DHT.read11(DHT11_PIN);
    hum = DHT.humidity;
    temp= DHT.temperature;
    Serial.print("Humidity: ");
    Serial.print(hum);
    Serial.print(" %, Temp: ");
    Serial.print(temp);
    Serial.println(" Celsius");
    delay(2000); 
}
