
#include <Wire.h>
#include <BH1750.h>


BH1750 sensor; 

void setup() {
Serial.begin (9600);
Wire.begin();
sensor.begin();
}

void loop() {
  unsigned int lux = sensor.readLightLevel();
  
if(lux > 500){
  Serial.println("Cerah ^^");
  Serial.println(lux);
} else if (lux > 250){
  Serial.println("Mendung !");
  Serial.println(lux);
} else if (lux > 150){
  Serial.println("Hujan !");  
  Serial.println(lux);
} 

 
delay(1000);
}
