package car;

public class CarTest {

	public static void main(String[] args) {
		int sonataNum = 3; // 자동차 대수만 바꿔주면 계산됨.
		int grandeurNum = 2;
		int genesisNum = 1;
		
		Car car[] = {new Sonata(sonataNum), new Grandeur(grandeurNum), new Genesis(genesisNum)};
		CalCarPrice carPrice = new CalCarPrice(car);
		
		System.out.println("Hyundai 보유 차량 목록");
		for(int i=0; i<car.length; i++){
			System.out.println(car[i].modelName + ": " + car[i].numOfCar + "대");
			if(car[i] instanceof Sonata)
				System.out.println("=>"+carPrice.sonataPrice+"만원");
			else if(car[i] instanceof Grandeur)
				System.out.println("=>"+carPrice.grandeurPrice+"만원");
			else if(car[i] instanceof Genesis)
				System.out.println("=>"+carPrice.genesisPrice+"만원");
		}
		
		Hyundai total = Hyundai.getInstance(); // 자동차가 하나 만들어질 때마다 Hyundai 자동차 회사에 가격과 대수가 쌓
		System.out.println("Total: "+(total.CarCount()-1)+"대, "+(total.CarPrice(0))+"만원");

	}
}
