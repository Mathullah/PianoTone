/**
 * @file    PianoTone.cpp
 * @author  Mathias Felix
 * @date    19.06.2020
 *
 * @brief   Implementation of CPianoTone class.
 *
 */

#include "Arduino.h"
#include "PianoTone.h"

                                           //An        A#n       Bn        Cn        C#n       Dn        D#n       En        Fn        F#n       Gn        G#n
const float CPianoTone::frequency_table[] = {00.0000F,
                                             27.5000F, 29.1352F, 30.8677F, 32.7032F, 34.6478F, 36.7081F, 38.8909F, 41.2034F, 43.6535F, 46.2493F, 48.9994F, 51.9131F,
                                             55.0000F, 58.2705F, 61.7354F, 65.4064F, 69.2957F, 73.4162F, 77.7817F, 82.4069F, 87.3071F, 92.4986F, 97.9989F, 103.826F,
                                             110.000F, 116.541F, 123.471F, 130.813F, 138.591F, 146.832F, 155.563F, 164.814F, 174.614F, 184.997F, 195.998F, 207.652F,
                                             220.000F, 233.082F, 246.942F, 261.626F, 277.183F, 293.665F, 311.127F, 329.628F, 349.228F, 369.994F, 391.995F, 415.305F,
                                             440.000F, 466.164F, 493.883F, 523.251F, 554.365F, 587.330F, 622.254F, 659.255F, 698.456F, 739.989F, 783.991F, 830.609F,
                                             880.000F, 932.328F, 987.767F, 1046.50F, 1108.73F, 1174.66F, 1244.51F, 1318.51F, 1396.91F, 1479.98F, 1567.98F, 1661.22F,
                                             1760.00F, 1864.66F, 1975.53F, 2093.00F, 2217.46F, 2349.32F, 2489.02F, 2637.02F, 2793.83F, 2959.96F, 3135.96F, 3322.44F,
                                             3520.00F, 3729.31F, 3951.07F, 4186.01F };

/**
 * Specific constructor of CPulse class
 */
CPianoTone::CPianoTone(const uint8_t Pin) :
  m_Pin(Pin),
  m_Note(TONE_A4)
{
  
}

/**
 * Default constructor of CPulse class
 */
CPianoTone::CPianoTone() :
  m_Pin(0),
  m_Note(TONE_A4)
{
  
}

uint16_t CPianoTone::GetFrequency(const piano_tones_t Tone)
{
  return static_cast<uint16_t>round(frequency_table[Tone]);  
}

void CPianoTone::Play(const piano_tones_t Tone)
{
  uint16_t frequency(GetFrequency(Tone));
  tone(m_Pin, frequency);
}

void CPianoTone::Mute(void)
{
  noTone(m_Pin);
}
