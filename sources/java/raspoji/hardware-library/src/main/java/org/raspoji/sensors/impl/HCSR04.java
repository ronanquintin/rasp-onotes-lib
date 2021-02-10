package org.raspoji.sensors.impl;

import org.raspoji.constants.PhysicalConstants;
import org.raspoji.quantities.LengthUnit;
import org.raspoji.quantities.Quantity;
import org.raspoji.sensors.MeasureException;
import org.raspoji.sensors.Sensor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import com.pi4j.io.gpio.GpioPinDigitalInput;
import com.pi4j.io.gpio.GpioPinDigitalOutput;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class HCSR04 implements Sensor{
	
	private static final Logger logger = LoggerFactory.getLogger(HCSR04.class); 
	
	private static final int TEN_MICROSECONDS = 10000;

	private GpioPinDigitalOutput trigger;
	
	private  GpioPinDigitalInput echo;
	
	public Quantity doMeasure() throws MeasureException {
		long echoPulseStartTime = 0;
		long echoPulseEndTime = 0;
		
		// Send an impulse during 10 micro seconds
		logger.debug("Set trigger to high");
		this.trigger.high();
		try {
			logger.debug("Waiting ten microseconds");
			Thread.sleep(0, TEN_MICROSECONDS);
		} catch (InterruptedException e) {
			throw new MeasureException(e);
		}
		
		logger.debug("Set trigger to low");
		this.trigger.low();
		
		logger.debug("Waiting that echo goes from low to high, then low an measuring nano time interval");
		while(echo.isLow()) {
			echoPulseStartTime = System.nanoTime();
		} // Waiting to have an high signal (wait until isn't low anymore)
		
		while(echo.isHigh()) { // Then waiting that the signal goes down (wait until isn't high anymore)
			echoPulseEndTime= System.nanoTime();
		}
		
		long totalEchoDuration = echoPulseEndTime -echoPulseStartTime;
	
		logger.debug("nano time interval is {}", totalEchoDuration);
		
		long oneWayEchoDuration  = totalEchoDuration / 2;
		
		// We have to convert m/s in m/ns by dividing by 10e9
		double distanceInMeters = (PhysicalConstants.SOUND_SPEED_AT_SEA_LEVEL / 1000000000.0) * oneWayEchoDuration;
		double distanceInCentimeters = distanceInMeters * 100; 

		return Quantity.of(LengthUnit.CM, distanceInCentimeters);
	}

}
