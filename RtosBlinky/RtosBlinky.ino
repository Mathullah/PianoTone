#include <Arduino_FreeRTOS.h>

// Prototype definitions
void TaskBlink(void *pvParameters);
void TaskMonitor(void *pvParameters);
void TaskBeep(void *pvParameters);

static const uint16_t main_1s_dealy = 1000 / portTICK_PERIOD_MS;
static const uint16_t main_0s5_dealy = 500 / portTICK_PERIOD_MS;
static const uint16_t main_10ms_dealy = 20 / portTICK_PERIOD_MS;

static const uint16_t Periode = (34286);

void setup() {

    pinMode(LED_BUILTIN, OUTPUT);  // Ausgabe LED festlegen
  
    // Timer 1
    noInterrupts();           // Alle Interrupts temporär abschalten
    TCCR1A = 0;
    TCCR1B = 0;
  
    TCNT1 = Periode;            // Timer nach obiger Rechnung vorbelegen
    TCCR1B |= (1 << CS12);    // 256 als Prescale-Wert spezifizieren
    TIMSK1 |= (1 << TOIE1);   // Timer Overflow Interrupt aktivieren
    interrupts();             // alle Interrupts scharf schalten

    //xTaskCreate(TaskBlink, "Blink", 128, NULL, 2, NULL );

}

void loop()
{

}

void TaskBlink(void *pvParameters)
{
  (void) pvParameters;

  //pinMode(LED_BUILTIN, OUTPUT);
  TickType_t LastWakeTime = xTaskGetTickCount();

  xTaskCreate(TaskMonitor, "Monitor", 128, NULL, 2, NULL );
  xTaskCreate(TaskBeep,    "Beep",    128, NULL, 2, NULL );

  for (;;)
  {
      vTaskDelayUntil(&LastWakeTime, main_0s5_dealy);
    
      //unsigned NewState = (digitalRead(LED_BUILTIN) ? LOW : HIGH);
      //digitalWrite(LED_BUILTIN, NewState);
  }
}

void TaskMonitor(void *pvParameters)
{
  (void) pvParameters;

  TickType_t LastWakeTime = xTaskGetTickCount();

  for (;;)
  {
      vTaskDelayUntil(&LastWakeTime, main_1s_dealy);

      //unsigned NewState = (digitalRead(LED_BUILTIN) ? LOW : HIGH);
      //digitalWrite(LED_BUILTIN, NewState);
  }
}

void TaskBeep(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {

  }
}

// Hier kommt die selbstdefinierte Interruptbehandlungsroutine 
// für den Timer Overflow
ISR(TIMER1_OVF_vect)        
{
  TCNT1 = Periode;
  digitalWrite(LED_BUILTIN, digitalRead(LED_BUILTIN) ^ 1);
}
