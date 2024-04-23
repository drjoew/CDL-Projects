#include <Keypad.h>
// initialize the library with the numbers of the interface pins
//#include <LiquidCrystal.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


const byte ROWS = 4; 
const byte COLS = 4;
const int DURATION=400;
const int BANG_DURATION = 10000;
const int TONE_FREQ = 2000; 

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
int i=0;
int time = DURATION;
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {A0, A1, A2, A3}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  //lcd.begin(16,2);
  //lcd.setCursor(i,1);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(1,0);
  lcd.print("____                ");
}
  
void loop(){
  char customKey = customKeypad.getKey();
  lcd.setCursor(0,0);  //Display position
  lcd.print("           ");
  lcd.setCursor(0,0);
  lcd.print(time/20);
  if ((time %10) ==0){tone(13, TONE_FREQ, 50);}
  else {  delay(50);}
  if (customKey){
    Serial.println(customKey);
    lcd.setCursor(i,1);  //Display position
    lcd.print(customKey);
    i++;
    if (i>3) 
    {
      i=0;
      lcd.setCursor(i,1);
      lcd.print("Wrong!");
      delay(100);
      lcd.setCursor(i,1);
      lcd.print("____             ");
      }
      
  }
  time=time-1;
  
  if (time==-1) 
  {
    lcd.setCursor(0,0);
    lcd.print("Bang!");
    lcd.setCursor(0,1);
    lcd.print("You Failed!"); 
    tone(13, TONE_FREQ,BANG_DURATION);
    delay(BANG_DURATION);
    time=DURATION;
    lcd.setCursor(i,1);
    lcd.print("____                ");
    } //make a long beep sound
}
