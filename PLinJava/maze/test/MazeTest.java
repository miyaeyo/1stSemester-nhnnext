package maze.test;
/**
 * [PLinJAVA FINAL] 
 *                   151008 정승미
 * 
 * <Problem Statement>
 * - 미로 찾기
 * 입구: 0,1  // wall을 전체적으로 한번 더 감싸기 위해서 입구와 출구가 조금 바뀌었습니다.
 * 출구: 9,8  
 * ◻: 갈수있는곳
 * ◼︎: wall
 * 입구에서 출구 까지 길을 찾아가는 문제를 구현한다.
 * 
 * - 구현 방법
 * 한 점에서 길을 찾는데 사용하는 direction이 4방향인 경우가 8방향인 경우 두 가지를 구현한다.
 * 4가지인 경우 :( 2,2 ) 위치에서 볼 수 있는 도달 가능 위치는 N(2,1), W(3,2), S(2,3), E(1,2)
 * 8가지인 경우: ( 2,2 ) 위치에서 볼 수 있는 도달 가능 위치는 NN(2,1), NW(3,1), WW(3,2), SW(3,3), SS(2,3), SE(1,3), EE(1,2), NE(1,1) stack이 필요하다면 사용한다.
 * stack은 JDK를 사용하지 않고 직접 구현한다.
 * 인터페이스를 활용하도록 한다.
 * 실행은 환경 파일(direction.properties)에서 direction의 정보를 변경할 때 해당 로직이 수행되도록 한다.
 * 예)search direction=4
 * 
 * - 출력
 * 이차원 배열의 미로 모양
 * path 와 wall 을 구별하여 출력 두가지 방식으로 구현했을 때 비교되는 점 출력 예) stack에 각위치가 input된 count
 * 
 * 
 * 
 */

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Properties;

import maze.run.MazeRun;
import maze.run.MazeRun4direction;
import maze.run.MazeRun8direction;

public class MazeTest {

	public static void main(String[] args) {
		MazeRun mazeRun = new MazeRun();
		
		FileInputStream fis = null;
		try {
			fis = new FileInputStream("direction.properties"); // 환경파일 direction.properties
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
		
		Properties property = new Properties();
		try {
			property.load(fis);
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		String dirType = property.getProperty("DIRECTION"); // direction.properties 안의 direction 정보는 DIRECTION을 통해 얻을 수 있다. 
		if(dirType.equals("4")){ // 4direction 방법
			mazeRun = new MazeRun4direction();
		}
		else if(dirType.equals("8")){ // 8direction 방법 
			mazeRun = new MazeRun8direction();
		}
		else{
			System.out.println("Direction type error");
			return;
		}
		// 출력 부분
		System.out.println("<"+dirType+"direction maze run>\n");
		mazeRun.runMaze(); // 이차원 배열의 미로
		System.out.println("Stack count: "+ mazeRun.getStackCount()); //stack count 
	}

}
