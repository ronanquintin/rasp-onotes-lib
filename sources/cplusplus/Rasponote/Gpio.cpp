#include "Gpio.h"

#include <wiringPi.h>
#include <iostream>

using namespace std;

Gpio::Gpio() {

	cout << "calling wiringPiSetup() to initialize GPIO library" << endl;

	wiringPiSetup();

	cout << "Initializing GPIO internal pin representation" << endl;

	/** physical pin index, wiring pi index, nickname */
	m_pins[0] = new Pin(1, -1, "3v3 Power", PinType::PT_3_3V);
	m_pins[1] = new Pin(2, -1, "5v Power", PinType::PT_5V);
	m_pins[2] = new Pin(3, 8, "BCM 2 (SDA)", PinType::PT_I2C);
	m_pins[3] = new Pin(4, -1, "5v Power", PinType::PT_5V);
	m_pins[4] = new Pin(5, 9, "BCM 3 (SCL)", PinType::PT_I2C);
	m_pins[5] = new Pin(6, -1, "Ground", PinType::PT_GROUND);
	m_pins[6] = new Pin(7, 7, "BCM 4 (GPCLK0)", PinType::PT_GPIO);
	m_pins[7] = new Pin(8, 15, "BCM 14 (TXD)", PinType::PT_UART);
	m_pins[8] = new Pin(9, -1, "Ground", PinType::PT_GROUND);
	m_pins[9] = new Pin(10, 16, "BCM 15 (RXD)", PinType::PT_UART);

	m_pins[10] = new Pin(11, 0, "BCM 17", PinType::PT_GPIO);
	m_pins[11] = new Pin(12, 1, "BMC 18 (PWM0)", PinType::PT_GPIO);
	m_pins[12] = new Pin(13, 2, "BCM 27", PinType::PT_GPIO);
	m_pins[13] = new Pin(14, -1, "Ground", PinType::PT_GROUND);
	m_pins[14] = new Pin(15, 3, "BCM 22", PinType::PT_GPIO);
	m_pins[15] = new Pin(16, 4, "BCM 23", PinType::PT_GPIO);
	m_pins[16] = new Pin(17, -1, "3v3 Power", PinType::PT_3_3V);
	m_pins[17] = new Pin(18, 5, "BCM 24", PinType::PT_GPIO);
	m_pins[18] = new Pin(19, 12, "BCM 10 (MOSI)", PinType::PT_SPI);
	m_pins[19] = new Pin(20, -1, "Ground", PinType::PT_GROUND);

	m_pins[20] = new Pin(21, 13, "BCM 9 (MISO)", PinType::PT_SPI);
	m_pins[21] = new Pin(22, 6, "BCM 25", PinType::PT_GPIO);
	m_pins[22] = new Pin(23, 14, "BCM 11 (SCLK)", PinType::PT_SPI);
	m_pins[23] = new Pin(24, 10, "BCM 8 (CE0)", PinType::PT_SPI);
	m_pins[24] = new Pin(25, -1, "Ground", PinType::PT_GROUND);
	m_pins[25] = new Pin(26, 11, "BCM 7 (CE1)", PinType::PT_SPI);
	m_pins[26] = new Pin(27, 30, "BCM 0 (ID_SD)", PinType::PT_I2C);
	m_pins[27] = new Pin(28, 31, "BCM 1 (ID_SC)", PinType::PT_I2C);
	m_pins[28] = new Pin(29, 21, "BCM 5", PinType::PT_GPIO);
	m_pins[29] = new Pin(30, -1, "Ground", PinType::PT_GROUND);

	m_pins[30] = new Pin(31, 22, "BCM 6", PinType::PT_GPIO);
	m_pins[31] = new Pin(32, 26, "BCM 12 (PWM0)", PinType::PT_GPIO);
	m_pins[32] = new Pin(33, 23, "BCM 13(PWM1)", PinType::PT_GPIO);
	m_pins[33] = new Pin(34, -1, "Ground", PinType::PT_GROUND);
	m_pins[34] = new Pin(35, 24, "BCM 19 (MISO)", PinType::PT_SPI);
	m_pins[35] = new Pin(36, 27, "BCM 16", PinType::PT_GPIO);
	m_pins[36] = new Pin(37, 25, "BCM 26", PinType::PT_GPIO);
	m_pins[37] = new Pin(38, 28, "BCM 20 (MOSI)", PinType::PT_SPI);
	m_pins[38] = new Pin(39, -1, "Ground", PinType::PT_GROUND);
	m_pins[39] = new Pin(40, 29, "BCM 21 (SCLK)", PinType::PT_SPI);

}

Gpio::~Gpio() {
	for (int i = 0; i < m_pinsLength; i++) {
		delete m_pins[i];
	}
}

Pin* Gpio::getPin(int physicalPinNumber) {
	cout << "Giving pin " << physicalPinNumber << endl;
	return m_pins[physicalPinNumber - 1];
}

