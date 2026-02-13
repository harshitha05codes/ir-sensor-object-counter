#include <Wire.h> // Library for I2C Communication 
#include <LiquidCrystal_I2C.h> // Library for LCD  
 int x = 0; //declare variable x as integer 0 
int input = A0; //declare input comment to A0 
int state = 0; // declare the state as 0 
LiquidCrystal_I2C lcd(0x27, 16, 2); 
void setup() {
  lcd.init(); // initiate the LCD   
  lcd.backlight(); //turn on the black light    
  lcd.setCursor(0,0); //set the cursor on the first column and first row    
  lcd.print("  Object =  ");// print the string “ object counter” on first line    
  lcd.setCursor(0, 1);// set the cursor on the first column second line 
  //lcd.print("objects=       ");// print the string “objects=”    
  //lcd.print(x); // print the string ‘X’  
} 
void loop() {
  int counter = digitalRead(A0);//declare counter as digital read A0   
  if (state == 0) //when state is 0  
  { 
    switch (counter) {
      case 1 : state = 1; 
      lcd.setCursor (0, 1); 
      x = x + 1; 
      lcd.print(x-1); 
      break; //declare state as 0    
	    case 0 : state = 0;
      break;//declare state as 0 	  
    } 
  } 
  if (counter == LOW){ //when the counter set to low      
  state = 0; //declare state as 0 
  } 
}
