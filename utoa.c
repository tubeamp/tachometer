#include "utoa.h"

// power of 2 table
int p2t[] =
{
    100,
    10,
    1
};

/*------------------------------------------------------------
------------------------------------------------------------*/
void u8toa( uint8_t value, char* s )
{
    char	buf[3];
    uint8_t	ti		= 0;
    uint8_t	counter	= 0;
    uint8_t r		= value;

	// in case of zero
    if ( value == 0 )
    {
        s[0] = 0;
        s[1] = 0;
        s[2] = 0;
        return;
    };

	//
    while ( ti < 3 )
    {
        while ( r >= p2t[ ti ] )
        {
            r -= p2t[ ti ];
            counter++;
        }
        buf[ ti ] = counter;
        counter = 0;
        ti++;
    }

	// output
    for (int i = 0; i < 3; i++ )
        s[i] = buf[i];
}

/*------------------------------------------------------------
------------------------------------------------------------*/
void u8tos( uint8_t value, char* s )
{
	u8toa( value, s );
	s[0] = s[0] + '0';
	s[1] = s[1] + '0';
	s[2] = s[2] + '0';
	s[3] = 0;
}
