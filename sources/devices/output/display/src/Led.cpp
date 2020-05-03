#include "Led.h"
#include <iostream>

Led::Led(Pin* vccPin) {
	m_vccPin = vccPin;
	m_vccPin->setMode(PinMode::PM_OUT);
	std::cout << "Led instantiated on pin physical number " << vccPin->getPinNumber();
}

Led::~Led() {

}


void Led::on(){
	std::cout << "Led on" << std::endl;
	m_vccPin->writePin(PinDigitalValue::PDV_HIGH);
}

void Led::off(){
	std::cout << "Led off" << std::endl;
	m_vccPin->writePin(PinDigitalValue::PDV_LOW);
}
