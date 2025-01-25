#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char ssid[] = "Your_SSID";      
char pass[] = "Your_PASSWORD";   
char auth[] = "Your_Blynk_Token"; 

#define flameSensorPin A0   
#define buzzerPin 8         
#define ledPin 13           
int threshold = 200;        

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  
  
  Serial.begin(9600);

  
  Blynk.begin(auth, ssid, pass);

  Serial.println("Fire detection system ready...");
}

void loop() {
  Blynk.run();

  int sensorValue = analogRead(flameSensorPin); 
  Serial.print("Flame Sensor Value: ");
  Serial.println(sensorValue);

  if (sensorValue < threshold) { 
    digitalWrite(buzzerPin, HIGH); 
    digitalWrite(ledPin, HIGH);   
    Serial.println("Fire detected! Alerting...");
    
   
    Blynk.notify("Fire Detected! Take Immediate Action!");
    delay(1000); 
  } else {
    digitalWrite(buzzerPin, LOW); 
    digitalWrite(ledPin, LOW);  
  }

  delay(500); 
}