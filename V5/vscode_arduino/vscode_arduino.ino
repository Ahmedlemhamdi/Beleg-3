/*
 Arduino Spiel
 Autor: Johannes Tümler, Ahmed Lemhamdi
 Letzte Änderung: 16.07.2022
 Zweck: Beleg 3
 Achtung: pin 10 = 0 !!!! wenn 0 ist, Alle Lichter gehen für eine Sekunde aus.
 pin 1 = 1
 pin 2 = 2
 usw.
*/


const int red = 13, blue = 12, green = 11 ;
byte *pt;
byte datenSpeicher[120];
byte i=0,a=0;
byte anzahlZahlen=0;
bool schwer=false;
bool obEingabe=false;
bool Anfang = false;

void setup()

{   pt=datenSpeicher;
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);
    for(i=1;i<=10;i++)
    {pinMode(i, INPUT_PULLUP);}
    
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
    for(i=1;i<=10;i++)
    {digitalWrite(i, HIGH);	}
  
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
    {
          if(!obEingabe) /*Überprüfen, ob eine Nummer eingegeben wurde*/
          { 
                digitalWrite(blue, LOW);   /*Wenn nicht, hellgrün und auf Eingabe warten*/
                digitalWrite(green, HIGH);
              for (i=1;i<=10;i++)
              {
                if(digitalRead(i)==LOW) /*Überprüfen, ob an den Ports 1-10 Eingaben vorhanden sind*/
                  {
                        if(i==10)       /*Wenn der Eingang Pin 10 ist, ist die gespeicherte Nummer 0 und das Licht ist für 1s aus*/
                            {i=0;digitalWrite(green, LOW);delay(1000);}
                        *(datenSpeicher+anzahlZahlen)= i;               /*Speichern die Nummer in Array*/
                        delay(500);
                        while(!i==0)                                    /*Blinkt grün entsprechend dem Eingangspin*/
                        {blink(&green);i--;}
                        anzahlZahlen++;
                        obEingabe=true;                                 /*Ende der Eingabe*/
                        
                  }
              }
              if(obEingabe&&schwer)                /*Überprüfen, ob sich das Spiel im Hardmode befindet*/
               {      
                      i=random(0,10);             /*zufällig 0-9*/
                      *(datenSpeicher+anzahlZahlen) = i;
                      anzahlZahlen++;
                      if(i==0)
                      delay(1000);
                      while(!i==0)              /*Rotes Licht nach Zufallszahl*/
                      {blink(&red);i--;}
                }
              
          }
         else
           { /*Das blaue Licht beginnt sich zu wiederholen*/
              digitalWrite(green, LOW);
              digitalWrite(blue, HIGH);
              for (i=1;i<=10;i++)
                  {if(digitalRead(i)==LOW)              /*Überprüfen, ob die Eingabe mit der im Array gespeicherten Zahl übereinstimmt*/
                      {if(i==10)
                        {i=0;}
                            if(*(datenSpeicher+a)==i) /*Wenn richtig, wiederholen die nächste Zahl*/
                            {
                                blink(&blue);         /*blaues Licht einmal blinken*/
                                a++;
                              }
                            else
                            {
                                  
                                  {startSignal(anzahlZahlen);}    /*Wenn die Erkennung falsch ist, GAMEOVER*/
                                  reset();
                              }
                        
                        }
             
                  }
              if(a==anzahlZahlen)   /*Wenn alle eingegebenen Zahlen überprüft wurden, fahren mit der Eingabe fort*/
              {a=0;obEingabe=false;}
              
            }    
      }
    else{
    menu(); /*Wenn das Spiel nicht startet, wiederholen Sie das Menü*/
    }
    
}


  

void startSignal(byte a) /*Drei Lichter sind gleichzeitig an, Eingabeparameter: wie oft die Lichter an sind*/
{
        while(!a==0)
        {  digitalWrite(red, LOW);
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
        a--;
        }
  }

void menu()   /*Menüfunktion, 3x rotes Licht, 2x grünes Licht, warten auf Eingang von Pin 2 oder 3*/
{
        blink(&green);
        blink(&green);
        blink(&red);
        blink(&red);
        blink(&red);
        if(digitalRead(2)==LOW)
       { 
              Anfang = true;
              startSignal(2);
        }
        if(digitalRead(3)==LOW)
        {
              Anfang = true;        
              schwer=true;
              startSignal(3);  
        }
  }

void reset()       /*Spiel vorbei, alle Einstellungen zurücksetzen*/ 
{
  obEingabe=false;
    schwer=false;
    i=0,a=0;
    Anfang=false;
    anzahlZahlen=0;
    datenSpeicher[120]; 
  }
