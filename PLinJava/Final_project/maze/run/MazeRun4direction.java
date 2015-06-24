package maze.run;

import java.util.ArrayList;

import maze.stack.Position;

public class MazeRun4direction extends MazeRun{
	private ArrayList<Position> positionStack = super.getPositionStack();
	private int top = super.getTop();
	
	@Override
	public Position findPath() {
		
		int[][] moveCase = {{0,1},{1,0},{0,-1},{-1,0}}; // 4 direction
		top = super.getTop();
		int currentX = positionStack.get(top).getx();
		int currentY = positionStack.get(top).gety();
		
		for(int i = 0; i< moveCase.length; i++){
			int candiX = currentX + moveCase[i][0];
			int candiY = currentY + moveCase[i][1];
		
			if(checkWall(candiX, candiY)){
				continue;
			}else{
				if(checkNewPath(candiX, candiY)){
					return (new Position(candiX, candiY));
				}
			}	
		}
		
		return null;
	}

}
