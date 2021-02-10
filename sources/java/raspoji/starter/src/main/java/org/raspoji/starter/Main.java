package org.raspoji.starter;

import org.raspoji.quantities.Quantity;
import org.raspoji.sensors.MeasureException;
import org.raspoji.sensors.hcsr04.HCSR04Sensor;
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
		
		
		
		logger.info("Provisionning GPIO trigger");
		GpioPinDigitalOutput  trigger = gpio.provisionDigitalOutputPin(
				RaspiPin.GPIO_00,             // PIN NUMBER
				"trigger",
				PinState.LOW
				); 
		
		logger.info("Provisionning GPIO echo");
		GpioPinDigitalInput echo = gpio.provisionDigitalInputPin(
				RaspiPin.GPIO_02,
				"echo"
				);

		HCSR04Sensor sensor = new HCSR04Sensor(trigger, echo);
		
		while (!Thread.interrupted()) {
			try {
				Quantity quantity = sensor.doMeasure();
				logger.info("Distance {} {}",  quantity.getAmount(), quantity.getUnit().toString());
				Thread.sleep(1000);
			} catch (MeasureException | InterruptedException e) {
				logger.error("Error while measuring because of {}", e.getMessage());
			}
			
			
		}
		
	}

}
