/*
 Arduino Spiel
 Autor: Johannes Tümler
 Letzte Änderung: 20.05.2022
 Zweck: Beleg 3 Hilfscode für einen leichteren Einstieg
*/

unsigned char gesamtpunktzahl;
const int red = 13, blue = 12, green = 11;
byte eingabemode = true;
String Zahlen = "";
int eingabezahlen=100;
bool gamestart = true;
bool hard= false;
byte zahlenLong=1;
char eingabespeicher=' ';
bool prufmode=false;
byte i=0;

void setup()

{
    gesamtpunktzahl = 0;
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    pinMode(10, INPUT_PULLUP);	
    pinMode(9, INPUT_PULLUP);
    pinMode(8, INPUT_PULLUP);
    pinMode(7, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(2, INPUT_PULLUP);
    pinMode(1, INPUT_PULLUP);
    pinMode(0, INPUT_PULLUP);
    resetAllPins();
    Serial.begin(9600);
}

void resetAllPins()
{
    // alle Pins auf definierte Werte setzen (sonst wissen wir nicht, welchen Wert sie gerade haben.)
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    digitalWrite(blue, LOW);
	// Alle nachfolgenden Pins werden auf HIGH gesetzt, sodass sie auf ein GND/Masse-Signal reagieren können.
    digitalWrite(1, HIGH);	
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
}

void blink(const int *pin)
{   digitalWrite(*pin, LOW);
    delay(100);
    digitalWrite(*pin, HIGH);
    delay(500);
    digitalWrite(*pin, LOW);
    delay(500);
}





void loop()
{
    
    if(gamestart)
    {
      eingabespeicher=eingabe();
      if(!prufmode)
            {
              digitalWrite(green, HIGH);
              if(Zahlen.length()<zahlenLong && eingabespeicher!='a' && !prufmode)
              {
                Zahlen=eingabespeicher+Zahlen;
                blink(&green);
                if(Zahlen.length()==zahlenLong)
                  prufmode=true;   
              }
              }
      
      
      else 
           { digitalWrite(blue, HIGH);
            if (eingabespeicher!='a' && Zahlen.length()>(i))
              {if (eingabespeicher==Zahlen.charAt(Zahlen.length()-i-1))
                {i++;
                blink(&blue);}
               else
                {startSignal();
                startSignal();
                startSignal();
                gamestart = false;}
              }
            else if (Zahlen.length()==i)
            {
              prufmode=false;
              zahlenLong++;
              i=0;
              startSignal();
              startSignal();
              startSignal();}
              Serial.println(Zahlen.length());
             Serial.println(i); }
}
else
{gamemeun();}
    resetAllPins();
    
}

/*--------------------------------------------------------------*/

  

void startSignal()
{
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    delay(500);
  }


char eingabe()
{ 
  if(digitalRead(0)==LOW)
     {return '0';}
  /*else if(digitalRead(1)==LOW)
     {blink(&green);return '1';}*/
  else if(digitalRead(2)==LOW)
     {return '2';}
  else if(digitalRead(3)==LOW)
     {return '3';}
  else if(digitalRead(4)==LOW)
     {return '4';}
  else if(digitalRead(5)==LOW)
     {return '5';}
  else if(digitalRead(6)==LOW)
     {return '6';}
  else if(digitalRead(7)==LOW)
     {return '7';}
  else if(digitalRead(8)==LOW)
     {return '8';}
  else if(digitalRead(9)==LOW)
     {return '9';}
  else if(digitalRead(10)==LOW)
     {return '0';}
  else return 'a';
  }

void gamemeun(){
   blink(&green);blink(&green);
      blink(&red);blink(&red);blink(&red);
    if(digitalRead(2)==LOW)
     { gamestart = true;
      startSignal();
      startSignal();}
    if(digitalRead(3)==LOW)
      {gamestart = true;
      hard = true;
      startSignal();
      startSignal();}
}
