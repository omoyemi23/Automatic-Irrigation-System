
//Final year EEE projects
//Omoyemi Adetifa @yemxy005@gmail.com
//Special thanks to all the communities

// include the library code:
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 6, en = 7, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//declaration of variables and parameters
int watersensorPin = A1;
int moisturesensorPin = A0;
int waterLevel;
int soilState;
#define buzer 8
#define greenLed 9
#define yellowLed 10
#define redLed 11
#define farmPump 12
int tankPump = 16;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzer, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(farmPump, OUTPUT);
  pinMode(tankPump, OUTPUT);
  digitalWrite(tankPump, HIGH); //pump switched OFF
  digitalWrite(farmPump, HIGH);
 digitalWrite(greenLed, HIGH);
 digitalWrite(yellowLed, LOW);
 digitalWrite(redLed, LOW);
   
   // set up the LCD's number of columns and rows:
   lcd.clear();
    Serial.println("Automatic Irrigation System");
  lcd.begin(16, 2);
  lcd.print("Automatic Irrig-");
  lcd.setCursor(0,1);
  lcd.print("-ation System.");
  delay(3000);
  lcd.clear();
   Serial.println("Checking status");
  lcd.print("Checking Status");
  lcd.setCursor(0,1);
    lcd.print(".............");
    delay(2000);  
}

void loop() {
  
  // put your main code here, to run repeatedly:
  waterLevel = digitalRead(watersensorPin);
  soilState = analogRead(moisturesensorPin);
   Serial.print("Water Level Reading:");
   Serial.println(waterLevel);
   Serial.print("Moisture Sensor Reading:");
   Serial.println(soilState);
    
  if (waterLevel == HIGH){
      lcd.clear();
      lcd.print("Water Tank Low");
        Serial.println("Water in the tank Low");
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, HIGH);
      digitalWrite(tankPump, LOW); //Tank pump switched ON
      Serial.println("Tank Pump switched ON");
      delay(1000);
      waterLevel = digitalRead(watersensorPin);
      lcd.clear();
      }
     else{
           lcd.clear();
           lcd.print("WTank Level Okay.");
           Serial.println("water in the tank Okay");
           digitalWrite(tankPump, HIGH); //Tank pump switched OFF
           digitalWrite(greenLed, HIGH);
           digitalWrite(yellowLed, LOW);
           Serial.println("Tank Pump switched OFF");
           delay(1000);
          lcd.clear();
      }
 if (soilState <= 170){
       lcd.clear();
        lcd.setCursor(0,1);
       lcd.print("Loggy Soil");
       Serial.println("Loggy Soil");
      digitalWrite(farmPump, HIGH); //farm pump switched OFF
        Serial.println("Farm Pump switched OFF");
       digitalWrite(greenLed, HIGH);
       digitalWrite(redLed, LOW);
      
       delay(1000);
       soilState = analogRead(moisturesensorPin);
       lcd.clear();
    } 
   if ((soilState >= 200)&& (soilState <= 350) ){
       lcd.clear();
        lcd.setCursor(0,1);
       lcd.print("Wet Soil");
       Serial.println("Wet Soil");
        digitalWrite(farmPump, HIGH); //farm pump switched OFF
        Serial.println("Farm Pump switched OFF");
       digitalWrite(greenLed, HIGH);
       digitalWrite(redLed, LOW);
       delay(1000);
      soilState = analogRead(moisturesensorPin);
       lcd.clear();
    } 
  if (soilState > 600){
       lcd.clear();
        lcd.setCursor(0,1);
       lcd.print("No Moisture");
       Serial.println("No Soil moisture, soil dry");
       digitalWrite(farmPump, LOW); //farm pump switched ON
       digitalWrite(greenLed, HIGH);
       digitalWrite(redLed, LOW);
       Serial.println("Farm Pump switched ON");
       delay(1000);
      soilState = analogRead(moisturesensorPin);
       lcd.clear();
    } 
 if ((soilState >= 351)&& (soilState <= 580) ){
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Moist Soil");
      Serial.println("Moist Soil, water moisture okay");
       digitalWrite(greenLed, LOW);
       digitalWrite(redLed, LOW);
      soilState = analogRead(moisturesensorPin);
       
     }
 if ((waterLevel == LOW)&&(soilState <= 300)){
      lcd.clear();
      lcd.print("System  OK");
      Serial.println("System OK ");
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(farmPump, HIGH); // farm irrigation pump switched OFF
      digitalWrite(tankPump, HIGH); //Tank pump switched OFF
      Serial.println("Farm Pump switched OFF");
      Serial.println("Tank Pump switched OFF");
     
      }
  if ((soilState > 600)&&(waterLevel == HIGH)){
       lcd.clear();
       lcd.print("Soil Water LOW");
       Serial.println("Soil Water Low");
       lcd.setCursor(0,1);
       lcd.print("Tank Empty");
       Serial.println("Tank Empty");
       digitalWrite(buzer, HIGH);
       digitalWrite(greenLed, LOW);
       digitalWrite(redLed, HIGH);
      digitalWrite(farmPump, LOW); // farm irrigation pump switched ON
      digitalWrite(tankPump, LOW); //Tank pump switched ON
      Serial.println("Farm Pump switched ON");
      Serial.println("Tank Pump switched ON");
      digitalWrite(yellowLed, LOW);
      delay(1000);
      digitalWrite(buzer, LOW);
    
     waterLevel = digitalRead(watersensorPin);
     soilState = analogRead(moisturesensorPin);
     lcd.clear();
          }
          //end
     waterLevel = digitalRead(watersensorPin);
     soilState = analogRead(moisturesensorPin);
      lcd.clear();
  lcd.print("Automatic Irrig-");
  lcd.setCursor(0,1);
  lcd.print("-ation System.");
}
