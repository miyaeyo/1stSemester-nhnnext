package shipping;

import java.util.ArrayList;

public class Company {
	private ArrayList<Vehicle> vList = new ArrayList<Vehicle>();
	private static Company instance = new Company();
	
	private Company(){} //singleton
	
	public static Company getCompany(){
		return instance;
	}
	
	public ArrayList<Vehicle> getVehicle(){
		return vList;
	}
	
	public void addVehicle(Vehicle v){
		vList.add(v);
	}
	
	
}
