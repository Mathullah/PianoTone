
#include "PianoTone.h"

const uint8_t OUTPUT_PIN(8);

void setup() {

  CPianoTone Tone(OUTPUT_PIN);

  Tone.Play(CPianoTone::TONE_C6);
  delay(500);

  Tone.Play(CPianoTone::TONE_E6); 
  delay(500);
  
  Tone.Play(CPianoTone::TONE_G6);    
  delay(500); 

  Tone.Mute();

}

void loop() {

}
