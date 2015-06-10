package assignment3;

public class English extends Major{
	private English(){
		this.majorId = initId();
		this.majorName = "¿µ¾î";
		getStudentList();
		getMajorCourse();
	}
	private static English instance = new English();
	
	public static English getInstance(){
		if(instance == null){
			instance = new English();
		}
		return instance;
	}

	
	
}
