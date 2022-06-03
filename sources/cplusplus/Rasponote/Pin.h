
#ifndef DEVICE_PIN_H_
#define DEVICE_PIN_H_

#include <string>


enum class PinType{
	PT_GPIO,
	PT_SPI,
	PT_I2C,
	PT_UART,
	PT_GROUND,
	PT_5V,
	PT_3_3V

};

std::string pinTypeAsString(PinType pinType);

enum class PinMode{
	PM_IN,
	PM_OUT
};

std::string pinModeAsString(PinMode pinMode);


enum class PinDigitalValue {
	PDV_LOW,
	PDV_HIGH
};

enum class PullUpMode {
	PUM_LOW, 
	PUM_HIGH,
	PUM_OFF
};

std::string pinDigitalValueAsString(PinDigitalValue pinDigitalValue);


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
	PinDigitalValue readDigitalValue();
	void waitForValue(PinDigitalValue value);

	void syncStateFromGPIO();

	void setPullUpMode(PullUpMode pullUpMode);

	std::string toString();
	std::string getPinTypeAsString();
	std::string getCurrentModeAsString();
	std::string getCurrentDigitalValueAsString();



	PinMode getCurrentMode() const;
	PinDigitalValue getCurrentPinDigitalValue() const;
	std::string getPinName() const;
	int getPinNumber() const;
	PinType getPinType() const;
	int getWiringPiNumber() const;
};



#endif /* DEVICE_PIN_H_ */
