package shipping;

public class ShippingMain {
	public static void main(String[] args){
		Company company = Company.getCompany();
		company.addVehicle(new Truck(500, 50)); // distance, efficiency
		company.addVehicle(new RiverBarge(100, 20));
		company.addVehicle(new RiverBarge(300, 10));
		company.addVehicle(new Truck(200, 10));
		company.addVehicle(new Truck(100, 10));
		
		FuelNeedsReport report = new FuelNeedsReport();
		System.out.println("Total Fuel Needs: "+report.generateReport());
		
	}

}
// �����Ҷ� player unit�� ������ ����� ����!! , interface, object class�о����!! 