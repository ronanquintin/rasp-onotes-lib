
#ifndef DEVICE_PIN_H_
#define DEVICE_PIN_H_

#include <string>
#include <wiringPi.h>

enum class PinType{
	PT_GPIO,
	PT_SPI,
	PT_I2C,
	PT_UART,
	PT_GROUND,
	PT_5V,
	PT_3_3V

};

enum class PinMode{
	PM_IN,
	PM_OUT
};


enum class PinDigitalValue {
	PDV_LOW,
	PDV_HIGH
};

class Pin {
private:

	// Pin caracterstics can't change
	int m_pinNumber;
	int m_wiringPiNumber;
	std::string m_pinName;
	PinType m_pinType;

	// Pin current state
	PinMode m_currentMode;
	PinDigitalValue m_currentPinDigitalValue;




public:



	Pin(int pinNumber, int wiringPiNumber, std::string pinName, PinType pinType);
	virtual ~Pin();

	void setMode(PinMode mode);
	void writePin(PinDigitalValue value);
};



#endif /* DEVICE_PIN_H_ */
