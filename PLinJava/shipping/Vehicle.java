package shipping;

public abstract class Vehicle {
	public int distance;
	public int efficiency;
	
	public Vehicle(int distance, int efficiency){
		this.distance = distance;
		this.efficiency = efficiency;
	}
	
	public abstract int calcTripDistance(); // abstract method
	public abstract int calcFuelEfficiency();
	
	public final double calcFuelNeeds(){ //template method pattern
		return calcTripDistance()/calcFuelEfficiency();
	}
	
	
}
