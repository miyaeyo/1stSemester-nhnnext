package game;

public class GameLevel2 extends GameLevel{
	private static GameLevel2 level2 = new GameLevel2();
	
	private GameLevel2(){
		super("Level2");
	}
	
	public static GameLevel2 getLevel2(){
		return level2;
	}

	@Override
	public void simpleAttack() {
		System.out.println("Level2 simple attack: 메롱~메롱~");
	}

	@Override
	public void turnAttack() {
		System.out.println("Level2 turn attack: 돌려차기 씽~~");	
	}

	@Override
	public void flyingAttack() {
		System.out.println("Level2 flying attack: 이건 못하지롱");
	}
}
