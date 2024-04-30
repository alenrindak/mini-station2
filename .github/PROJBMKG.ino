#define Sensor1 2
#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define POMPA_AIR A5
#define SENSOR A0

BH1750 sensor;

float t, t1;
float windSpeed;
float nilaiSensor = 0;
bool state = true;
bool count = true;
int S1 = 0;
void setup() {
  Serial.begin(9600);
  pinMode(Sensor1, INPUT);
  pinMode(POMPA_AIR, OUTPUT);
pinMode(SENSOR, INPUT);

}

void readSensor()
{
  S1 = digitalRead(Sensor1);
  Serial.begin (9600);
    Serial.println(F("Allocation failed"));
    for(;;); //Don't proceed, loop forever
}

void loop() {
  {
   
    
    readSensor();
    if (S1 == 1)
    {
      t1 = millis();
      t = t1 / 1000;
      windSpeed = (2 * 3.1416 * 0.0001 * 3600) / t;
      Serial.print("Kecepatan");
      Serial.print(windSpeed);
      Serial.println("Km/h");
      count = true;
     }
      unsigned int lux = sensor.readLightLevel();
  Serial.println("Lumi metior");

 if(nilaiSensor >= 512 && lux > 500){
   Serial.println("Serenum");
   Serial.println(lux);
 }   else if(nilaiSensor >= 512 && lux > 250){
    Serial.println("Nubilum");
    Serial.println(lux);
 }   else if (nilaiSensor <= 512 && lux > 100){
    Serial.println("Pluvia");
    Serial.println(lux);
    }
  }
} 
 
  
    
 
