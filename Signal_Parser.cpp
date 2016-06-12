/*********************************************************************
Version 2.0
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
                        Parser Base Class
*********************************************************************/
/*
#include "Signal_Parser.h"
#include "Arduino.h"

unsigned int fparse_preamble(unsigned long signal) {
    return (signal >> 14) & 0x3FF;
}

unsigned int fparse_load(unsigned long signal) {
    return (signal >> 4) & 0x3FF;
}

unsigned int fparse_postamble(unsigned long signal) {
    return (signal & 0xF);
}

bool get_state(unsigned long signal) {
    return (signal & 0xF) == 12;
}
*/