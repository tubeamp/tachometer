/*
    Some helpful macros
*/

#ifndef _UTIL_H_
#define _UTIL_H_

#define PULLUP_OFF	0
#define PULLUP_ON 	1

#define PORT_IN		0
#define PORT_OUT	1


#define HI(x) ( (x) >> 8 )
#define LO(x) ( (x) & 0xFF )

#define HIT(x) ( (x) >> 4 )
#define LOT(x) ( (x) & 0x0F )

#define SET_BIT(port,bit) ( port |= (uint8_t) (1 << (bit)) )
#define CLR_BIT(port,bit) ( port &= (uint8_t) ~(1 << (bit)) )
#define INV_BIT(port,bit) ( port ^= (uint8_t) (1 << (bit)) )

#define SET_BITM(port,mask) ( port |= (uint8_t) (mask) )
#define CLR_BITM(port,mask) ( port &= (uint8_t) ~(mask) )
#define INV_BITM(port,mask) ( port ^= (uint8_t) (mask) )

#define OUT(port,value,mask) ( port = (uint8_t) (port&~(mask))|(value) )

#define CHK_BIT(port,bit) ( port & (uint8_t)_BV(bit) )



#endif
