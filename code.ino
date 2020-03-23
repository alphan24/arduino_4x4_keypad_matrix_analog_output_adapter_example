#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Make Your Choice ?");
}

void loop()
{
  lcd.setCursor(0,1);
  lcd.print("You Choose: ");
  lcd.setCursor(13,1);
  if(keyMapper(A0) != '\0'){lcd.print(keyMapper(A0));}
}

char keyMapper(char analogPin  [2] )
{
  char keypad = '\0';
  int analogValue;
  analogValue = analogRead(analogPin);
  delay(10);
  if(analogValue<=1020 && analogValue>=1010) {keypad = '1';}
  else if(analogValue<=920 && analogValue>=900) {keypad = '2';}
  else if (analogValue<=860 && analogValue>=840) {keypad = '3';}
  else if (analogValue<=790 && analogValue>=770) {keypad = 'A';}
  else if(analogValue<=680 && analogValue>=660) {keypad = '4';}
  else if (analogValue<=640 && analogValue>=620) {keypad = '5';}
  else if (analogValue<=600 && analogValue>=590) {keypad = '6';}
  else if (analogValue<=570 && analogValue>=550) {keypad = 'B';}
  else if(analogValue<=510 && analogValue>=490) {keypad = '7';}
  else if (analogValue<=480 && analogValue>=470) {keypad = '8';}
  else if (analogValue<=460 && analogValue>=450) {keypad = '9';}
  else if (analogValue<=440 && analogValue>=430) {keypad = 'C';}
  else if(analogValue<=410 && analogValue>=400) {keypad = '*';}
  else if (analogValue<=390 && analogValue>=380) {keypad = '0';}
  else if (analogValue<=380 && analogValue>=370) {keypad = '#';}
  else if (analogValue<=365 && analogValue>=350) {keypad = 'D';}
  else {keypad = '\0';}
  return keypad;
  }
