package assignment3;

public class ScoreForNonMajor implements IScore{// 비전공자들이 과목 수강했을 때 학점계산

	private static ScoreForNonMajor instance = new ScoreForNonMajor();

	public static ScoreForNonMajor getInstance(){
		if(instance == null){
			instance = new ScoreForNonMajor();
		}
		return instance;
	}
	
	@Override
	public char getGrade(int score) {
		if(score>89){
			return 'A';
		}
		else if(score>79 && score<=89){
			return 'B';
		}
		else if(score>69 && score<=79){
			return 'C';
		}
		else if(score>54 && score<=69){
			return 'D';
		}
		else{
			return 'F';
		}
		
	}

}
