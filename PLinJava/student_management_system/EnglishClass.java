package assignment3;

public class EnglishClass extends Course { // ���� ���� singleton 
	private EnglishClass(){
		this.courseId = initId();
		this.courseName = "����";
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
