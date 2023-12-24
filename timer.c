#include "timer.h"

#define TICKS_1MS 1530  // tweak this number to get 1ms delay

void delay(int ms)
{
    volatile int i;
    while (ms > 0)
    {
        // delay for 1 millisecond
       for(i=0;i<TICKS_1MS;i++)
            ;

        ms--;
    }
}
