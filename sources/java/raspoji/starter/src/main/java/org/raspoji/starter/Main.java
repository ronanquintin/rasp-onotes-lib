package org.raspoji.starter;

import org.raspoji.quantities.Quantity;
import org.raspoji.sensors.MeasureException;
import org.raspoji.sensors.impl.HCSR04;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.pi4j.io.gpio.GpioController;
import com.pi4j.io.gpio.GpioFactory;
import com.pi4j.io.gpio.GpioPinDigitalInput;
import com.pi4j.io.gpio.GpioPinDigitalOutput;
import com.pi4j.io.gpio.PinState;
import com.pi4j.io.gpio.RaspiPin;

public class Main {

	private static final Logger logger = LoggerFactory.getLogger(Main.class);
	
	public static void main(String[] args) {
		final GpioController gpio = GpioFactory.getInstance();
		
		
		
		
		GpioPinDigitalOutput  trigger = gpio.provisionDigitalOutputPin(
				RaspiPin.GPIO_00,             // PIN NUMBER
				"trigger",
				PinState.LOW
				); 
		
		GpioPinDigitalInput echo = gpio.provisionDigitalInputPin(
				RaspiPin.GPIO_02,
				"echo"
				);

		HCSR04 sensor = new HCSR04(trigger, echo);
		
		while (!Thread.interrupted()) {
			try {
				Quantity quantity = sensor.doMeasure();
				logger.info("Distance {} {}",  quantity.getAmount(), quantity.getUnit().toString());
			} catch (MeasureException e) {
				logger.error("Error while measuring because of {}", e.getMessage());
			}
			
			
		}
		
	}

}
