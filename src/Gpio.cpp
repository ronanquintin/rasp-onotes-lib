#include "Gpio.h"
#include "wiringPi.h"


Gpio::Gpio() {
	wiringPiSetup () ; // @suppress("Function cannot be resolved")
	for(int i=0; i<m_pinsLength; i++){
		m_pins[i] = new Pin(i+1);
	}
}

Gpio::~Gpio() {
	for(int i=0; i<m_pinsLength; i++){
		delete m_pins[i];
	}
}

