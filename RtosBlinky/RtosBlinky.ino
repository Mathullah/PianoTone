#include <Arduino_FreeRTOS.h>

// Prototype definitions
void TaskBlink(void *pvParameters);
void TaskMonitor(void *pvParameters);
void TaskBeep(void *pvParameters);

static const uint16_t main_1s_dealy = 1000 / portTICK_PERIOD_MS;
static const uint16_t main_0s5_dealy = 500 / portTICK_PERIOD_MS;
static const uint16_t main_0s1_dealy = 100 / portTICK_PERIOD_MS;

static const uint16_t Periode(65535 - 100);


static const unsigned PUSH_BUTTON(6); 

volatile uint16_t State(0);
volatile bool DebouncedInput(false);

void setup() {

    pinMode(PUSH_BUTTON, INPUT_PULLUP);
    pinMode(LED_BUILTIN, OUTPUT);
  
    // Timer 1
    noInterrupts();           // Alle Interrupts temporär abschalten
    TCCR1A = 0;
    TCCR1B = 0;
  
    TCNT1 = Periode;            // Timer nach obiger Rechnung vorbelegen
    TCCR1B |= (1 << CS12);      // 256 als Prescale-Wert spezifizieren
    TIMSK1 |= (1 << TOIE1);     // Timer Overflow Interrupt aktivieren
    interrupts();


    xTaskCreate(TaskMonitor, "Monitor", 128, NULL, 2, NULL );
    xTaskCreate(TaskBeep,    "Beep",    128, NULL, 2, NULL );
    xTaskCreate(TaskBlink,   "Blink",   128, NULL, 2, NULL );

}

void loop()
{

}

void TaskBlink(void *pvParameters)
{
  (void) pvParameters;

  TickType_t LastWakeTime = xTaskGetTickCount();

  for (;;)
  {
      vTaskDelayUntil(&LastWakeTime, main_0s1_dealy);
    
      unsigned NewState = (DebouncedInput ? HIGH : LOW);
      digitalWrite(LED_BUILTIN, NewState);
  }
}

void TaskMonitor(void *pvParameters)
{
    (void) pvParameters;
    
    TickType_t LastWakeTime = xTaskGetTickCount();
    
    for (;;)
    {
        vTaskDelayUntil(&LastWakeTime, main_1s_dealy);
    
    }
}

void TaskBeep(void *pvParameters)
{
    (void) pvParameters;
    
    for (;;)
    {
    
    }
}

/**
 * Timer 1 Overflow ISR
 * https://www.embedded.com/my-favorite-software-debouncers/
 */
ISR(TIMER1_OVF_vect)        
{
    TCNT1 = Periode;
    
    uint16_t input = digitalRead(PUSH_BUTTON) ? 0 : 1;
    
    State = (State << 1) | input;

    if(State == 0x0000) { DebouncedInput = false; }
    if(State == 0xFFFF) { DebouncedInput = true; }
}
