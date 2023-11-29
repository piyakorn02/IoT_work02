#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

DHT dht(D4, DHT11);
LiquidCrystal_I2C lcd(0x27, 16, 2);
float hum, temp;

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 1);
  lcd.print("Hum:      %"); 
  lcd.setCursor(0, 0);
  lcd.print("Temp :    ");  
 
}

void loop() {
  hum = dht.readHumidity();
  temp = dht.readTemperature();

  Serial.print(" C  Hum: ");
  Serial.print(hum);
  Serial.println(" %");
  Serial.print("T: ");
  Serial.print(temp);

  lcd.setCursor(4, 1); 
  lcd.print(hum);
  lcd.setCursor(4, 0);  
  lcd.print(temp);
  lcd.print((char)223); 

  delay(500);
}