package assignment3;

import java.util.ArrayList;

public class Student {
	private String studentName;
	private int studentId;
	private String major;
	private int majorId;
	private ArrayList<Course> course = new ArrayList<Course>();
	private ArrayList<Grade> grade = new ArrayList<Grade>();
	NEXTuniv next = NEXTuniv.getInstance();
	
	//constructor
	public Student(int studentId, String studentName, String major){
		this.studentId = studentId;
		this.studentName = studentName;
		this.major = major;
		this.majorId = setMajorId();
	}
	//getter 
	public String getStudentName() {
		return studentName;
	}

	public int getStudentId() {
		return studentId;
	}
	
	public String getMajor(){
		return major;
	}
	public ArrayList<Grade> getGradeList(){
		return grade;
	}
	
   
	private int setMajorId(){
		for(int i = 0; i<next.getMajorList().size(); i++){
			Major m = next.getMajorList().get(i);
			if(major.equals(m.majorName)){
				return  m.majorId;
			}
		}
		return 0;
	}
	
	public int getMajorId() {
		return majorId;
	}
	
	public void setScore(String courseName, int score){	
		takeCourse(courseName);
		if(courseName == this.major){
			ScoreForMajor majorScore = ScoreForMajor.getInstance();
			Grade g = new Grade(this.studentId, courseName, majorScore.getGrade(score));
			grade.add(g);
		}
		else{
			ScoreForNonMajor nonmajorScore = ScoreForNonMajor.getInstance();
			Grade g = new Grade(this.studentId, courseName,nonmajorScore.getGrade(score));
			grade.add(g);
		}
		
	}
	
	private void takeCourse(String courseName){ // 학생이 듣는 과목 list setup
		for(int i = 0; i<next.getCourseList().size(); i++){
			Course c = next.getCourseList().get(i);
			if(courseName == c.courseName){
				course.add(c);
			}
		}
	}
	
	public ArrayList<Course> getStudentCourse(){
		return course;
	}
	
	
	
}
