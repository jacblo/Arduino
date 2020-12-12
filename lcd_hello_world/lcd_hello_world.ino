#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte hi[8] = {
  B10101,
  B10101,
  B10101,
  B11101,
  B10101,
  B10101,
  B10101,
};

int moveYSense = A0;
int moveXSense = A1;
int moveY = 0;  
int moveX = 0;  

void setup() {
  
  lcd.createChar(0, hi);
  lcd.begin(16, 2);  
  lcd.write(byte(0));
  lcd.print(" there");
}

void loop() {
  moveY = analogRead(moveXSense);
  moveX = analogRead(moveYSense);
  lcd.clear();
  lcd.print(String(moveY));
}
