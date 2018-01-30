#include "mbed.h"
#include "cmsis_os.h"

#define DEBUG true

void t1(void const*);
void t2(void const*);
void t3(void const*);

osThreadDef(t1, osPriorityNormal, 2048);
osThreadDef(t2, osPriorityNormal, 2048);
osThreadDef(t3, osPriorityNormal, 2048);