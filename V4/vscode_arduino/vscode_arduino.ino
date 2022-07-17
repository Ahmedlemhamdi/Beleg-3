/*
 Arduino Spiel
 Autor: Johannes Tümler, Ahmed Lemhamdi
 Letzte Änderung: 16.07.2022
 Zweck: Beleg 3
 Achtung: pin 10 = 0 !!!! wenn 0 ist, Alle Lichter gehen für eine Sekunde aus
 pin 1 = 1
 pin 2 = 2
 usw.
*/


const int red = 13, blue = 12, green = 11 ;
int datenSpeicher[120];
byte i=0,a=0;
byte anzahlZahlen=0;
bool schwer=true;
bool obEingabe=false;
bool Anfang = true;

void setup()

{   
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
    randomSeed(analogRead(0));
    resetAllPins();
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
    delay(250);
    digitalWrite(*pin, HIGH);
    delay(500);
    digitalWrite(*pin, LOW);
    delay(250);
}





void loop()
{
    if(Anfang)
    {if(!obEingabe)
      { digitalWrite(blue, LOW);
        digitalWrite(green, HIGH);
      for (i=1;i<=10;i++)
      {if(digitalRead(i)==LOW)
          {/*Serial.println(i);*/
                if(i==10)
                    {i=0;delay(1000);}
                datenSpeicher[anzahlZahlen]=i;
                delay(500);
                while(!i==0)
                {blink(&green);i--;}
                anzahlZahlen++;
                obEingabe=true;
                
          }
      }
      if(obEingabe&&schwer)
      { i=random(0,10);
        datenSpeicher[anzahlZahlen]=i;anzahlZahlen++;
        if(i==0)
        delay(1000);
        while(!i==0)
        {blink(&red);i--;}
        }
      
      }
      else
      { digitalWrite(green, LOW);
        digitalWrite(blue, HIGH);
        for (i=1;i<=10;i++)
            {if(digitalRead(i)==LOW)
                {
                      if(datenSpeicher[a]==i)
                      {blink(&blue);
                        a++;
                        }
                      else
                      {
                        while(!anzahlZahlen==0)
                        {startSignal();anzahlZahlen--;}
                        reset();
                        }
                  
                  }
       
            }
        if(a==anzahlZahlen)
        {a=0;obEingabe=false;}
        }    
      }
    else{
    menu();
    }
    
}


  

void startSignal()
{
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    delay(250);
    digitalWrite(red, HIGH);
    digitalWrite(blue, HIGH);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    delay(250);
  }

void menu()
{
  blink(&green);
  blink(&green);
      blink(&red);
      blink(&red);
      blink(&red);
    if(digitalRead(2)==LOW)
     { Anfang = true;
      startSignal();
      startSignal();}
    if(digitalRead(3)==LOW)
      {Anfang = true;
      startSignal();
      startSignal();
      startSignal();
      schwer=true;}
  }

void reset()
{
  obEingabe=false;
    schwer=false;
    i=0,a=0;
    Anfang=false;
    anzahlZahlen=0;
    datenSpeicher[120]; 
  }
