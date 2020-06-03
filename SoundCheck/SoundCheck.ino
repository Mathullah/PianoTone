
#include <math.h>

const uint16_t MIN_TONE_FREQUENCY(440);
const uint16_t MAX_TONE_FREQUENCY(5000);
const uint16_t FREQUENCY_STEP(40);

const uint8_t OUTPUT_PIN(8);

const float tone_C6(1046.5F);
const float tone_E6(1318.51F);
const float tone_G6(1567.98F);


enum
{
    TONE_A0  = 0,
    TONE_Ab0,
    TONE_B0
} piano_tones_t;

                                      //An        A#n       Bn        Cn        C#n       Dn        D#n       En        Fn        F#n       Gn        G#n  
static const float frequency_table[] = {27.5000F, 29.1352F, 30.8677F, 32.7032F, 34.6478F, 36.7081F, 38.8909F, 41.2034F, 43.6535F, 46.2493F, 48.9994F, 51.9131F, 
                                        55.0000F, 58.2705F, 61.7354F, 65.4064F, 69.2957F, 73.4162F, 77.7817F, 82.4069F, 87.3071F, 92.4986F, 97.9989F, 103.826F,                                       
                                        110.000F, 116.541F, 123.471F, 130.813F, 138.591F, 146.832F, 155.563F, 164.814F, 174.614F, 184.997F, 195.998F, 207.652F,
                                        220.000F, 233.082F, 246.942F, 261.626F, 277.183F, 293.665F, 311.127F, 329.628F, 349.228F, 369.994F, 391.995F, 415.305F,
                                                                                                                                                       4186.01F};





void setup() {

  tone(OUTPUT_PIN, static_cast<uint16_t>round(tone_C6));
  delay(500);
  tone(OUTPUT_PIN, static_cast<uint16_t>round(tone_E6));
  delay(500);
  tone(OUTPUT_PIN, static_cast<uint16_t>round(tone_G6));
  delay(500);
  noTone(OUTPUT_PIN);  
  delay(500);
}

void loop() {

  for (uint16_t Frequency = MIN_TONE_FREQUENCY; Frequency < MAX_TONE_FREQUENCY; Frequency += FREQUENCY_STEP)
  {
      tone(OUTPUT_PIN, Frequency);
      delay(20);
  }
}
