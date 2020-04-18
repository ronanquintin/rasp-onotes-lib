#include <iostream>
#include <thread>
#include <chrono>


#include "Led.h"
#include "Gpio.h"


int main(int argc, char **argv) {


		Gpio gpio;
		Led redLed(gpio.getPin(11));

		while(true){
			redLed.on();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			redLed.off();
			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		}



	return 0;
}
