/*
 Arduino Spiel
 Autor: Johannes Tümler
 Letzte Änderung: 20.05.2022
 Zweck: Beleg 3 Hilfscode für einen leichteren Einstieg
*/

unsigned char gesamtpunktzahl;
const int red = 13, blue = 12, green = 11;
int eingabezahlen[9999];
bool Anfang = false;
byte i=0;
byte 
bool hard=true;

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
    resetAllPins();
    /*Serial.begin(9600);*/
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
}





void loop()
{
    if(Anfang)
    {
      for (i=1;i>=10;i++)
      if(digitalRead(i)==LOW)
          {}
      }
    else{
    menu();
    }
    
}


  

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

void menu()
{
  blink(&green);blink(&green);
      blink(&red);blink(&red);blink(&red);
    if(digitalRead(2)==LOW)
     { Anfang = true;
      startSignal();
      startSignal();}
    if(digitalRead(3)==LOW)
      {Anfang = true;
      startSignal();
      startSignal();
      hard=true;}
  }
