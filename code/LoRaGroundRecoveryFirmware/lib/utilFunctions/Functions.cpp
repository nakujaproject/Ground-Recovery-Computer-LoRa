#include <Functions.h>

uint8_t GROUND_DROGUE_PIN = 13;
uint8_t GROUND_MAIN_PIN = 23;

char DROGUE_MESSAGE[] = "D";
char MAIN_MESSAGE[] = "M";

extern TaskHandle_t DrogueInterruptTaskHandle;
extern TaskHandle_t MainChuteInterruptTaskHandle;

void setPinModes()
{
    // setup drogue button interrupt
    pinMode(GROUND_DROGUE_PIN, INPUT_PULLUP);                            // initialize pin HIGH
    attachInterrupt(GROUND_DROGUE_PIN, sendEjectDrogueCommand, FALLING); // press drogue push button

    // setup main button interrupt
    pinMode(GROUND_MAIN_PIN, INPUT_PULLUP);                          // initialize pin HIGH
    attachInterrupt(GROUND_MAIN_PIN, sendEjectMainCommand, FALLING); // press drogue push button
}

void IRAM_ATTR sendEjectDrogueCommand()
{
    BaseType_t checkIfYieldRequired;
    checkIfYieldRequired = xTaskResumeFromISR(DrogueInterruptTaskHandle);
    portYIELD_FROM_ISR(checkIfYieldRequired);
}
void IRAM_ATTR sendEjectMainCommand()
{
    BaseType_t checkIfYieldRequired;
    checkIfYieldRequired = xTaskResumeFromISR(MainChuteInterruptTaskHandle);
    portYIELD_FROM_ISR(checkIfYieldRequired);
}