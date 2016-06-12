/*********************************************************************
This is a library to control "Etekcity ZAP 5LX Remote Outlets"
with a 434MHz RF Transmitter and Arduino

You can pick up a set of outlets here:
http://www.etekcity.com/product/100058.html   

Along with a transmitter to talk to it:
http://amzn.com/B00M2CUALS

Please see http://www.webbhacks.com/Outlets
for more detailed information on this project

Written by Cameron J. Webb  (cam@webbhacks.com)

Copyright (c) 2015 Cameron J. Webb  
MIT License, check LICENSE for more information
All text above must be included in any redistribution

**********************************************************************
                         Outlet Signal Parser 
*********************************************************************/

#ifndef Signal_Parser_h
#define Signal_Parser_h
#include "Arduino.h"

#define CH1       339
#define CH2       348
#define CH3       368
#define CH4       464
#define CH5       848
                         
#define POST_ON   3
#define POST_OFF  12

/* MACRO FUNCTIONS */
#define parse_preamble(SIGNAL) ((SIGNAL >> 14) & 0x3FF)
#define parse_load(SIGNAL) ((SIGNAL >> 4) & 0x3FF)
#define parse_postamble(SIGNAL) (SIGNAL & 0xF)


/*  these functions take a 24-bit long signal and parse it into
 *  its corresponding parts */
                         /*
unsigned int fparse_preamble(unsigned long);
unsigned int fparse_load(unsigned long);
unsigned int fparse_postamble(unsigned long);
*/

// returns a boolean rather than the raw number for signal's state
// bool get_state(unsigned long);

#endif