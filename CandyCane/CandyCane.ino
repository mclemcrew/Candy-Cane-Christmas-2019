#include <SoftwareSerial.h>
#include "pitches.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIXEL_PIN 6    // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 8

SoftwareSerial SerialBt(2, 3);

// Melody (liberated from the toneMelody Arduino example sketch by Tom Igoe).
int melody[] = { 262, 196, 196, 220, 196, 0, 247, 262 };
int noteDurations[] = { 4, 8, 8, 4, 4, 4, 4, 4 };
int speakerPin = 8;
int tempo = 135;
String btString = "";
String readString;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(9600);
  SerialBt.begin(9600);
  pinMode(speakerPin, OUTPUT); 
  strip.begin();
}

void loop()
{
//    DeckTheHalls();
//    solid(1,1000);
//    solid(0,1000);
//    solid(2,1000);
//    rainbowCycle(30);
//    rainbow(30);
//    theaterChase(2,120);
//    while(1);
    while (SerialBt.available()) {
      delay(5);  //small delay to allow input buffer to fill
      char c = SerialBt.read();  //gets one byte from serial buffer
      if (c == ',') {
        break;
      }  //breaks out of capture loop to print readstring
      readString += c;
    } //makes the string readString 
  
    if (readString.length() >0) {
      Serial.print(readString); //prints string to serial port out
        if(readString=="DeckTheHalls\n") {
          tempo = 167;
          DeckTheHalls();
        }
        if(readString=="OComeEmmanual\n") {
          tempo = 140;
          OComeEmmanuel();
        }
        if(readString=="MidnightClear\n") {
          tempo = 110;
          MidnightClear();
        }
        if(readString=="Green/Red\n") {
          solid(1,1000);
        }
        if(readString=="White/Blue\n") {
          solid(0,1000);
        }
        if(readString=="Silver/Gold\n") {
          solid(2,1000);
        }
        if(readString=="Rainbow2\n") {
          rainbowCycle(30);
        }
        if(readString=="Rainbow1\n") {
          rainbow(30);
        }
        if(readString=="Chase1\n") {
          theaterChase(0,120);
        }
        if(readString=="Chase2\n") {
          theaterChase(1,120);
        }
        if(readString=="Chase3\n") {
          theaterChase(2,120);
        }
      readString=""; //clears variable for new input
    }

    if (Serial.available()) {
        SerialBt.write(Serial.read());
    }
}

void spacedNote(int frequencyInHertz, int noteLength)
{
  tone(speakerPin, frequencyInHertz);
  float delayTime = (1000/tempo) * (60/4) * noteLength;
  delay(delayTime - 50);
  noTone(speakerPin);
  delay(50);
}
void note(int frequencyInHertz, int noteLength)  //Code to take care of the note
{
  tone(speakerPin, frequencyInHertz);
  float delayTime = (1000/tempo) * (60/4) * noteLength;
  delay(delayTime);
}        
void rest(int restLength)
{
  noTone(speakerPin);
  float delayTime = (1000/tempo) * (60/4) * restLength;
  delay(delayTime);
}

