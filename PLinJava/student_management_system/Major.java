package assignment3;

import java.util.ArrayList;

public class Major implements ISession{
	protected int majorId;
	private static int defaultMajorId = initMajorId;
	protected String majorName;
	private ArrayList<Student> student = new ArrayList<Student>();
	private ArrayList<Course> course = new ArrayList<Course>();
	NEXTuniv next = NEXTuniv.getInstance();
	
	public void getMajorCourse(){
		for(int i = 0; i<next.getCourseList().size(); i++){
			Course c = next.getCourseList().get(i);
			if(c.majorId == this.majorId){
				course.add(c);
			}
		}
	}
	
	@Override
	public void getStudentList() {
		for(int i = 0; i < next.getStudentList().size(); i++){
			Student s = next.getStudentList().get(i);
			if(s.getMajorId() == this.majorId){
				student.add(s);
			}
		}
		
	}

	@Override
	public int initId() {
		return majorId = defaultMajorId++;
	}

	
	
}
