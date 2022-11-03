#ifndef GNDLORA_H
#define GNDLORA_H

#include "../definitions/defs.h"

#define FREQUENCY_BAND 915E6

void initHeltecLoRa();
void sendLoRaCommand(uint8_t chutePin);
void getDownStream();

#endif // GNDLORA_H