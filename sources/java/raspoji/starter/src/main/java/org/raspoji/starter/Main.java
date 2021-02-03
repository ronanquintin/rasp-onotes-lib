package org.raspoji.starter;

import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.PinState;
import com.pi4j.io.gpio.RaspiPin;

public class Main {

	public static void main(String[] args) {
		final GpioController gpio = GpioFactory.getInstance();
		
		GpioPinDigitalOutput  led = gpio.provisionDigitalOutputPin(
				RaspiPin.GPIO_00,             // PIN NUMBER
				"led",
				PinState.LOW
				); // PIN RESISTANCE (optional)
		
		led.pulse(1000);
	}

}
