package org.raspoji.sensors;

import org.raspoji.quantities.Quantity;

public interface Sensor {

	Quantity doMeasure() throws MeasureException;
}
