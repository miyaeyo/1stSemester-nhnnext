package game;

public class GameLevel3 extends GameLevel{
	private static GameLevel3 level3 = new GameLevel3();
	
	private GameLevel3(){
		super("Level3");
	}
	
	public static GameLevel3 getLevel3(){
		return level3;
	}

	@Override
	public void simpleAttack() {
		System.out.println("Level3 simple attack: �޷�~�޷�~�޷�");
	}

	@Override
	public void turnAttack() {
		System.out.println("Level3 turn attack: �ڵ������� �յ�������");	
	}

	@Override
	public void flyingAttack() {
		System.out.println("Level3 flying attack: �������� ��~~");
	}
}
