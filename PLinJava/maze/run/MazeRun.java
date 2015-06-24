package maze.run;

import java.util.ArrayList;

import maze.info.MazeDisplay;
import maze.info.MazePath;
import maze.stack.Position;
import maze.stack.PositionStack;

public class MazeRun extends PositionStack implements IMazeRun{
	private int stackCount = 1;
	private int[][] maze = new MazePath().getMaze();
	private ArrayList<Position> positionStack = super.getPositionStack();
	private int top = super.getTop();
	
	public Position findPath(){
		return null;
	}
	
	public boolean checkWall(int x, int y){ 
		return (x >= maze.length|| y>= maze.length || x< 0|| y<0 || maze[x][y] == 1);
	}
	
	
	public boolean checkEndOfMaze(int x, int y){
		return (x == maze.length-1 && y == maze[0].length-2);
	}
	
	
	public boolean checkNewPath(int x, int y){
		for(Position position: positionStack){
			if(x == position.getx() && y == position.gety()){
				return false;
			}
		}
		return true;
	}
	
	
	public void moveFoward(int x, int y){
		push(x,y);
		stackCount++;
	}
	
	
	public void moveBackward(){
		pop();
		stackCount--;
	}
	

	public int getStackCount(){
		return stackCount;
	}
	
	
	public void endOfMaze(){ // maze가 끝나면 positionStack에 들어간 위치의 값을 maze에 대응시킨다
		for(Position position: positionStack){ // for in 구문
			maze[position.getx()][position.gety()] = 2;
		}
	}
	

	public void runMaze(){
		top = super.getTop();
		int currentX = positionStack.get(top).getx();
		int currentY = positionStack.get(top).gety();
		Position position = findPath();
		
		while(checkEndOfMaze(currentX, currentY) == false){
			if(position == null){
				moveBackward();
				top = super.getTop();
				currentX = positionStack.get(top).getx();
				currentY = positionStack.get(top).gety();
				position = findPath();
				positionStack.remove(top+1);
			}else{
				moveFoward(position.getx(), position.gety());
				top = super.getTop();
				currentX = positionStack.get(top).getx();
				currentY = positionStack.get(top).gety();
				position = findPath();
			}
		}
		endOfMaze();
		MazeDisplay md = new MazeDisplay(maze);
		md.displayMazePath();
	}
	
	

}
