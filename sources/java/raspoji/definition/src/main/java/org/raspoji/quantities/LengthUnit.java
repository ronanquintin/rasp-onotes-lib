package org.raspoji.quantities;

public enum LengthUnit implements Unit {
	
	CM,M,KM;
	

	@Override
	public LengthUnit getBaseUnit() {
		return M;
	}
	
	
	
}
