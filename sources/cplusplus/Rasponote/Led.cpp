#include "Led.h"
#include <iostream>

using namespace std;

Led::Led(Pin* vccPin) {
	m_vccPin = vccPin;
	m_vccPin->setMode(PinMode::PM_OUT);
	cout << "Led instantiated on pin physical number " << vccPin->getPinNumber();
}

Led::~Led() {

}


void Led::on(){
	cout << "Led on" << endl;
	m_vccPin->writePin(PinDigitalValue::PDV_HIGH);
}

void Led::off(){
	cout << "Led off" << endl;
	m_vccPin->writePin(PinDigitalValue::PDV_LOW);
}
