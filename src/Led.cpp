
#include "Led.h"

Led::Led(Pin* vccPin) {
	m_vccPin = vccPin;
}

Led::~Led() {
	m_vccPin->setMode(PinMode::PM_OUT);
}


void Led::on(){
	m_vccPin->writePin(PinDigitalValue::PDV_HIGH);
}

void Led::off(){
	m_vccPin->writePin(PinDigitalValue::PDV_LOW);
}
