#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int moveYSense = A0;
int moveXSense = A1;
int moveY = 0;  
int moveX = 0;  
float temperatures[] = {0,0,0,0};
String cities[] = {"Beit Shemesh","Jerusalem","Rochester","Hollywood FL"};
int counter = 0;
int passiveTimer = 0;
int in = 0;
int in2 = 0;
int in3 = 0;
int in4 = 0;

int decimals[] = {0,0,0,0};



void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);  
  lcd.print("weather");
  lcd.setCursor(0,1);
  lcd.print("IOT");
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
        decimals[0] = Serial.read();
        Serial.println(decimals[0]);
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
        decimals[1] = Serial.read();
        Serial.println(decimals[1]);
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
        decimals[2] = Serial.read();
        Serial.println(decimals[2]);
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


    
    while(true){
      if(Serial.available() != 0){
        decimals[3] = Serial.read();
        Serial.println(decimals[3]);
        break;
      }
      lcd.clear();
      lcd.print("disconnected");
    }

    String tmp1 = String(in) + "." + String(decimals[0]);
    String tmp2 = String(in2) + "." + String(decimals[1]);
    String tmp3 = String(in3) + "." + String(decimals[2]);
    String tmp4 = String(in4) + "." + String(decimals[3]);
    
    temperatures[0] = tmp1.toFloat();
    temperatures[1] = tmp2.toFloat();
    temperatures[2] = tmp3.toFloat();
    temperatures[3] = tmp4.toFloat();
    
    lcd.clear();
    lcd.print(cities[counter]);
    lcd.setCursor(0,1);
    float x = (((temperatures[counter] * 9) / 5)+32);
    lcd.print(String((temperatures[counter]))+" C "+String(x)+" F");
    
  }
  if (passiveTimer == 100000000){
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
    float x = (((temperatures[counter] * 9) / 5)+32);
    lcd.print(String((temperatures[counter]))+" C "+String(x)+" F");
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
    float x = (((temperatures[counter] * 9) / 5)+32);
    lcd.print(String((temperatures[counter]))+" C "+String(x)+" F");
    delay(500);
  }
}
