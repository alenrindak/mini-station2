#define Sensor1 2
#include <Wire.h>
#include <BH1750.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define POMPA_AIR A5
#define SENSOR A0
#include <DHT.h> 
#define DHTPIN 2 
#define DHTTYPE DHT11
#define LED 2
#define BUZZER 3
#define SENSOR A5
DHT dht(DHTPIN, DHTTYPE);

float humi, temp; 


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
  Serial.begin(9600);
  delay(10);
  pinMode (LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode (SENSOR, INPUT);
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

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
   humi = dht.readHumidity();//baca kelembaban
  temp = dht.readTemperature(); //baca suhu
  if (isnan(humi) || isnan(temp)) {//jika tidak ada hasil
    Serial.println("DHT11 tidak terbaca!!");
    return;
    }
  else{//jika ada hasilnya
    Serial.print("Suhu="); //kirim serial "suhu"
    Serial.print(temp);    //kirim serial nilai suhu
    Serial.println("C");  //kirim serial "C" Celcius
    Serial.print("Humi="); //kirim serial "Humi"
    Serial.print(humi); //kirim serial nilai kelembaban
    Serial.println("%RH"); //kirim serial "%RH"
     if(digitalRead(SENSOR) == HIGH){
  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER,LOW);
  delay(250);
  digitalWrite(LED, HIGH);
  digitalWrite(BUZZER, HIGH);
  delay(250);
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
  delay(250);
  }
  delay(1000); //tunda 1 detik untuk pembacaan selanjutnya
}
    }

 
  
    
 
