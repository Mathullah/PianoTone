#include <Arduino_FreeRTOS.h>

// Prototype definitions
void TaskBlink(void *pvParameters);

static const uint16_t main_1s_dealy = 1000 / portTICK_PERIOD_MS;
static const uint16_t main_0s5_dealy = 500 / portTICK_PERIOD_MS;

void setup() {

    xTaskCreate(TaskBlink, (const portCHAR *)"Blink", 128, NULL, 2, NULL );

}

void loop()
{

}



void TaskBlink(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED_BUILTIN, OUTPUT);

  TickType_t LastWakeTime = xTaskGetTickCount();

  for (;;)
  {
    vTaskDelayUntil(&LastWakeTime, main_0s5_dealy);
    
    unsigned NewState = (digitalRead(LED_BUILTIN) ? LOW : HIGH);
    digitalWrite(LED_BUILTIN, NewState);

  }
}
