package shipping;

public class Truck extends Vehicle{
	public Truck(int distance, int efficiency){
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
