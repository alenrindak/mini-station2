#define Sensor1 D3

float t, t1;
float windSpeed;
bool state = true;
bool count = true;
int S1 = 0;

#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6bWoBt_Zt"
#define BLYNK_DEVICE_NAME "BMKG"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <DHT_U.h>

BlynkTimer timer;

char auth[] = "ix8f3Mb21R_-EDmaAru1bUzZuYM8o5Jg";
char ssid[] = "JH3";
char pass[] = "12345678";

float suhu = 0;
float kelembapan = 0;

DHT dht(D6, DHT11);
void myTimerEvent() {
  suhu = dht.readTemperature();
  kelembapan = dht.readHumidity();
  readSensor();

  Blynk.virtualWrite(V0, windSpeed);
  Blynk.virtualWrite(V1, kelembapan);
  Blynk.virtualWrite(V2, suhu);
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Blynk.begin(auth, ssid, pass);
dht.begin();
pinMode(Sensor1, INPUT);
S1 = digitalRead(Sensor1);
timer.setInterval(2000L, myTimerEvent);
}
void readSensor() {
    t1 = millis();
    t  = t1 / 1000;
    windSpeed = (2 * 3.1416 * 0.0001 * 3600) / t;
    
    count = true;
} 
void loop() {
  // put your main code here, to run repeatedly:
  readSensor();
Blynk.run();
timer.run();
Serial.print("suhu:");
Serial.println(suhu);
Serial.print("kelembapan:");
Serial.println(kelembapan);
Serial.print("Kecepatan:");
    Serial.println(windSpeed);
delay(1000);
}
