package org.raspoji.sensors.hcsr04;

import com.pi4j.io.gpio.event.GpioPinDigitalStateChangeEvent;
import com.pi4j.io.gpio.event.GpioPinListenerDigital;

import lombok.Getter;

public class HCSR04EchoListener implements GpioPinListenerDigital {

	private long echoPulseStartTime;
	private long echoPulseEndTime;
	private long currentMeasure;
	
	@Getter
	private boolean measureAvailable;

	
	public HCSR04EchoListener() {
		reinit();
	}

	public void reinit() {
		echoPulseStartTime = 0;
		echoPulseEndTime = 0;
		currentMeasure = 0;
		measureAvailable = false;
	}
	
	
	
	
	@Override
	public void handleGpioPinDigitalStateChangeEvent(GpioPinDigitalStateChangeEvent event) {
		currentMeasure = System.nanoTime();
		if(event.getState().isHigh()) {
			echoPulseStartTime = currentMeasure;
		}else {
			echoPulseEndTime = currentMeasure;
			measureAvailable = true;
		}
	}
	
	
	
	public long getInterval() {
		return echoPulseEndTime - echoPulseStartTime;
	}

}
