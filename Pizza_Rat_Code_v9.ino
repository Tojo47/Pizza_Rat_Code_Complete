#include <LiquidCrystal.h>

LiquidCrystal lcd(24, 26, 10, 11, 12, 13);

const int ButtonGreen = 28; //button 28 is right 
const int ButtonBlack = 30; // button 30 is left

int StateButtonGreen = 0;
int StateButtonBlack = 0;

int STATE = 0;

boolean PressingButtonGreen = false;
boolean PressingButtonBlack = false;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(ButtonGreen, INPUT);
  pinMode(ButtonBlack, INPUT);

  STATE = 0;
}

void loop()
{
  StateButtonGreen = digitalRead(ButtonGreen);
  StateButtonBlack = digitalRead(ButtonBlack);



  if (StateButtonGreen == HIGH) 
  {
    PressingButtonGreen = true;
  }

  if (StateButtonGreen == LOW && PressingButtonGreen == true) 
  {
    PressingButtonGreen = false;
  }

  if (StateButtonBlack == HIGH) 
  {
    PressingButtonBlack = true;
  }

  if (StateButtonBlack == LOW && StateButtonBlack == true)
  {
    StateButtonBlack = false;
  }


  if (STATE == 0)
  {
    Instruction1();
  }


 if (STATE == 1)  // Do you find pizza?
 {

    if (StateButtonGreen == HIGH) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("I Found Pizza!");
      delay(2000);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction2();
      
    }

    else if (StateButtonBlack == HIGH)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Didn't Find!");
      delay(2000);
      lcd.clear();

      lcd.setCursor (0, 0);
      lcd.print ("   Try again  ");
      delay(1500);
      lcd.clear();
      StateButtonBlack = 0;
      STATE = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
    }

    
 }

 if (STATE == 2)   // Do you eat Pizza?
 {
    if (StateButtonGreen == HIGH) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Killed by pigeon");
      delay(3000);
      lcd.clear();

      lcd.setCursor (0, 1);
      lcd.print ("   Try Again   ");
      delay(1500);
      lcd.clear();      
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction2();
    }

    else if (StateButtonBlack == HIGH)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Take it Home");
      delay(3000);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction3();
    }

    
  
 }

 if (STATE == 3)   // Encountering stairs
  {
    if (StateButtonGreen == HIGH) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Stepped by humans");
      delay(3000);
      lcd.clear();

      lcd.setCursor (0, 1);
      lcd.print ("   Try Again  ");
      delay(1500);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction3();
    }

    else if (StateButtonBlack == HIGH)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Throw downstairs");
      delay(2000);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction4();
    }

  }

 if (STATE == 4)   // Arrive near nest hole
  {
    if (StateButtonGreen == HIGH) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print ("Stuck. Eaten");
      lcd.setCursor(0, 1);
      lcd.print ("by Snake");
      delay(3000);
      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print ("   Try Again  ");
      delay(1500);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction4();
    }

    else if (StateButtonBlack == HIGH)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print ("Go around");
      delay(2000);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction5();
    }

  }

 if (STATE == 5)   // Found other way.Now facing Turtle Gang
  {
    if (StateButtonGreen == HIGH) 
    {
      //Serial.print("BG.= Boutton Green has been pressed");
      lcd.clear();
      lcd.setCursor (0, 0);
      lcd.print ("Defeated Turtle");
      lcd.setCursor(0, 1);
      lcd.print ("Ninja");
      delay(2000);
      lcd.clear();
      StateButtonGreen = 0;
      StateButtonGreen = LOW;
      StateButtonBlack = LOW;
      Instruction6();
      
    }

    else if (StateButtonBlack == HIGH)
    {
      lcd.clear();
      lcd.setCursor (0, 1);
      lcd.print (" Lost to Ninja ");
      delay(3000);
      lcd.clear();

      lcd.setCursor (0, 1);
      lcd.print ("   Try Again  ");
      delay(1500);
      lcd.clear();
      StateButtonBlack = 0;
      Instruction5();
    }
    
  }
  
}



void Instruction1() 
{
  lcd.setCursor(2, 0);
  lcd.print ("Find pizza ");
  delay(4000);
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  //lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 1;

}

void Instruction2() 
{
  lcd.setCursor(0, 0);
  lcd.print ("Want to eat it ?");
  delay(3000);
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  //lcd.clear();
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 2;

}

void Instruction3() 
{
  lcd.setCursor(0, 0);
  lcd.print ("Now Encountering");
  lcd.setCursor(0, 1);
  lcd.print (" the stairs");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print ("Drag down with");
  lcd.setCursor(0, 1);
  lcd.print ("mouth?:");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 3;

}

void Instruction4()
{
  lcd.setCursor(0, 0);
  lcd.print ("Arrive near ");
  lcd.setCursor(0, 1);
  lcd.print ("Nest Hole");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print ("Too small to ");
  lcd.setCursor(0, 1);
  lcd.print ("fit Pizza");
  delay(3000);
  lcd.clear();  
  
  lcd.setCursor(0, 0);
  lcd.print ("Force it ?");
  lcd.setCursor(0, 1);
  delay(1500);
  lcd.clear();
  
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 4;
}

void Instruction5()
{
  lcd.setCursor(0, 0);
  lcd.print ("Found other");
  lcd.setCursor(0, 1);
  lcd.print ("  Way ");
  delay(3000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print ("Encounter");
  lcd.setCursor(0, 1);
  lcd.print ("  Turtle Ninja ");
  delay(3000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print ("  Fight ?");
  lcd.setCursor(0, 1);
  delay(1500);
  lcd.clear();
  
  lcd.setCursor (0, 1);
  lcd.print ("YES : Press GR.");
  delay(1500);
  lcd.setCursor (0, 1);
  lcd.print ("NO : Press BL.");
  delay(1500);
  lcd.clear();

  STATE = 5;
}






void Instruction6()
{
  lcd.setCursor(0, 0);
  lcd.print ("CONGRATULATION");
  lcd.setCursor(0, 1);
  lcd.print ("  YOU WIN! ");
  delay(3000);
  

}

