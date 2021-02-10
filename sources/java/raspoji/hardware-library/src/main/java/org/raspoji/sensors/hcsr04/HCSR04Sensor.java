package org.raspoji.sensors.hcsr04;

import org.raspoji.constants.PhysicalConstants;
import org.raspoji.quantities.LengthUnit;
import org.raspoji.quantities.Quantity;
import org.raspoji.sensors.MeasureException;
import org.raspoji.sensors.Sensor;

import com.pi4j.io.gpio.GpioPinDigitalInput;
import com.pi4j.io.gpio.GpioPinDigitalOutput;

public class HCSR04Sensor implements Sensor{
	
	
	private static final int TEN_MICROSECONDS = 10000;

	private GpioPinDigitalOutput trigger;
	
	private  GpioPinDigitalInput echo;
	
	private HCSR04EchoListener listener;
	
	public HCSR04Sensor(GpioPinDigitalOutput trigger, GpioPinDigitalInput echo) {
		super();
		this.trigger = trigger;
		this.echo = echo;
		this.listener = new HCSR04EchoListener();
		this.echo.addListener(this.listener);
	}



	public Quantity doMeasure() throws MeasureException {
		
		this.listener.reinit();
		
		// Send an impulse during 10 micro seconds
		this.trigger.high();
		try {
			Thread.sleep(0, TEN_MICROSECONDS);
		} catch (InterruptedException e) {
			throw new MeasureException(e);
		}
		
		this.trigger.low();
		
		
	
		long oneWayEchoDuration  = this.listener.getInterval() / 2;
		
		// We have to convert m/s in m/ns by dividing by 10e9
		double distanceInMeters = (PhysicalConstants.SOUND_SPEED_AT_SEA_LEVEL / 1000000000.0) * oneWayEchoDuration;
		double distanceInCentimeters = distanceInMeters * 100; 

		return Quantity.of(LengthUnit.CM, distanceInCentimeters);
	}

}
