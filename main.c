#include "tm4c123.h"
#include "sw.h"
#include "led.h"
#include "timer.h"


int n=1, led=0, m=0, i=1;

int main(void)
{

    sw_init();
    led_init();

    while(1)
    {

        if(sw_get()&0x10)               // if SW1 is pressed
        {
            n=n%4+1;                    // change speed multiplier
        }

        if(sw_get()&0x01)               // if SW2 is pressed
        {
            m=(m+1)%5;                  // change switch case for blink pattern
        }

        delay(250*n);                   // wait

        switch (m)
        {
        case 0:

            led_on(led);
            break;

        case 1:

            if (led == 0)
                led = 2;
            led_on(led);
            delay(250*n);
            led_off(0x0E);
            break;

        case 2:

            led_on(1 << i);
            break;

        case 3:

            led_on(1 << i);
            delay(250*n);                        // wait
            led_off(0x0E);
            break;

        case 4:

            led_on(1 << i);
            delay(250*n);                        // wait
            led_off(0x0E);

            delay(250*n);                        // wait
            led_on(1 << i);
            delay(250*n);                        // wait
            led_off(0x0E);
            break;

        }

        led=(led+2)%16;                         // update 'led'
        i=(i+1)%3+1;                            // update 'i'

    }
}

