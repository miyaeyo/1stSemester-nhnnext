package assignment3;

public class Grade {
	private int studentId;
	private String courseName;
	private char grade;
	
	public Grade(int studentId, String courseName, char grade){
		this.studentId = studentId;
		this.courseName = courseName;
		this.grade = grade;
	}

	public int getStudentId() {
		return studentId;
	}
	
	public String getCourseName() {
		return courseName;
	}


	public char getGrade() {
		return grade;
	}

	

}
