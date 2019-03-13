/*
  CoinButton Taster System R2 ToolDroid
  created 2018
  by Doc Snyder <https://github.com/R2ToolDroid>

  System mit Serial Read Input
*/

// constants won't change. They're used here to
// set pin numbers:

//    A                        B
//  LED 7   A0-14   |  Button 1   |   LED 1    D13-13
//  LED 8   A1-15   |  Button 2   |   LED 2    D12-12
//  LED 9   A2-16   |  Button 3   |   LED 3    D11-11
//  LED 10  A3-17   |  Button 4   |   LED 4    D10-10
//  LED 11  A4-18   |  Button 5   |   LED 5    D9-9
//  LED 12  D8-8    |  Button 6   |   LED 6    A5-19


//Button 5 and 6 are for select Level
//Button 4 is for Excecute the Command
//HOLD BUTTON 5 on Start for Debugsequence

//Arduino Pin Numbers V3 

// TX - 1  
// RX - 0  
// D2 - 2
// D3 - 3
// D4 - 4
// D5 - 5
// D6 - 6
// D7 - 7
// D8 - 8
// D9 - 9
// D10- 10
// D11- 11
// D12- 12
// D13- 13

// A0 - 14
// A1 - 15
// A2 - 16
// A3 - 17
// A4 - 18
// A5 - 19
// A6 - 20 ?
// A7 - 21 ?

int buttonPin[] = {7, 6, 5, 4, 3, 2};     // Button PIN Array
int ledPinA[] =  {14, 15, 16, 17, 18, 8};      // the number of the LED pin
int ledPinB[] =  {13, 12, 11, 10, 9, 19};      // the number of the LED pin

int pinCount = 6; //Raster 6 Tasten
int level = 0;

// this String will come in future from SD Card to make R2 easyer to learn
// this Sting shuld have 17 Commands now
// Here typical Marcduino Commands
// Direkt push Commands:
// BUTTON 1   Reset and mode0 RAND to Dome
// BUTTON 2   mode1 RC to Dome
// BUTTON 3   charge panel open
// BUTTON 4   EXECUTE Sequence
// BUTTON 5   Level +
// BUTTON 6   Level -



String syscmd[] = {
  "CB0",      //0   Close all panels (full speed), servo off - use as init only. Use CL00 for all soft close.
  "CB1",      //1   Scream, with all panels open
  "CB2",      //2   
  "CB3",      //3   
  "CB4",      //4   Wave 2 (open progressively all panels, then close one by one)
  "CB5",      //5   Beep Cantina (with marching ants panel action)
  "CB6",     //6   Faint/Short Circuit
  "CB7",      //7   Cantina dance (orchestral, rhythmic panel dance)
  "CB8",      //8   Leia
  "CB9",      //9   Disco
  "CB10",      //10  Quite Mode reset (panel close, stop holos, stop sounds)
  "CB11",      //11  Full Awake Mode reset (panel close, random sound, holo movement, no holo lights)
  "CB12",      //12  Top Panels to RC
  "CB13",      //13    Mid Awake Mode reset (panel close, random sound, stop holos)
  "CB14",      //14  Awake+ Mode reset ((panel close, random sound, holo movement, lights on)
  "CB15",     //15
  "CB16",       //16
  "CB17"       //17
  

};

// Vars for Serial Input

String cmd; //Consohlen Input

// variables will change:

int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;

int debug = 0; //Debug function

void setup() {
  Serial.begin(9600);

  // set the pin as Input and Output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPinA[thisPin], OUTPUT);
    pinMode(ledPinB[thisPin], OUTPUT);
    pinMode(buttonPin[thisPin], INPUT);
  }
  
  if (digitalRead(buttonPin[5]) == HIGH) {

  Serial.println("SCRIPT: CoinButton 26.10.2018");
  Serial.println("initiate......");
  Serial.println("DebugMode ON");
  Serial.println("...");
  delay(5000);
  debug = 1;
  }
}



