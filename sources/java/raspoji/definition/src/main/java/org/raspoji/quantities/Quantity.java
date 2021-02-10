package org.raspoji.quantities;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
@AllArgsConstructor(staticName = "of")
public class Quantity {
	
	private Unit unit;
	
	private double amount;
	
}
