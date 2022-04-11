#include "DHT.h"
#define DHTPN A0
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);
const int ledRojo = 13;
const int ledVerde = 11;
const int ledAzul = 9;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode (ledRojo, OUTPUT);
  pinMode (ledVerde, OUTPUT);
  pinMode (ledAzul, OUTPUT);

}

void loop() {
  delay(1000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  if (t< 21.00){
    digitalWrite(ledRojo, HIGH);
    delay(500);
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, LOW);
  }
  else if (t>26.00){
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAzul, HIGH);
    delay(500);
    digitalWrite(ledAzul, LOW);
  }else {
    digitalWrite(ledRojo, LOW);
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAzul, LOW);
  }
  if (isnan(h) !! isnan(t) !! isnan (f){
    Serial.println("Falled to read from DHT sensor ");
    return;
  }
  Serial.println(t);
}
