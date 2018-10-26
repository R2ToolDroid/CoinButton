/*
  CoinButton Taster System R2 ToolDroid


  created 2018
  by Doc Snyder <http://www.0j0.org>
*/

// constants won't change. They're used here to
// set pin numbers:


//  LED A1 |  Button 1 |  LED B1
//  LED A2 |  Button 2 |  LED B2
//  LED A3 |  Button 3 |  LED B3
//  LED A4 |  Button 4 |  LED B4
//  LED A5 |  Button 5 |  LED B5
//  LED A6 |  Button 6 |  LED B6


//Button 5 and 6 are for select Level
//Button 4 is for Excecute the Command


const int buttonPin[] = {6, 7, 5, 4, 3, 2};     // Button PIN Array
const int ledPinA[] =  {14, 15, 16, 17, 18, 19};      // the number of the LED pin
const int ledPinB[] =  {13, 12, 11, 10, 9, 8};      // the number of the LED pin

const int pinCount = 6; //Raster 6 Tasten
int level = 0;

// this String will come in future from SD Card to make R2 easyer to learn
// this Sting shuld have 17 Commands now
// Here typical Marcduino Commands

const String syscmd[] = {
  ":SE00",      //0   Close all panels (full speed), servo off - use as init only. Use CL00 for all soft close.
  ":SE01",      //1   Scream, with all panels open
  ":SE02",      //2   Wave, one panel at a time
  ":SE03",      //3   Fast (Smirk) back and forth wave
  ":SE04",      //4   Wave 2 (open progressively all panels, then close one by one)
  ":SE05",      //5   Beep Cantina (with marching ants panel action)
  ":SE06 ",     //6   Faint/Short Circuit
  ":SE07",      //7   Cantina dance (orchestral, rhythmic panel dance)
  ":SE08",      //8   Leia
  ":SE09",      //9   Disco
  ":SE10",      //10  Quite Mode reset (panel close, stop holos, stop sounds)
  ":SE11",      //11  Full Awake Mode reset (panel close, random sound, holo movement, no holo lights)
  ":SE12",     //12  Top Panels to RC
  ":SE13",   //13    Mid Awake Mode reset (panel close, random sound, stop holos)
  ":SE14",     //14  Awake+ Mode reset ((panel close, random sound, holo movement, lights on)
  ":SE15 ",      //15
  "kjhjas",   //16
  "tzuw"     //17
  

};



// variables will change:

int buttonState1 = 0;         // variable for reading the pushbutton status
int buttonState2 = 0;         // variable for reading the pushbutton status
int buttonState3 = 0;
int buttonState4 = 0;
int buttonState5 = 0;
int buttonState6 = 0;

String cmd; //Consohlen Input
byte debug; //Debug function

void setup() {
  Serial.begin(9600);

  // set the pin as Input and Output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPinA[thisPin], OUTPUT);
    pinMode(ledPinB[thisPin], OUTPUT);
    pinMode(buttonPin[thisPin], INPUT);
  }

  Serial.println("SCRIPT: coin-slot-panel-1.2 26.10.2018");
  delay(3000);
  Serial.println("initiate......");
  Serial.println("...fuer DebugMode 1 eingeben...");
  Serial.println("...ende DebugMode 0 eingeben...");
}



void loop() {
  while (Serial.available() > 0) {
    checkdebug(); ///debuging prüfen
  }

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

    //if (debug == 1) {
    Serial.println("Button-1 - Levelreset");
    //}
    level = 0;
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], HIGH);
      digitalWrite(ledPinB[thisPin], HIGH);
    }
  } else {

    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], LOW);
      digitalWrite(ledPinB[thisPin], LOW);
    }
  }

  if (buttonState2 == HIGH) {
    
    if (debug == 1) {
      Serial.println("Button-2");
    }

    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
      digitalWrite(ledPinA[thisPin], HIGH);
      digitalWrite(ledPinB[thisPin], HIGH);
    }

    delay(1000);


  } else {
    // turn LED off:
    
}

  if (buttonState3 == HIGH) {
    // turn LED on:

    if (debug == 1) {
      Serial.println("Button-3");
    }

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


void checkdebug() {

  cmd = "";
  cmd = Serial.read();
  int h = Serial.available();
  for (int i = 0; i < h; i++) {
    cmd += (char)Serial.read();
  }

  if (cmd == "49") {
    Serial.print( cmd + " OK debug on" + "\n" ); //Kommando quittieren
    debug = 1;
  }
  if (cmd == "48") {
    Serial.print( cmd + " OK debug off" + "\n" ); //Kommando quittieren
    debug = 0;
  }
  return;
}
