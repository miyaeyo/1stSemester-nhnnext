package assignment3;

public interface ISession { // 전공과 과목 class에서 동시에 필요한것을 interface로 구현
	int initCourseId = 100; // public static final
	int initMajorId = 5000;
	void getStudentList(); // public abstract
	int initId();
	
}
