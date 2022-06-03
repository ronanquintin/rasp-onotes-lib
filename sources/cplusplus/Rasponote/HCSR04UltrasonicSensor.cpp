#include "HCSR04UltrasonicSensor.h"
#include "Pin.h"

#include <wiringPi.h>
#include <iostream>
#include <thread>
#include <chrono>



using namespace std;

HCSR04UltrasonicSensor::HCSR04UltrasonicSensor( Pin* trigPin, Pin* echoPin)
{


	m_trigPin = trigPin;
	m_trigPin->setMode(PinMode::PM_OUT);
	m_trigPin->writePin(PinDigitalValue::PDV_LOW);

	m_echoPin = echoPin;
	m_echoPin->setMode(PinMode::PM_IN);
	m_echoPin->setPullUpMode(PullUpMode::PUM_LOW);


}

HCSR04UltrasonicSensor::~HCSR04UltrasonicSensor()
{
}

/*
* Return the distance in cm
*/
int HCSR04UltrasonicSensor::performMeasure()
{


	cout << "Launch trigger" << endl;
	m_trigPin->writePin(PinDigitalValue::PDV_HIGH);
	delayMicroseconds(10);
	m_trigPin->writePin(PinDigitalValue::PDV_LOW);



	auto start = chrono::high_resolution_clock::now();
	m_echoPin->waitForValue(PinDigitalValue::PDV_LOW);
	m_echoPin->waitForValue(PinDigitalValue::PDV_HIGH);
	m_echoPin->waitForValue(PinDigitalValue::PDV_LOW);
	auto end =  chrono::high_resolution_clock::now();

	auto elaspedTimeInMilliseconds = chrono::duration_cast<chrono::milliseconds>(end - start).count();

	return elaspedTimeInMilliseconds * 17.0;
}
