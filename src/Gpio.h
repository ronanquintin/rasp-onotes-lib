
#ifndef GPIO_H_
#define GPIO_H_

#include "Pin.h"


class Gpio {


private:

	static int const m_pinsLength = 40;

	Pin* m_pins[m_pinsLength];

public:
	Gpio();
	virtual ~Gpio();

	Pin* getPinByWiringPiIndex(int wiringPiIndex);
};

#endif /* GPIO_H_ */
