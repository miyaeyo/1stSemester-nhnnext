package assignment3;

import java.util.ArrayList;


public class NEXTuniv {
	private static NEXTuniv instance = new NEXTuniv();
	private ArrayList<Student> student  = new ArrayList<Student>();
	private ArrayList<Course> course = new ArrayList<Course>();
	private ArrayList<Major> major = new ArrayList<Major>();
	
	public static NEXTuniv getInstance(){
		if(instance == null){
			instance = new NEXTuniv();
		}
		return instance;
	}
	
	public void addStudent(Student s){
		student.add(s);
	}
	public ArrayList<Student> getStudentList(){
		return student;
	}
	
	public void addCourse(Course c){
		course.add(c);
	}
	public ArrayList<Course> getCourseList(){
		return course;
	}
	
	public void addMajor(Major m){
		major.add(m);
	}
	public ArrayList<Major> getMajorList(){
		return major;
	}
}
