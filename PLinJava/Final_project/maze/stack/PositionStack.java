package maze.stack;

import java.util.ArrayList;

public class PositionStack {
	private int top;
	private ArrayList<Position> positionStack = new ArrayList<Position>();
	
	public PositionStack(){ // maze에 사용할 position stack생성
		top = 0;
		positionStack.add(new Position(0,1));
	}

	public int getTop(){
		return top;
	}
	
	public ArrayList<Position> getPositionStack(){
		return positionStack;
	}
	
	public boolean isEmpty(){ // position stack이 비어있는지 check
		return (top == 0);
	}
	
	public void push(int x, int y){ // positionStack에 좌표값 집어 넣음.
		Position position = new Position(x,y);
		top++;
		positionStack.add(top,position);
	}
	
	public void pop(){
		if(isEmpty()){
			System.out.println("the position stack is empty.");
			return;
		} 
		top--; 
	}
	
	public Position peek(){
		return positionStack.get(top);
	}

}
