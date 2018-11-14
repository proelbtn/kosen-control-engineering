#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 7, 8, 9, 10);

double val2rad(int val) {
  return (val - 512) / 512. * 150. * (PI / 180.);
}

double rad2ang(double rad) {
  return rad / (PI / 180.);
}

int rad2val(double rad) {    
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  lcd.setCursor(0, 0);
  lcd.print("val : ");
  lcd.setCursor(0, 1);
  lcd.print("ang : ");
}

void printValue(int val, double ang) {
  lcd.setCursor(6, 0);
  lcd.print("      ");
  lcd.setCursor(6, 0);
  lcd.print(val, DEC);
  
  lcd.setCursor(6, 1);
  lcd.print("      ");
  lcd.setCursor(6, 1);
  lcd.print(ang);
}

void loop() {
  int val = analogRead(0);
  
  double rad = val2rad(val);
  double ang = rad2ang(rad);

  printValue(val, ang);

  delay(20);
}
