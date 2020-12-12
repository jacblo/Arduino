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
int tempertures[] = {0,0,0,0};
String cities[] = {"beit shemmesh","jerusalem","rochester","hollywood fl"};
int counter = 0;
int passiveTimer = 0;

void setup() {
  
  lcd.createChar(0, hi);
  lcd.begin(16, 2);  
  lcd.print("weather");
  /*
  lcd.write(byte(0));
  lcd.print(" there");
  */
}

void loop() {
  moveY = analogRead(moveXSense);
  moveX = analogRead(moveYSense);
  if (passiveTimer == 1000){
    passiveTimer = 0;
    lcd.clear();
    lcd.print("hi");
    delay(1000);
  }
  else{
    passiveTimer ++;
    lcd.clear();
    lcd.print("there");
  }
  /*
  else if(digitalRead(7) == HIGH){
    lcd.clear();
    lcd.print("click");
    delay(1000);
  }
  */
}
