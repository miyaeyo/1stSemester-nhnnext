package maze.info;

public class MazeDisplay {
	
	private int[][] mazeArray;
		
	public MazeDisplay(int[][] mazeArray){
		this.mazeArray = mazeArray;
	}
	
	public void displayMazePath(){
		for(int i = 0; i< mazeArray.length; i++){
			for(int j = 0; j< mazeArray[0].length; j++){
				switch(mazeArray[i][j]){
				case 0: System.out.print("◻︎");break; //path 
				case 1: System.out.print("◼︎");break; //wall
				case 2: System.out.print("☆");break; //passed path
				}
			}
			System.out.println();
		}
		System.out.println();
	}
	
}
