
#include "Pin.h"
#include <wiringPi.h>




Pin::Pin(int pinNumber) {
	m_pinNumber = pinNumber;

}

Pin::~Pin() {
}

void Pin::writePin(PinDigitalValue value){

	digitalWrite(m_pinNumber, (value == PinDigitalValue::PDV_LOW )? 0 : 1 );
}

void Pin::setMode(PinMode mode){
	int wiringPiMode;
	switch (mode) {
	case PinMode::PM_IN:
		wiringPiMode=0;
		break;
	case PinMode::PM_OUT:
		wiringPiMode=1;
		break;
	default:
		break;
	}
	pinMode(m_pinNumber, wiringPiMode) ;
}


