#include "Signal_Composer.h"

/*  Helper Functions  */
static void one(byte pin);
static void zero(byte pin);

/*  returns an unsigned long containing the preamble and load
 *  with the last 4 bits set to be zero so that the user
 *  can OR it with ON or OFF
 */
unsigned long compose_signal(unsigned long preamble, unsigned long load) {
	
	return (preamble << 14) | (load << 4);
}

/*  sends the signal with the given state
 *  ON == true; OFF == false;
 */
 /*
void send_signal(unsigned long sig, bool s, byte pin) {
  byte state = (state ? _ON : _OFF);
  send_signal(sig, state, pin);
}
*/
void send_signal(unsigned long sig, byte state, byte pin) {
  sig |= (state & 15);  /* only takes 4-bits (safety precaution) */
  /* loop 8 times to make sure signal is recieved */
  for (int i = 0; i < 8; i++) {
  	delayMicroseconds(_BREAK);
    /*  goes to -1 for the extra zero() that should be sent 
        at end of a signal  */
    for (int j = 23; j >= 0; j--) {
      if ( (sig >> j) & 1)  one(pin);
      else zero(pin);
    }
    one(pin);
  }
}

static void one(byte pin) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(_HIGHLONG);
  digitalWrite(pin, LOW);
  delayMicroseconds(_LOWSHORT);
}

static void zero(byte pin) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(_HIGHSHORT);
  digitalWrite(pin, LOW);
  delayMicroseconds(_LOWLONG);
}
