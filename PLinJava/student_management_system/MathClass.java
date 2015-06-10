package assignment3;

public class MathClass extends Course{ // ���� ���� singleton
	private MathClass(){
		this.courseId = initId();
		this.courseName = "����";
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
