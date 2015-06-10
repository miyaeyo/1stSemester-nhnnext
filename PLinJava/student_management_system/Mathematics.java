package assignment3;

public class Mathematics extends Major{
	private Mathematics(){
		this.majorId = initId();
		this.majorName = "¼öÇÐ";
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
