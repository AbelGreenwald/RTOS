#include "mbed.h"
#include "cmsis_os.h"

void t1(void const*);
void t2(void const*);

osThreadDef(t1, osPriorityNormal, 2048);
osThreadDef(t2, osPriorityNormal,  2048);
