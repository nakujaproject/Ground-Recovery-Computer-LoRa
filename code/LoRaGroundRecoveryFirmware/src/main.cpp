#include "../lib/definitions/defs.h"
#include <Tasks.h>
#include <GNDLoRa.h>
#include <Functions.h>

TaskHandle_t ListenDownStreamTaskHandle = NULL;
TaskHandle_t DrogueInterruptTaskHandle = NULL;
TaskHandle_t MainChuteInterruptTaskHandle = NULL;

const BaseType_t pro_cpu = 0;
const BaseType_t app_cpu = 1;

void setup()
{
  initHeltecLoRa();

  setPinModes();

  // initialize core 0 tasks
  xTaskCreatePinnedToCore(ListenDownStreamTask, "ListenDownStreamTask", 3000, NULL, 1, &ListenDownStreamTaskHandle, pro_cpu);

  // initialize core 1 tasks
  xTaskCreatePinnedToCore(DrogueInterruptTask, "DrogueInterruptTask", 3000, NULL, 1, &DrogueInterruptTaskHandle, app_cpu);
  xTaskCreatePinnedToCore(MainChuteInterruptTask, "MainChuteInterruptTask", 3000, NULL, 1, &MainChuteInterruptTaskHandle, app_cpu);

  // delete setup task
  vTaskDelete(NULL);
}

void loop()
{
  // delete loop task
  vTaskDelete(NULL);
}