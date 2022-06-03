
#include "Pin.h"

#include <wiringPi.h>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

Pin::Pin(int pinNumber,  int wiringPiNumber, string pinName,PinType pinType) {
	m_pinNumber = pinNumber;
	m_pinName = pinName;
	m_wiringPiNumber = wiringPiNumber;
	m_pinType = pinType;
	syncStateFromGPIO();

}

Pin::~Pin() {
}

void Pin::writePin(PinDigitalValue value){
	digitalWrite(m_wiringPiNumber, (value == PinDigitalValue::PDV_LOW )? 0 : 1 );
	m_currentPinDigitalValue = value;
}

PinDigitalValue Pin::readDigitalValue()
{

	return digitalRead(m_wiringPiNumber) == 0 ? PinDigitalValue::PDV_LOW : PinDigitalValue::PDV_HIGH;
	
}

void Pin::waitForValue(PinDigitalValue value)
{

	while (readDigitalValue() != value) {

	}
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
	m_currentMode=mode;
}


void Pin::syncStateFromGPIO(){
	
	m_currentMode = getAlt(m_wiringPiNumber) == 0 ? PinMode::PM_IN : PinMode::PM_OUT;
	m_currentPinDigitalValue = digitalRead(m_wiringPiNumber) == 0 ? PinDigitalValue::PDV_LOW : PinDigitalValue::PDV_HIGH;

}

void Pin::setPullUpMode(PullUpMode pullUpMode)
{
	int wiringPiPudMode;
	switch (pullUpMode) {
	case PullUpMode::PUM_OFF:
		wiringPiPudMode = 0;
		break;

	case PullUpMode::PUM_LOW:
		wiringPiPudMode = 1;
		break;
	case PullUpMode::PUM_HIGH:
		wiringPiPudMode = 2;
		break;
	}

	pullUpDnControl(m_wiringPiNumber, wiringPiPudMode);

}

string Pin::toString(){
	ostringstream os;
	os << "Physical number : " << m_pinNumber << ", ";
	os << "wiringPi number : " << m_wiringPiNumber << ", ";
	os << "name : "  << m_pinName << ", ";
	os << "type : " << getPinTypeAsString() << ", ";
	os << "current mode : " << getCurrentModeAsString() << ", ";
	os << "current digital value : " << getCurrentDigitalValueAsString();
	return os.str();
}




string pinTypeAsString(PinType pinType){
	switch (pinType) {
		case PinType::PT_3_3V:
			return "3,3V";

		case PinType::PT_5V:
			return "5V";

		case PinType::PT_GPIO:
			return "GPIO";

		case PinType::PT_GROUND:
			return "Ground";

		case PinType::PT_I2C:
			return "I2C";

		case PinType::PT_SPI:
			return "SPI";

		case PinType::PT_UART:
			return "UART";
		default:
			return "UNKNOWN pin type, which should highlight a programming error";

	}
}

string pinModeAsString(PinMode pinMode){
	return pinMode == PinMode::PM_IN ? "IN" : "OUT";
}

string pinDigitalValueAsString(PinDigitalValue pinDigitalValue){
	return pinDigitalValue == PinDigitalValue::PDV_HIGH ? "HIGH" : "LOW";
}

string Pin::getCurrentModeAsString(){
	return pinModeAsString(m_currentMode);
}

string Pin::getCurrentDigitalValueAsString(){
	return pinDigitalValueAsString(m_currentPinDigitalValue);
}

string Pin::getPinTypeAsString(){
	return pinTypeAsString(m_pinType);
}


PinMode Pin::getCurrentMode() const {
	return m_currentMode;
}

PinDigitalValue Pin::getCurrentPinDigitalValue() const {
	return m_currentPinDigitalValue;
}

string Pin::getPinName() const {
	return m_pinName;
}

int Pin::getPinNumber() const {
	return m_pinNumber;
}

PinType Pin::getPinType() const {
	return m_pinType;
}


int Pin::getWiringPiNumber() const {
	return m_wiringPiNumber;
}
