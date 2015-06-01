package shipping;

public class RiverBarge extends Vehicle{
	public RiverBarge(int distance, int efficiency){
		super(distance, efficiency);
	}

	@Override
	public int calcTripDistance() {
		return distance;
	}
	
	public int calcFuelEfficiency() {
		return efficiency;
	}

}
