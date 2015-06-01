package game;

public abstract class GameLevel {
	private String gameLevel;
	
	public GameLevel(String gameLevel){
		this.gameLevel = gameLevel;
	}
	
	public abstract void simpleAttack();
	public abstract void turnAttack();
	public abstract void flyingAttack();
	
	public final void play(){
		System.out.println("========== "+gameLevel+" START ==========");
		simpleAttack();
		turnAttack();
		flyingAttack();
		System.out.println("=========== "+gameLevel+" END ===========");
		
	}
}
