package org.raspoji.sensors;

public class MeasureException extends Exception {

	private static final long serialVersionUID = 165227523771220195L;

	public MeasureException() {
		super();
	}

	public MeasureException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	public MeasureException(String message, Throwable cause) {
		super(message, cause);
	}

	public MeasureException(String message) {
		super(message);
	}

	public MeasureException(Throwable cause) {
		
		super(cause);
	}

}
