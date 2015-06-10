package assignment3;

public class EnglishClass extends Course { // 영어 과목 singleton 
	private EnglishClass(){
		this.courseId = initId();
		this.courseName = "영어";
		this.majorId = getMajorId();
		getStudentList();
		
	}
	private static EnglishClass instance = new EnglishClass();
	
	public static EnglishClass getInstance(){
		if(instance == null){
			instance = new EnglishClass();
		}
		return instance;
	}
	

}
