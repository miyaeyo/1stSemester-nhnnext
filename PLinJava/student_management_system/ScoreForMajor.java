package assignment3;

public class ScoreForMajor implements IScore { // 전공자들이 전공과목을 수강했을 때 학점 계산
	private static ScoreForMajor instance = new ScoreForMajor();

	public static ScoreForMajor getInstance(){
		if(instance == null){
			instance = new ScoreForMajor();
		}
		return instance;
	}
	
	@Override
	public char getGrade(int score) {
		if(score >94){
			return 'S';
		}
		else if(score>89 && score<=94){
			return 'A';
		}
		else if(score>79 && score <=89){
			return 'B';
		}
		else if(score>69 && score <=79){
			return 'C';
		}
		else if(score>59 && score <= 69){
			return 'D';
		}
		else{
			return 'F';
		}
		
	}

}
