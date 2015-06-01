package game;


public class Player {
	String player;
	private GameLevel level[] = {GameLevel1.getLevel1(), GameLevel2.getLevel2(), GameLevel3.getLevel3()};
	private int i=0;
	
	public Player(String player){
		this.player = player;
	}
	
	public void upgradeLevel(){ // if���� ������ i�� �ִ밪�� ������ ���� ������ ��
		i++;
	}
	public GameLevel getGameLevel(){
		return level[i];
	}
	public void attack(GameLevel level){
		System.out.println("<"+player+" Attack>");
		level.play();
	}

}
