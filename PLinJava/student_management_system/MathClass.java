package assignment3;

public class MathClass extends Course{ // 수학 과목 singleton
	private MathClass(){
		this.courseId = initId();
		this.courseName = "수학";
		this.majorId = getMajorId();
		getStudentList();
		
	}
	private static MathClass instance = new MathClass();
	
	public static MathClass getInstance(){
		if(instance == null){
			instance = new MathClass();
		}
		return instance;
	}

}
