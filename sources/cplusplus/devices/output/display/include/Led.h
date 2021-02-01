
#ifndef LED_H_
#define LED_H_

#include "Pin.h"

class Led {

private:
	Pin* m_vccPin;
public:
	Led(Pin* vccPin);
	virtual ~Led();

	void on();
	void off();
};

#endif /* LED_H_ */
