#include <LiquidCrystal.h>
int tempPin = 0;
int inputPin = 3;               // Connect sensor to input pin 3 
//                BS  E  D4 D5  D6 D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
void setup()
{
  /*lcd.begin(cols, rows)
cols = lil fields
rows = layers
  */
  lcd.begin(16, 2);
  pinMode(inputPin, INPUT);     // declare button as input
}
void loop()
{
  int val = digitalRead(inputPin);  // read input value
  int tempReading = analogRead(tempPin);
  int onoff = onoff; // a switch controlled by the button
  
  // catch temp with some formula i found online
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin
  // turns it into a unit of measurement that isnt shit
  float tempC = tempK - 277.15;            // Convert Kelvin to Celcius

    if (val == HIGH && onoff == 0) {   // check if the input is HIGH and display is off
    onoff = 1;}  // turn display on 
    if (val == HIGH && onoff == 1) {   // check if the input is HIGH and display is on
    onoff = 0;}  // turn display off 

  if (onoff == 1) {   // check if the input is HIGH and display is on
      // build Temperature in C text
  lcd.setCursor(0, 0);
  lcd.print("Temp         C  ");
  lcd.setCursor(6, 0);
  // Display Temperature in C
  lcd.print(tempC); 
  delay(200); } // small delay to prevent button fuckery & make text more readable
}
