package assignment3;

public class Mathematics extends Major{// 수학전공 singleton
	private Mathematics(){
		this.majorId = initId();
		this.majorName = "수학";
		getStudentList();
		getMajorCourse();
	
	}
	private static Mathematics instance = new Mathematics();
	
	public static Mathematics getInstance(){
		if(instance == null){
			instance = new Mathematics();
		}
		return instance;
	}

	
}
