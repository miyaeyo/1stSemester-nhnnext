package maze.run;

import maze.stack.Position;

public interface IMazeRun { // maze interface. 
	boolean checkWall(int x, int y);
	boolean checkEndOfMaze(int x, int y);
	boolean checkNewPath(int x, int y);
	Position findPath();
	void moveFoward(int x, int y);
	void moveBackward();
	int getStackCount();
	void endOfMaze();
	void runMaze();
}
