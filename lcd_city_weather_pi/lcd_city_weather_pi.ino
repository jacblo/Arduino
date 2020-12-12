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
float temperatures[] = {0,0,5,0};
String cities[] = {"Beit Shemmesh","Jerusalem","Rochester","Hollywood fl"};
int counter = 0;
int passiveTimer = 0;
int in = 0;
int in2 = 0;
int in3 = 0;
int in4 = 0;

int dec = 0;
int dec2 = 0;
int dec3 = 0;
int dec4 = 0;


void setup() {
  Serial.begin(9600);
  lcd.createChar(0, hi);
  lcd.begin(16, 2);  
  lcd.print("weather");
  lcd.setCursor(0,1);
  lcd.print("IOT");
  /*
  lcd.write(byte(0));
  lcd.print(" there");
  */
}

void loop() {
  moveY = analogRead(moveXSense);
  moveX = analogRead(moveYSense);
  if (passiveTimer == 1){
    Serial.println("ask");
    while(true){
      if(Serial.available() != 0){
        in = Serial.read();
        Serial.println(in);
        break;
      }
      lcd.clear();
      lcd.print("disconnected");
    }
    
    while(true){
      if(Serial.available() != 0){
        in2 = Serial.read();
        Serial.println(in2);
        break;
      }
      lcd.clear();
      lcd.print("disconnected");
    }

  
    
    while(true){
      if(Serial.available() != 0){
        in3 = Serial.read();
        Serial.println(in3);
        break;
      }
      lcd.clear();
      lcd.print("disconnected");
    }
    
    while(true){
      if(Serial.available() != 0){
        in4 = Serial.read();
        Serial.println(in4);
        break;
      }
      lcd.clear();
      lcd.print("disconnected");
    }
    
    temperatures[0] = in;
    temperatures[1] = in2;
    temperatures[2] = in3;
    temperatures[3] = in4;
    
    lcd.clear();
    lcd.print(cities[counter]);
    lcd.setCursor(0,1);
    int x = ((temperatures[counter] * 9) / 5)+32;
    lcd.print(String(int(temperatures[counter]))+" C "+String(x)+" F");
    
  }
  if (passiveTimer == 100000){
    passiveTimer = 0;
  }
  else{
    passiveTimer ++;
  }
  
  if(moveX > 700){
    if(counter == 0){
      counter = 3;
    }
    else{
      counter -= 1;
    }
    lcd.clear();
    lcd.print(cities[counter]);
    lcd.setCursor(0,1);
    int x = ((temperatures[counter] * 9) / 5)+32;
    lcd.print(String(int(temperatures[counter]))+" C "+String(x)+" F");
    delay(500);
  }
  else if(moveX < 100){
    if(counter == 3){
      counter = 0;
    }
    else{
      counter ++;
    }
    lcd.clear();
    lcd.print(cities[counter]);
    lcd.setCursor(0,1);
    int x = ((temperatures[counter] * 9) / 5)+32;
    lcd.print(String(int(temperatures[counter]))+" C "+String(x)+" F");
    delay(500);
  }
}
