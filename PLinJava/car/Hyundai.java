package car;

public class Hyundai {
	private static Hyundai hyundai = new Hyundai();
	private int carCnt = 0;
	private int totalCarPrice = 0;
	
	private Hyundai(){}
	
	public static Hyundai getInstance(){
		if(hyundai == null)
			hyundai = new Hyundai();
			
		return hyundai;
	}
	
	public int CarCount(){
		return ++carCnt;
	}
	
	public int CarPrice(int price){
		return totalCarPrice += price;
	}
}
