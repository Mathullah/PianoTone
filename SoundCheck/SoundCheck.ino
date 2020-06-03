const uint16_t MIN_TONE_FREQUENCY(440);
const uint16_t MAX_TONE_FREQUENCY(5000);
const uint16_t FREQUENCY_STEP(40);

const uint8_t OUTPUT_PIN(8);

const float tone_C6(1046.5F);
const float tone_E6(1318.51F);
const float tone_G6(1567.98F);

void setup() {

  tone(OUTPUT_PIN, static_cast<uint16_t>(tone_C6));
  delay(500);
  tone(OUTPUT_PIN, static_cast<uint16_t>(tone_E6));
  delay(500);
  tone(OUTPUT_PIN, static_cast<uint16_t>(tone_G6));
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
