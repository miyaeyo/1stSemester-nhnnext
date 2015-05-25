package car;

public class Hyundai {
	private static Hyundai hyundai = new Hyundai();
	private int carCount = 0;
	private int totalCarPrice = 0;
	
	private Hyundai(){}
	
	public static Hyundai getInstance(){
		if(hyundai == null){
			hyundai = new Hyundai();
		}
		return hyundai;
	}
	
	public int increaseCarCount(){
		return ++carCount;
	}
	
	public int increaseCarPrice(int price){
		return totalCarPrice += price;
	}
}
