package assignment3;

import java.util.ArrayList;

public class Major implements ISession{ // 전공, 해당전공의 학생 list와 전공과목 list를 가지고 있다. 
	protected int majorId;
	private static int defaultMajorId = initMajorId;
	protected String majorName;
	private ArrayList<Student> student = new ArrayList<Student>();
	private ArrayList<Course> course = new ArrayList<Course>();
	NEXTuniv next = NEXTuniv.getInstance();
	
	// 과목의 majorid와 전공의 id가 일치하면 해당전공 과목으로 list에 포함시킴
	public void getMajorCourse(){
		for(int i = 0; i<next.getCourseList().size(); i++){
			Course c = next.getCourseList().get(i);
			if(c.majorId == this.majorId){
				course.add(c);
			}
		}
	}
	
	@Override // 해당전공 학생들의 list
	public void getStudentList() {
		for(int i = 0; i < next.getStudentList().size(); i++){
			Student s = next.getStudentList().get(i);
			if(s.getMajorId() == this.majorId){
				student.add(s);
			}
		}
		
	}

	@Override // id setting
	public int initId() {
		return majorId = defaultMajorId++;
	}

	
	
}
