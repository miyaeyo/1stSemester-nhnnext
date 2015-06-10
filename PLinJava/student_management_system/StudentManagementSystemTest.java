package assignment3;

public class StudentManagementSystemTest {

	public static void main(String[] args) {
		NEXTuniv next = NEXTuniv.getInstance();
		Major english = English.getInstance();
		Major mathematics = Mathematics.getInstance();
		Course englishClass = EnglishClass.getInstance();
		Course mathClass = MathClass.getInstance(); 
		next.addMajor(english);
		next.addMajor(mathematics);
		next.addCourse(englishClass);
		next.addCourse(mathClass);
		
		Student std1 = new Student(141213, "이승기", "수학");
		Student std2 = new Student(141518, "김수현", "영어");
		Student std3 = new Student(141230, "주 원", "수학");
		Student std4 = new Student(141255, "김우빈", "수학");
		Student std5 = new Student(141590, "이민호", "영어");
		next.addStudent(std1);
		next.addStudent(std2);
		next.addStudent(std3);
		next.addStudent(std4);
		next.addStudent(std5);
		std1.setScore("수학", 95);std1.setScore("영어", 20);
		std2.setScore("수학", 90);std2.setScore("영어", 100);
		std3.setScore("수학", 76);std3.setScore("영어", 60);
		std4.setScore("수학", 85);std4.setScore("영어", 89);
		std5.setScore("수학", 90);std5.setScore("영어", 95);
		
	
		Reporting report = new Reporting();
		report.setReport();
		report.report();
		
		
		

	}

}
