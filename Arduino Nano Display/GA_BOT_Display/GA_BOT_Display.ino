//Project by Nikhil Mishra
//For Google Assistant Bot - NickPi

// include the library code:
#include <LiquidCrystal.h>
int Contrast = 45;
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
int analogPin = A0;
int val = 0;
int val2 = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // set up the LCD's number of columns and rows:

  Serial.begin(9600);
  analogWrite(6,Contrast);
  lcd.begin(16, 1);
  lcd.setCursor(0, 1);
  lcd.print("Say Hey Google! :)");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):

  val = analogRead(analogPin);     // read the input pin
  val2 = analogRead(A1);
  float v1 = val * (5.0 / 1023.0);
  float v2 = val2 * (5.0 / 1023.0);
   Serial.println(v1);
  Serial.println(v2);             // debug value

  //v1 is speaking 
  lcd.setCursor(0, 1);

  if (v1 > 3.2 && v1 < 3.8) {
    lcd.setCursor(0, 1);
    lcd.clear();
    lcd.print("I am Listening!");
    lcd.blink();
    delay(2000);
    if (v2 > 2.3 && v2 < 2.8) {
      lcd.setCursor(0, 1);
      lcd.clear();
      lcd.print("I am Talking!");
      lcd.blink();    
      }    
    else {
    lcd.setCursor(0, 1);
    lcd.clear();
    lcd.print("Hello, There!");
    delay(1000);
    lcd.setCursor(0,0);
    lcd.print("Hey Google!! ");
   }
  }

  delay(100);
  //print the number of seconds since reset:
  //lcd.print(millis() / 1000);
}

