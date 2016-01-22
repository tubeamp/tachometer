/*------------------------------------------------------------

------------------------------------------------------------*/

#ifndef SSD_H
#define SSD_H

#include <avr/io.h>

#define PORT_DIGIT		PORTC
#define PORT_SEGMENTS	PORTD

#define SSD_SPACE 10


extern uint8_t dp_pos;

void ssd_init	( void );
void ssd_putc	( char c[4] );
void ssd_frame	( void );

#endif
