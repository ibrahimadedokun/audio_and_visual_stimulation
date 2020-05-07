//https://www.princetronics.com/supermariothemesong/
#include "pitches.h"

// the setup function runs once when you press reset or power the board
#define PIN_1 9
#define PIN_2 10
#define PIN_3 11
#define PIN_4 12

//https://create.arduino.cc/projecthub/GeneralSpud/passive-buzzer-song-take-on-me-by-a-ha-0f04a8
int melody[] = {
  NOTE_FS5, NOTE_FS5, NOTE_D5, NOTE_B4, NOTE_B4, NOTE_E5, 
  NOTE_E5, NOTE_E5, NOTE_GS5, NOTE_GS5, NOTE_A5, NOTE_B5, 
  NOTE_A5, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_D5, NOTE_FS5, 
  NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5
};

int songLength = sizeof(melody)/sizeof(melody[0]);

int durations[] = {
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8, 
  8, 8, 8, 4, 4, 4, 
  4, 5, 8, 8, 8, 8
};

void setup() {
  pinMode(PIN_1, OUTPUT);
  pinMode(PIN_2, OUTPUT);
  pinMode(PIN_3, OUTPUT);
  pinMode(PIN_4, OUTPUT);
}

void loop() {  
  //tone(PIN_4, 100, 500);
  
  for (int thisNote = 0; thisNote < songLength; thisNote++){
    int duration = 1000/ durations[thisNote];
    tone(PIN_4, melody[thisNote], duration);
    int pause = duration * 1.3;
    delay(pause);
    noTone(8);
  }
  
  digitalWrite(PIN_1, HIGH);  
  digitalWrite(PIN_2, HIGH);
  digitalWrite(PIN_3, HIGH);
  delay(2500); 
  digitalWrite(PIN_1, LOW);  
  digitalWrite(PIN_2, LOW);
  digitalWrite(PIN_3, LOW);
  delay(1000);            
}
