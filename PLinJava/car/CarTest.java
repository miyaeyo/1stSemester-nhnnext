package car;

public class CarTest {

	public static void main(String[] args) {
		int sonataNum = 3; // �ڵ��� ����� �ٲ��ָ� ����.
		int grandeurNum = 2;
		int genesisNum = 1;
		
		Car car[] = {new Sonata(sonataNum), new Grandeur(grandeurNum), new Genesis(genesisNum)};
		CalCarPrice carPrice = new CalCarPrice(car);
		
		System.out.println("Hyundai ���� ���� ���");
		for(int i=0; i<car.length; i++){
			System.out.println(car[i].modelName + ": " + car[i].numOfCar + "��");
			if(car[i] instanceof Sonata)
				System.out.println("=>"+carPrice.sonataPrice+"����");
			else if(car[i] instanceof Grandeur)
				System.out.println("=>"+carPrice.grandeurPrice+"����");
			else if(car[i] instanceof Genesis)
				System.out.println("=>"+carPrice.genesisPrice+"����");
		}
		
		Hyundai total = Hyundai.getInstance(); // �ڵ����� �ϳ� ������� ������ Hyundai �ڵ��� ȸ�翡 ���ݰ� ����� ��
		System.out.println("Total: "+(total.CarCount()-1)+"��, "+(total.CarPrice(0))+"����");

	}
}
