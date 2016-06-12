#if !defined(SIGNAL_COMPOSER_H)
#define SIGNAL_COMPOSER_H

#include "Arduino.h"

/*	TIMINGS in microseconds (µS)	*/
#define _BREAK		5745
#define _HIGHLONG	500
#define _HIGHSHORT	135
#define _LOWSHORT	235
#define _LOWLONG	600

#define _ON  3
#define _OFF 12

/*  Macro version of compose_signal:
 *  WARNING: You cannot use variables with this macro,
 *              use only literals
 *  If wanting to pass vairables, use the function
 */

#define COMPOSE_SIGNAL(PREAMBLE,LOAD) \
                    ((PREAMBLE##ul << 14) | (LOAD##ul << 4))


unsigned long compose_signal(unsigned long, unsigned long);
// void send_signal(unsigned long, bool, byte);
void send_signal(unsigned long, byte, byte);


#endif
