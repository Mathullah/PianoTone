
#include <math.h>

const uint16_t MIN_TONE_FREQUENCY(440);
const uint16_t MAX_TONE_FREQUENCY(5000);
const uint16_t FREQUENCY_STEP(40);

const uint8_t OUTPUT_PIN(8);

enum
{
    TONE_NONE = 0,
    TONE_A0  =  1,
    TONE_Bb0 =  2,
    TONE_B0  =  3,
    TONE_C1  =  4,
    TONE_Db1 =  5,
    TONE_D1  =  6,
    TONE_Eb1 =  7,
    TONE_E1  =  8,
    TONE_F1  =  9,
    TONE_Gb1 = 10,
    TONE_G1  = 11,
    TONE_Ab1 = 12,
    TONE_A1  = 13,
    TONE_Bb1 = 14,
    TONE_B1  = 15,
    TONE_C2  = 16,
    TONE_Db2 = 17,
    TONE_D2  = 18,
    TONE_Eb2 = 19,
    TONE_E2  = 20,
    TONE_F2  = 21,
    TONE_Gb2 = 22,
    TONE_G2  = 23,
    TONE_Ab2 = 24,
    TONE_A2  = 25,
    TONE_Bb2 = 26,
    TONE_B2  = 27,
    TONE_C3  = 28,
    TONE_Db3 = 29,
    TONE_D3  = 30,
    TONE_Eb3 = 31,
    TONE_E3  = 32,
    TONE_F3  = 33,
    TONE_Gb3 = 34,
    TONE_G3  = 35,
    TONE_Ab3 = 36,
    TONE_A3  = 37,
    TONE_Bb3 = 38,
    TONE_B3  = 39,
    TONE_C4  = 40,
    TONE_Db4 = 41,
    TONE_D4  = 42,
    TONE_Eb4 = 43,
    TONE_E4  = 44,
    TONE_F4  = 45,
    TONE_Gb4 = 46,
    TONE_G4  = 47,
    TONE_Ab4 = 48,
    TONE_A4  = 49,
    TONE_Bb4 = 50,
    TONE_B4  = 51,
    TONE_C5  = 52,
    TONE_Db5 = 53,
    TONE_D5  = 54,
    TONE_Eb5 = 55,
    TONE_E5  = 56,
    TONE_F5  = 57,
    TONE_Gb5 = 58,
    TONE_G5  = 59,
    TONE_Ab5 = 60,
    TONE_A5  = 61,
    TONE_Bb5 = 62,
    TONE_B5  = 63,
    TONE_C6  = 64,
    TONE_Db6 = 65,
    TONE_D6  = 66,
    TONE_Eb6 = 67,
    TONE_E6  = 68,
    TONE_F6  = 69,
    TONE_Gb6 = 70,
    TONE_G6  = 71,
    TONE_Ab6 = 72,
    TONE_A6  = 73,
    TONE_Bb6 = 74,
    TONE_B6  = 75,
    TONE_C7  = 76,
    TONE_Db7 = 77,
    TONE_D7  = 78,
    TONE_Eb7 = 79,
    TONE_E7  = 80,
    TONE_F7  = 81,
    TONE_Gb7 = 82,
    TONE_G7  = 83,
    TONE_Ab7 = 84,
    TONE_A7  = 85,
    TONE_Bb7 = 86,
    TONE_B7  = 87,
    TONE_C8  = 88
} piano_tones_t;

                                      //An        A#n       Bn        Cn        C#n       Dn        D#n       En        Fn        F#n       Gn        G#n
static const float frequency_table[] = {00.0000F,
                                        27.5000F, 29.1352F, 30.8677F, 32.7032F, 34.6478F, 36.7081F, 38.8909F, 41.2034F, 43.6535F, 46.2493F, 48.9994F, 51.9131F,
                                        55.0000F, 58.2705F, 61.7354F, 65.4064F, 69.2957F, 73.4162F, 77.7817F, 82.4069F, 87.3071F, 92.4986F, 97.9989F, 103.826F,
                                        110.000F, 116.541F, 123.471F, 130.813F, 138.591F, 146.832F, 155.563F, 164.814F, 174.614F, 184.997F, 195.998F, 207.652F,
                                        220.000F, 233.082F, 246.942F, 261.626F, 277.183F, 293.665F, 311.127F, 329.628F, 349.228F, 369.994F, 391.995F, 415.305F,
                                        440.000F, 466.164F, 493.883F, 523.251F, 554.365F, 587.330F, 622.254F, 659.255F, 698.456F, 739.989F, 783.991F, 830.609F,
                                        880.000F, 932.328F, 987.767F, 1046.50F, 1108.73F, 1174.66F, 1244.51F, 1318.51F, 1396.91F, 1479.98F, 1567.98F, 1661.22F,
                                        1760.00F, 1864.66F, 1975.53F, 2093.00F, 2217.46F, 2349.32F, 2489.02F, 2637.02F, 2793.83F, 2959.96F, 3135.96F, 3322.44F,
                                        3520.00F, 3729.31F, 3951.07F, 4186.01F };



void setup() {

  tone(OUTPUT_PIN, static_cast<uint16_t>round(frequency_table[TONE_C6]));
  delay(500);
  tone(OUTPUT_PIN, static_cast<uint16_t>round(frequency_table[TONE_E6]));
  delay(500);
  tone(OUTPUT_PIN, static_cast<uint16_t>round(frequency_table[TONE_G6]));
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
