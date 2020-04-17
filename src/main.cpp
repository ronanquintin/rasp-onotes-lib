#include <iostream>

#include "Led.h"
#include "Pin.h"

using namespace std;

int main(int argc, char **argv) {

	Pin pin(0);
	Led redLed(&pin);

	redLed.on();


	return 0;
}