void DeckTheHalls() {
  // 1
  spacedNote(NOTE_C5,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  // 2
  spacedNote(NOTE_F4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_F4,QUARTERNOTE);
  // 3
  spacedNote(NOTE_G4,EIGHTHNOTE);
  spacedNote(NOTE_A4,EIGHTHNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  spacedNote(NOTE_G4,EIGHTHNOTE);
  spacedNote(NOTE_A4,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_G4,EIGHTHNOTE);
  // 4
  spacedNote(NOTE_F4,QUARTERNOTE);
  spacedNote(NOTE_E4,QUARTERNOTE);
  spacedNote(NOTE_F4,HALFNOTE);
  // 5
  spacedNote(NOTE_C5,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  // 6
  spacedNote(NOTE_F4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_F4,QUARTERNOTE);
  // 7
  spacedNote(NOTE_G4,EIGHTHNOTE);
  spacedNote(NOTE_A4,EIGHTHNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  spacedNote(NOTE_G4,EIGHTHNOTE);
  spacedNote(NOTE_A4,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_G4,EIGHTHNOTE);
  // 8
  spacedNote(NOTE_F4,QUARTERNOTE);
  spacedNote(NOTE_E4,QUARTERNOTE);
  spacedNote(NOTE_F4,HALFNOTE);
  // 9
  spacedNote(NOTE_G4,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_A4,EIGHTHNOTE);
  spacedNote(NOTE_AS4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  // 10
  spacedNote(NOTE_A4,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  spacedNote(NOTE_C5,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  // 11
  spacedNote(NOTE_A4,EIGHTHNOTE);
  spacedNote(NOTE_B4,EIGHTHNOTE);
  spacedNote(NOTE_C5,QUARTERNOTE);
  spacedNote(NOTE_D5,EIGHTHNOTE);
  spacedNote(NOTE_E5,EIGHTHNOTE);
  spacedNote(NOTE_F5,QUARTERNOTE);
  // 12
  spacedNote(NOTE_E5,QUARTERNOTE);
  spacedNote(NOTE_D5,QUARTERNOTE);
  spacedNote(NOTE_C5,HALFNOTE);
  // 13
  spacedNote(NOTE_C5,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  // 14
  spacedNote(NOTE_F4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_F4,QUARTERNOTE);
  // 14
  spacedNote(NOTE_D5,EIGHTHNOTE);
  spacedNote(NOTE_D5,EIGHTHNOTE);
  spacedNote(NOTE_D5,EIGHTHNOTE);
  spacedNote(NOTE_D5,EIGHTHNOTE);
  spacedNote(NOTE_C5,DOTTEDQUARTERNOTE);
  spacedNote(NOTE_AS4,EIGHTHNOTE);
  // 15
  spacedNote(NOTE_A4,QUARTERNOTE);
  spacedNote(NOTE_G4,QUARTERNOTE);
  spacedNote(NOTE_F4,HALFNOTE);
  // 
  rest(EIGHTHNOTE);
}


void OComeEmmanuel() {
  // 1
  spacedNote(NOTE_E3,QUARTERNOTE);
  
  // 2
  spacedNote(NOTE_G3,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  
  // 3
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_C4,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_A3,QUARTERNOTE);
  
  // 4
  spacedNote(NOTE_G3,DOTTEDHALFNOTE);
  spacedNote(NOTE_A3,QUARTERNOTE);
  
  // 5
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_G3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  spacedNote(NOTE_G3,QUARTERNOTE);
  
  // 6
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_FS3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  spacedNote(NOTE_D3,QUARTERNOTE);
  
  // 7
  spacedNote(NOTE_E3,DOTTEDHALFNOTE);
  spacedNote(NOTE_A3,QUARTERNOTE);
  
  // 8
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  spacedNote(NOTE_FS3,QUARTERNOTE);
  
  // 9
  spacedNote(NOTE_G3,HALFNOTE);
  spacedNote(NOTE_FS3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  
  // 10
  spacedNote(NOTE_D3,DOTTEDHALFNOTE);
  spacedNote(NOTE_G3,QUARTERNOTE);
  
  // 11
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  
  // 12
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_C4,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_A3,QUARTERNOTE);
  
  // 13
  spacedNote(NOTE_G3,DOTTEDHALFNOTE);
  spacedNote(NOTE_D4,QUARTERNOTE);
  
  // 14
  spacedNote(NOTE_D4,DOTTEDHALFNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  
  // 15
  spacedNote(NOTE_B3,DOTTEDHALFNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  
  // 16
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_C4,QUARTERNOTE);
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_A3,QUARTERNOTE);

  // 17
  spacedNote(NOTE_G3,DOTTEDHALFNOTE);
  spacedNote(NOTE_A3,QUARTERNOTE);

  // 18
  spacedNote(NOTE_B3,QUARTERNOTE);
  spacedNote(NOTE_G3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  spacedNote(NOTE_G3,QUARTERNOTE);

  // 19
  spacedNote(NOTE_A3,QUARTERNOTE);
  spacedNote(NOTE_FS3,QUARTERNOTE);
  spacedNote(NOTE_E3,QUARTERNOTE);
  spacedNote(NOTE_D3,QUARTERNOTE);
  
  // 20
  spacedNote(NOTE_E3,DOTTEDHALFNOTE);

  // END
  rest(EIGHTHNOTE);
}

void MidnightClear() {
  // 1
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 2
  spacedNote(NOTE_D4,QUARTERNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_C4,EIGHTHNOTE);
  spacedNote(NOTE_AS3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  
  // 3
  spacedNote(NOTE_F3,QUARTERNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_F3,QUARTERNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 4
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_AS3,EIGHTHNOTE);
  spacedNote(NOTE_AS3,EIGHTHNOTE);
  spacedNote(NOTE_C4,EIGHTHNOTE);
  spacedNote(NOTE_D4,EIGHTHNOTE);

  // 5
  spacedNote(NOTE_C4,HALFNOTE);
  rest(EIGHTHNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 6
  spacedNote(NOTE_D4,QUARTERNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_C4,EIGHTHNOTE);
  spacedNote(NOTE_AS3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);

  // 7
  spacedNote(NOTE_F3,QUARTERNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_F3,QUARTERNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 8 
  spacedNote(NOTE_G3,QUARTERNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 9
  spacedNote(NOTE_AS3,HALFNOTE);
  rest(EIGHTHNOTE);
  spacedNote(NOTE_D4,EIGHTHNOTE);

  // 10
  spacedNote(NOTE_D4,QUARTERNOTE);
  spacedNote(NOTE_D3,EIGHTHNOTE);
  spacedNote(NOTE_D3,EIGHTHNOTE);
  spacedNote(NOTE_E3,EIGHTHNOTE);
  spacedNote(NOTE_FS3,EIGHTHNOTE);

  // 11
  spacedNote(NOTE_G3,QUARTERNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_AS3,QUARTERNOTE);
  spacedNote(NOTE_D4,EIGHTHNOTE);

  // 12
  spacedNote(NOTE_C4,EIGHTHNOTE);
  spacedNote(NOTE_AS3,EIGHTHNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);

  // 13
  spacedNote(NOTE_F3,HALFNOTE);
  rest(EIGHTHNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 14
  spacedNote(NOTE_D4,QUARTERNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_C4,EIGHTHNOTE);
  spacedNote(NOTE_AS3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);

  // 15
  spacedNote(NOTE_F3,QUARTERNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_F3,QUARTERNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 16 
  spacedNote(NOTE_G3,QUARTERNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_A3,EIGHTHNOTE);
  spacedNote(NOTE_G3,EIGHTHNOTE);
  spacedNote(NOTE_F3,EIGHTHNOTE);

  // 17
  spacedNote(NOTE_AS3,HALFNOTE);
  rest(EIGHTHNOTE);
  
}



// Fill the dots one after the other with a color
void solid(uint8_t color, uint8_t wait) {
  if(color==0) {
    for(uint16_t i=0; i<strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, strip.Color(0, 35, 180));
      delay(wait);
      strip.show();
    }
    for(uint16_t i=1; i<strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, strip.Color(127, 127, 127));
      delay(wait);
      strip.show();
    }
  }
  if(color==1) {
    for(uint16_t i=0; i<strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, strip.Color(127, 0, 0));
      delay(wait);
      strip.show();
    }
    for(uint16_t i=1; i<strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, strip.Color(0, 127, 0));
      delay(wait);
      strip.show();
    }
  }
  if(color==2) {
    for(uint16_t i=0; i<strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, strip.Color(160,120,16));
      delay(wait);
      strip.show();
    }
    for(uint16_t i=1; i<strip.numPixels(); i=i+2) {
      strip.setPixelColor(i, strip.Color(100,100,100));
      delay(wait);
      strip.show();
    }
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;
  while(1){
  readString = "";
  for(j=0; j<256; j++) {
    while (SerialBt.available()) {
      delay(5);  //small delay to allow input buffer to fill
      char c = SerialBt.read();  //gets one byte from serial buffer
      if (c == ',') {
        break;
      }  //breaks out of capture loop to print readstring
      readString += c;
    }
    if(readString!="") {
      return;
    }
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
  while(1){
  readString = "";
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    while (SerialBt.available()) {
      delay(5);  //small delay to allow input buffer to fill
      char c = SerialBt.read();  //gets one byte from serial buffer
      if (c == ',') {
        break;
      }  //breaks out of capture loop to print readstring
      readString += c;
    }
    if(readString!="") {
      return;
    }
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
  }
}

//Theatre-style crawling lights.
void theaterChase(uint8_t color, uint8_t wait) {
  while (1) {  //do 10 cycles of chasing
    readString = "";
    for (int q=0; q < 3; q++) {
      while (SerialBt.available()) {
      delay(5);  //small delay to allow input buffer to fill
      char c = SerialBt.read();  //gets one byte from serial buffer
      if (c == ',') {
        break;
      }  //breaks out of capture loop to print readstring
      readString += c;
      }
      if(readString!="") {
        return;
      }
      if(color==0) {
        int change = 0;
        for(uint16_t i=0; i<strip.numPixels(); i=i+3) {
          if(change==0) {
            strip.setPixelColor(i+q, strip.Color(0, 35, 180));
            change = 1;
          }
          else {
            strip.setPixelColor(i+q, strip.Color(127, 127, 127));
            change = 0;
          }
        }   
      }
      if(color==1) {
        int change = 0;
        for(uint16_t i=0; i<strip.numPixels(); i=i+3) {
          if(change==0) {
            strip.setPixelColor(i+q, strip.Color(127, 0, 0));
            change = 1;
          }
          else {
            strip.setPixelColor(i+q, strip.Color(0, 127, 0));
            change = 0;
          }
        }   
      }
      if(color==2) {
        int change = 0;
        for(uint16_t i=0; i<strip.numPixels(); i=i+3) {
          if(change==0) {
            strip.setPixelColor(i+q, strip.Color(160,120,16));
            change = 1;
          }
          else {
            strip.setPixelColor(i+q, strip.Color(100, 100, 100));
            change = 0;
          }
        }   
      }
      strip.show();
      delay(wait);

      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    } 
  }
}


// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
