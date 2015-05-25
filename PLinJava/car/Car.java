package car;

public class Car {
	String modelName;
	int price;
	int numOfCar;
	
	public Car(String modelName, int price, int numOfCar){
		this.modelName = modelName;
		this.price = price;
		this.numOfCar = numOfCar;
		
		Hyundai newCar = Hyundai.getInstance();
		for(int i=0; i<numOfCar; i++){
			newCar.increaseCarCount();
			newCar.increaseCarPrice(price);
		}
	}
}
