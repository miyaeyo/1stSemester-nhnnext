package assignment3;

import java.util.ArrayList;

public class Course implements ISession{
	protected int courseId;
	private static int defaultCourseId = initCourseId;
	protected String courseName;
	protected int majorId;
	protected ArrayList<Student> student = new ArrayList<Student>();
	NEXTuniv next = NEXTuniv.getInstance();
	
	public int getMajorId(){
		for(int i = 0; i<next.getMajorList().size(); i++){
			Major m = next.getMajorList().get(i);
			if(this.courseName == m.majorName){
				return m.majorId;
			}
		}
		return 0;
	}

	@Override
	public void getStudentList() {
		for(int i = 0; i<next.getStudentList().size(); i++){
			Student s = next.getStudentList().get(i);
			for(int j = 0; j<s.getStudentCourse().size(); j++){
				if(this.courseId == s.getStudentCourse().get(j).courseId){
					student.add(s);
				}
			}
			
		}
		
	}

	@Override
	public int initId() {
		return courseId = defaultCourseId++;
	}

	
	
	
	
	
}
