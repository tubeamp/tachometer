#include "ssd.h"
#include "util.h"

/*
segment	pin		port
a		11		0
b		7		7
c		4		5
d		2		2
e		1		1
f		10		4
g		5		6
dp		3		3
*/

uint8_t seg_table[] = {
	//common anode, 0 = on
	//bgcfpdea
	// numbers
	0b01001000,		// 0
	0b01011111,		// 1
	0b00111000,		// 2
	0b00011010,		// 3
	0b00001111,		// 4
	0b10001010,		// 5
	0b10001000,		// 6
	0b01011110,		// 7
	0b00001000,		// 8
	0b00001010,		// 9
	0b11111111		// space (all off)
	// letters
	// TODO : add letters
};

#define DP_BIT 7

#define DIGITS_MASK ( _BV(0) | _BV(1) | _BV(2) | _BV(3) )

// digits
uint8_t dig_table[] = {
	~(1<<0),
	~(1<<1),
	~(1<<2),
	~(1<<3)
};


uint8_t dp_pos = 2;
uint8_t	active_digit = 0;	    // разряд
uint8_t	out_buf[4];				// буфер с кодами

/*------------------------------------------------------------

------------------------------------------------------------*/
void ssd_init( void )
{
	DDRC =	DIGITS_MASK;

	PORTC = _BV(1) |
			_BV(2) |
			_BV(3);

	DDRD = 0xFF;

}

/*------------------------------------------------------------

------------------------------------------------------------*/
void ssd_putc( char c[4] )
{
    for ( int i = 0; i < 4; i++ )
        out_buf[i] = c[i];

    //active_digit = 0;
}

/*------------------------------------------------------------

------------------------------------------------------------*/
void ssd_frame( void )
{
	uint8_t digit_code = seg_table[ out_buf[ active_digit ] ];

	// dot
	if ( active_digit  == dp_pos ) CLR_BIT( digit_code, DP_BIT );

	// disable all digits
	OUT( PORT_DIGIT, 0xFF, DIGITS_MASK );

	PORT_SEGMENTS = digit_code;

	// enable active digit
	OUT( PORT_DIGIT, dig_table[ active_digit ], DIGITS_MASK );

	active_digit++;
	if ( active_digit > 3 ) { active_digit = 0; }

}
