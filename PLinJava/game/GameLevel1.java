package game;

public class GameLevel1 extends GameLevel{
	private static GameLevel1 level1 = new GameLevel1();
	
	private GameLevel1(){
		super("Level1");
	}
	
	public static GameLevel1 getLevel1(){
		return level1;
	}

	@Override
	public void simpleAttack() {
		System.out.println("Level1 simple attack: ¸Ş·Õ~~~");
	}

	@Override
	public void turnAttack() {
		System.out.println("Level1 turn attack: ¸øÇÏÁö·Õ");	
	}

	@Override
	public void flyingAttack() {
		System.out.println("Level1 flying attack: ÀÌ°Íµµ ¸øÇÏÁö·Õ");
	}
}
