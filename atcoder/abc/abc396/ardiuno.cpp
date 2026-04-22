// Arduino buzzer sketch
// Original melody inspired by the *feeling* of Ocarina of Time
// Pin: buzzer + -> D8, buzzer - -> GND

#include <Arduino.h>
// Arduino buzzer sketch
// Original melody inspired by Zelda/Ocarina-style feeling
// Buzzer + -> pin 8
// Buzzer - -> GND

const int BUZZER_PIN = 8;
const int REST = 0;

// Notes
const int A4_ = 440;
const int B4 = 494;
const int C5 = 523;
const int D5 = 587;
const int E5 = 659;
const int G4 = 392;

// Melody notes
const int notes[] = {
  A4_, C5, D5,
  E5, D5, C5,

  A4_, G4, A4_,
  D5, C5, A4_,

  REST,

  A4_, C5, E5,
  D5, C5, A4_,

  G4, A4_, C5,
  B4, A4_, G4,

  REST
};

// Melody durations in milliseconds
const int times[] = {
  260, 260, 520,
  260, 260, 520,

  260, 260, 520,
  260, 260, 700,

  160,

  260, 260, 520,
  260, 260, 520,

  260, 260, 520,
  260, 260, 700,

  220
};

const int melodyLength = sizeof(notes) / sizeof(notes[0]);

void playNote(int freq, int durationMs) {
  if (freq == REST) {
    noTone(BUZZER_PIN);
    delay(durationMs);
    return;
  }

  tone(BUZZER_PIN, freq, durationMs);
  delay(durationMs * 1.18);
  noTone(BUZZER_PIN);
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < melodyLength; ++i) {
    playNote(notes[i], times[i]);
  }

  delay(1800);
}
