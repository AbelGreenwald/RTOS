#include "main.h"

osMutexId sem1;
osMutexDef(sem1);

DigitalOut led1(PB_0);
DigitalOut led2(PB_7);
DigitalOut led3(PB_14);

int main() {
    osKernelStart();
    osMutexCreate(osMutex(sem1));
    osThreadCreate(osThread(t2), NULL);
    osThreadCreate(osThread(t1), NULL);
    osThreadCreate(osThread(t3), NULL);

    osDelay(osWaitForever);
}

void t1(void const *argument){
    while (true) {
        osMutexWait(sem1, 0);
        osDelay(80);
        led1 = !led1;
        osMutexRelease(sem1);
    }
}

void t2(void const *argument){
    while (true) {
        osMutexWait(sem1, 0);
        osDelay(40);
        led2 = !led2;
        osMutexRelease(sem1);
    }
}

void t3(void const *argument){
    while (true) {
        osMutexWait(sem1, 0);
        osDelay(20);
        led3 = !led3;
        osMutexRelease(sem1);
    }
}
