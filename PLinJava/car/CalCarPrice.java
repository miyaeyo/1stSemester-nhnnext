package car;

public class CalCarPrice {
	
	int sonataPrice;
	int grandeurPrice;
	int genesisPrice;

	public CalCarPrice(Car[] car) {
		for(int i = 0; i<car.length; i++){
			int carPrice = car[i].price*car[i].numOfCar;
			if(car[i] instanceof Sonata)
				sonataPrice = carPrice;
			else if(car[i] instanceof Grandeur)
				grandeurPrice = carPrice;
			else if(car[i] instanceof Genesis)
				genesisPrice = carPrice;
		}
	}
	
}
