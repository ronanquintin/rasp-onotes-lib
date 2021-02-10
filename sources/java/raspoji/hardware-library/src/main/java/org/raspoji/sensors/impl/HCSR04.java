package org.raspoji.sensors.impl;

import org.raspoji.constants.PhysicalConstants;
import org.raspoji.quantities.LengthUnit;
import org.raspoji.quantities.Quantity;
import org.raspoji.sensors.MeasureException;
import org.raspoji.sensors.Sensor;

import com.pi4j.io.gpio.GpioPinDigitalInput;
import com.pi4j.io.gpio.GpioPinDigitalOutput;

import lombok.AllArgsConstructor;

@AllArgsConstructor
public class HCSR04 implements Sensor{
	
	
	
	private static final int TEN_MICROSECONDS = 10000;

	private GpioPinDigitalOutput trigger;
	
	private  GpioPinDigitalInput echo;
	
	public Quantity doMeasure() throws MeasureException {
		
		// Send an impulse during 10 micro seconds
		this.trigger.high();
		try {
			Thread.sleep(0, TEN_MICROSECONDS);
		} catch (InterruptedException e) {
			throw new MeasureException(e);
		}
		this.trigger.low();
		
		while(echo.isLow()) {} // Waiting to have an high signal (wait until isn't low anymore)
		long echoPulseStartTime = System.nanoTime();
		
		while(echo.isHigh()) {} // Then waiting that the signal goes down (wait until isn't high anymore)
		long echoPulseEndTime = System.nanoTime();
		
		long totalEchoDuration = echoPulseEndTime -echoPulseStartTime;
		long oneWayEchoDuration  = totalEchoDuration / 2;
		
		// We have to convert m/s in m/ns by dividing by 10e9
		double distance = (PhysicalConstants.SOUND_SPEED_AT_SEA_LEVEL / 1000000000.0) * oneWayEchoDuration;
		
		return Quantity.of(LengthUnit.M, distance);
	}

}
