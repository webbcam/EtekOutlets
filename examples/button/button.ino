#include "Signal_Composer.h"
#include <avr/sleep.h>
#include <avr/power.h>

#define ON true
#define OFF false
#define LED_PIN 13
#define DATA_PIN 5

volatile bool state = false;

unsigned long sig = COMPOSE_SIGNAL(325, 339);
unsigned long sig1 = COMPOSE_SIGNAL(325, 348);
unsigned long sig2 = COMPOSE_SIGNAL(325, 368);
unsigned long sig3 = COMPOSE_SIGNAL(325, 464);
unsigned long sig4 = COMPOSE_SIGNAL(325, 848);

void setup() {
  pinMode(DATA_PIN, OUTPUT);
  pinMode(2, INPUT_PULLUP); //  attach button to interrupt 0 of Uno
  attachInterrupt(0, send_the_signal, FALLING);

  pinMode(LED_PIN,OUTPUT);      // set pin 13 as an output so we can use LED to monitor
  digitalWrite(LED_PIN,LOW);   // turn pin 13 LED on

}

void loop() {
  delay(1000);  //  wait one second before going back to sleep
  
//  attachInterrupt(0, send_signal, FALLING);

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here  
  sleep_enable();          // enables the sleep bit in the mcucr register
  digitalWrite(LED_PIN,LOW);  
  sleep_mode();            // here the device is actually put to sleep!!  
  digitalWrite(LED_PIN,HIGH);   // shows when device is awoken!
  
  
//  sleep_disable();         // first thing after waking from sleep: disable sleep... 
//  detachInterrupt(0);
}

void send_the_signal() {
  if (state)
    send_signal(sig, OFF, DATA_PIN);
  else
    send_signal(sig, ON, DATA_PIN);

  state = !state;
}

