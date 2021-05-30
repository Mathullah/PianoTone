/**
 * @file    PianoTone.h
 * @author  Mathias Felix
 * @date    19.06.2020
 *
 * @brief   Header file holding CPianoTone class declaration.
 *
 */

#ifndef PIANO_TONE
	#define PIANO_TONE

class CPianoTone
{
    public:

        typedef enum
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

        CPianoTone();
        CPianoTone(const uint8_t Pin);

        uint16_t GetFrequency(const piano_tones_t Tone);
        void Play(const piano_tones_t Tone);
        void Mute(void);

    protected:

    private:

        static const float frequency_table[];

        uint8_t       m_Pin;
        piano_tones_t m_Note;

};

#endif
