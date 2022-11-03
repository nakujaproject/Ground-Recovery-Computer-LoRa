#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "../definitions/defs.h"

void setPinModes();
void IRAM_ATTR sendEjectDrogueCommand();
void IRAM_ATTR sendEjectMainCommand();

#endif // FUNCTIONS_H