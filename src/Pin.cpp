
#include "Pin.h"



Pin::Pin(int pinNumber,  int wiringPiNumber, std::string pinName,PinType pinType) {
	m_pinNumber = pinNumber;
	m_pinName = pinName;
	m_wiringPiNumber = wiringPiNumber;
	m_pinType = pinType;

}

Pin::~Pin() {
}

void Pin::writePin(PinDigitalValue value){

	digitalWrite(m_wiringPiNumber, (value == PinDigitalValue::PDV_LOW )? 0 : 1 );
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
	pinMode(m_wiringPiNumber, wiringPiMode) ;
}


