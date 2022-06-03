#ifndef HCSR04_H_
#define HCSR04_H_

#include "Pin.h"

class HCSR04UltrasonicSensor
{
private:

	Pin* m_trigPin;
	Pin* m_echoPin;

public:
	HCSR04UltrasonicSensor(Pin* trigPin, Pin* echoPin);
	virtual ~HCSR04UltrasonicSensor();

	int performMeasure();

};


#endif /* HCSR04_H_ */