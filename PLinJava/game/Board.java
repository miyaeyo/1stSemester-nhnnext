package game;

//숙제할때 player unit을 여러개 만들어 보기!!
public class Board {

	public static void main(String[] args) {
		Player player1 = new Player("player1");
		Player player2 = new Player("player2");
		Player player3 = new Player("player3");
		
		player1.attack(player1.getGameLevel());
		player1.upgradeLevel();
		player1.attack(player1.getGameLevel());
		player1.upgradeLevel();
		player1.attack(player1.getGameLevel());
		
		player2.attack(player2.getGameLevel());
		player2.upgradeLevel();
		player2.attack(player2.getGameLevel());
		
		player3.attack(player3.getGameLevel());
		
		
	

	}
}
