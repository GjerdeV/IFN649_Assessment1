#include "DHT.h"
//#include <SoftwareSerial.h>

// Humidity sensor
#define LEDPIN 11
#define DHTPIN 21      // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

#define rxPin 7 // Teensy pin 7 <--> HC-05 Tx
#define txPin 8 // Teensy pin 8 <--> HC-05 Rx

void setup() { 
// Setup serial for monitor and Setup Serial1 for BlueTooth
Serial.begin(9600); 
Serial1.begin(9600); 
pinMode(LEDPIN, OUTPUT);

// Setup serial for monitor
  Serial.begin(9600); 

  // Setup DHT Sensor
  pinMode(DHTPIN, INPUT);
  dht.begin();

  // Setup Serial1 for BlueTooth
  Serial1.begin(9600); // Default communication rate of the Bluetooth module
}

void loop() {
// Process commands from bluetooth first.
  //if(Serial1.available() > 0){
    String str = Serial1.readString().substring(0); 
    Serial.println(str);

    // Sending commands to turn on or off the LED
    if(str == "LED_ON"){
      digitalWrite(LEDPIN, HIGH);
      Serial.println("LED ON");
    }
    else if(str == "LED_OFF"){
      digitalWrite(LEDPIN, LOW);
      Serial.println("LED OFF");
    }
    
    // Fetching humidity sensor data
        float h = dht.readHumidity();
        float t = dht.readTemperature();
        float f = dht.readTemperature(true);
    
        float hif = dht.computeHeatIndex(f, h);
        float hic = dht.computeHeatIndex(t, h, false);  
    
        Serial.print(F(" Humidity: "));
        Serial.print(h);
        Serial.print(F("%  Temperature: "));
        Serial.print(t);
        Serial.print(F("C "));
        Serial.print(f);
        Serial.print(F("F  Heat index: "));
        Serial.print(hic);
        Serial.print(F("C "));
        Serial.print(hif);
        Serial.println(F("F"));
    
        Serial1.print(F(" Humidity: "));
        Serial1.print(h);
        Serial1.print(F("%  Temperature: "));
        Serial1.print(t);
        Serial1.print(F("C "));
        Serial1.print(f);
        Serial1.print(F("F  Heat index: "));
        Serial1.print(hic);
        Serial1.print(F("C "));
        Serial1.print(hif);
        Serial1.println(F("F"));
        
        delay(2000);
    
      }
