#ifndef TASKS_H
#define TASKS_H
#include "../definitions/defs.h"

void DrogueInterruptTask(void *parameter);
void MainChuteInterruptTask(void *parameter);
void ListenDownStreamTask(void *parameter);

#endif // TASKS_H