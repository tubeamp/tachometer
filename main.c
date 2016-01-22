/*
 */

#include <avr/io.h>
#include <util/delay.h>
#include "ssd.h"
#include "util.h"


// input : PB1 PB2

int main(void)
{

    ssd_init();
    char buf[] = {1,2,3,4};

    ssd_putc( buf );

    while(1)
    {
    	ssd_frame();
		_delay_ms(2);

    };

    return 0;
}
