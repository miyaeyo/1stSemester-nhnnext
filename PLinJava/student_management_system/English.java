package assignment3;

public class English extends Major{ // 영어 전공 singleton pattern, 전공클래스를 추가하게되면 같은 포맷의 클래스만 하나 더만들면 됨.
	private English(){
		this.majorId = initId();
		this.majorName = "영어";
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
