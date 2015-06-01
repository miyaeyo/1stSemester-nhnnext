package shipping;

import java.util.ArrayList;

public class FuelNeedsReport {
	Company company = Company.getCompany();
	ArrayList<Vehicle> vList = company.getVehicle();
	
	public double generateReport() {
		double sumFuelNeeds = 0;
		for(int i = 0; i< vList.size(); i++){
			sumFuelNeeds += vList.get(i).calcFuelNeeds();
		}
		return sumFuelNeeds;
	}	
}