void loop() {

  

  // read the state of the pushbutton value:
  buttonState1 = digitalRead(buttonPin[0]);
  buttonState2 = digitalRead(buttonPin[1]);
  buttonState3 = digitalRead(buttonPin[2]);
  buttonState4 = digitalRead(buttonPin[3]);
  buttonState5 = digitalRead(buttonPin[4]);
  buttonState6 = digitalRead(buttonPin[5]);

  //if (level >= 0 ) {
  //    digitalWrite(ledPinA[level], HIGH);
  //   digitalWrite(ledPinB[level], HIGH);
  //   }

  matrix();
  if (debug == 1) {
    Serial.print("LEVEL= ");
    Serial.println(level);
  }

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState1 == HIGH) {

    if (debug == 1) {
    Serial.println("Button-1 - Levelreset");
    }

    Serial.print("CBD1");
    Serial.print("\n");
    delay(1000);
    
    level = 0;
    
      for (int thisPin = 0; thisPin < pinCount; thisPin++) {
        digitalWrite(ledPinA[thisPin], HIGH);
        digitalWrite(ledPinB[thisPin], HIGH);
        
        buttonState2 == LOW;
        buttonState3 == LOW;
        
        
        } 
  }// end button 1
  
      for (int thisPin = 0; thisPin < pinCount; thisPin++) {
           digitalWrite(ledPinA[thisPin], LOW);
          digitalWrite(ledPinB[thisPin], LOW);
        }   // end for
    
    

  if (buttonState2 == HIGH) {
    
    if (debug == 1) {
      Serial.println("Button-2");
    }

    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], HIGH);
      digitalWrite(ledPinB[thisPin], HIGH);
    }
    
    Serial.print ("CBD2");
    Serial.print ("\n");

    delay(1000);

   
    
    buttonState2 == LOW;
    
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], LOW);

      digitalWrite(ledPinB[thisPin], LOW);
      delay(100);
    }
 } 

  if (buttonState3 == HIGH) {
    // turn LED on:

    if (debug == 1) {
      Serial.println("Button-3");
    }

    Serial.print ("CBD3");
    Serial.print ("\n");
    delay(1000);

    
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], LOW);
      digitalWrite(ledPinB[thisPin], LOW);
    }

  } else {
    // turn LED off:

  }

  if (buttonState4 == HIGH) {
    // turn LED on:

    if (debug == 1) {
      Serial.println("Button-4");
    }
   
    ///Hier Befehl ausführen
    if (debug == 1) {
    Serial.print("LEVEL= ");
    Serial.print(level);
    Serial.print (" ...Execute");
    Serial.print("\n");
    }

     Serial.println(syscmd[level]);
     Serial.print("\r");
    
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], HIGH);

      digitalWrite(ledPinB[thisPin], HIGH);
      delay (100);
    }

    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], LOW);

      digitalWrite(ledPinB[thisPin], LOW);
      delay(100);
    }


  } else {
    // turn LED off:

  }


  if (buttonState5 == HIGH) {
    // turn LED on:
    if (debug == 1) {
      Serial.println("Button-5");
    }
    //digitalWrite(ledPinA6 HIGH);

    if (level >= 0 && level <= 17) {
      level--;
    }
    delay(200);


  }


  if (buttonState6 == HIGH) {
    // turn LED on:
    if (debug == 1) {
      Serial.println("Button-6");
    }
    if (level >= -1 && level <= 16) {

      level++;
    }
    delay(200);


  }

   getCMD();
}



void getCMD() {     // Input Comando auswerten
  
  while(Serial.available() > 0  ) {
    
        cmd= Serial.readString();// read the incoming data as string
        Serial.println(cmd); 

        if (cmd)
        {
          level = cmd.toInt();
        }

        
     
    } // End While
  
}

int matrix() {

  switch (level) {
    case 0:
      digitalWrite(ledPinA[level], HIGH);
      digitalWrite(ledPinB[level], HIGH);
      break;
    case 1:
      digitalWrite(ledPinA[level], HIGH);
      digitalWrite(ledPinB[level], HIGH);
      break;

    case 2:
      digitalWrite(ledPinA[level], HIGH);
      digitalWrite(ledPinB[level], HIGH);
      break;
    case 3:
      digitalWrite(ledPinA[level], HIGH);
      digitalWrite(ledPinB[level], HIGH);
      break;
    case 4:
      digitalWrite(ledPinA[level], HIGH);
      digitalWrite(ledPinB[level], HIGH);
      break;

    case 5:
      digitalWrite(ledPinA[level], HIGH);
      digitalWrite(ledPinB[level], HIGH);
      break;

    case 6:
      digitalWrite(ledPinA[0], HIGH);
      break;
    case 7:
      digitalWrite(ledPinB[0], HIGH);
      break;
    case 8:
      digitalWrite(ledPinA[1], HIGH);
      break;
    case 9:
      digitalWrite(ledPinB[1], HIGH);
      break;
    case 10:
      digitalWrite(ledPinA[2], HIGH);
      break;
    case 11:
      digitalWrite(ledPinB[2], HIGH);
      break;
    case 12:
      digitalWrite(ledPinA[3], HIGH);
      break;
    case 13:
      digitalWrite(ledPinB[3], HIGH);
      break;
    case 14:
      digitalWrite(ledPinA[4], HIGH);
      break;
    case 15:
      digitalWrite(ledPinB[4], HIGH);
      break;
    case 16:
      digitalWrite(ledPinA[5], HIGH);
      break;
    case 17:
      digitalWrite(ledPinB[5], HIGH);
      break;

  }


}
