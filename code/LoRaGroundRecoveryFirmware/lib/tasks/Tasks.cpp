#include <Tasks.h>
#include <GNDLoRa.h>

extern uint8_t GROUND_DROGUE_PIN;
extern uint8_t GROUND_MAIN_PIN;

void DrogueInterruptTask(void *parameter)
{
    for (;;)
    {
        vTaskSuspend(NULL);
        sendLoRaCommand(GROUND_DROGUE_PIN);
    }
}
void MainChuteInterruptTask(void *parameter)
{
    for (;;)
    {
        vTaskSuspend(NULL);
        sendLoRaCommand(GROUND_MAIN_PIN);
    }
}

void ListenDownStreamTask(void *parameter)
{
    for (;;)
    {
        getDownStream();
        vTaskDelay(5);
    }
}
