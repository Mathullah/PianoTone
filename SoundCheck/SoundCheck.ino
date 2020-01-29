const uint16_t MIN_TONE_FREQUENCY(100);
const uint16_t MAX_TONE_FREQUENCY(5000);
const uint16_t FREQUENCY_STEP(20);

const uint8_t OUTPUT_PIN(8);

void setup() {

  tone(OUTPUT_PIN, 1047);
  delay(500);
  tone(OUTPUT_PIN, 1319);
  delay(500);
  tone(OUTPUT_PIN, 1568);
  delay(500);
  noTone(OUTPUT_PIN);  
  delay(500);
}

void loop() {


  uint16_t Frequency (MIN_TONE_FREQUENCY);

  for (Frequency; Frequency < MAX_TONE_FREQUENCY; Frequency += FREQUENCY_STEP)
  {
      tone(OUTPUT_PIN, Frequency);
      delay(20);
  }

  noTone(OUTPUT_PIN);
  
}
