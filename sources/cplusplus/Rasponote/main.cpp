#include <iostream>
#include <thread>
#include <chrono>


#include "Led.h"
#include "Gpio.h"
#include "HCSR04UltrasonicSensor.h"

using namespace std;

int main(int argc, char** argv) {


	Gpio gpio;


	Pin* triggerPin = gpio.getPin(11);
	Pin* echoPin = gpio.getPin(13);
	HCSR04UltrasonicSensor sensor(  triggerPin, echoPin);

	while (true) {
		cout << sensor.performMeasure() << endl;
	}



	return 0;
}
