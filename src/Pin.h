
#ifndef DEVICE_PIN_H_
#define DEVICE_PIN_H_


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

	int m_pinNumber;




public:



	Pin(int pinNumber);
	virtual ~Pin();

	void setMode(PinMode mode);
	void writePin(PinDigitalValue value);
};



#endif /* DEVICE_PIN_H_ */
