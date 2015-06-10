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
		
		Student std1 = new Student(141213, "�̽±�", "����");
		Student std2 = new Student(141518, "�����", "����");
		Student std3 = new Student(141230, "�� ��", "����");
		Student std4 = new Student(141255, "����", "����");
		Student std5 = new Student(141590, "�̹�ȣ", "����");
		next.addStudent(std1);
		next.addStudent(std2);
		next.addStudent(std3);
		next.addStudent(std4);
		next.addStudent(std5);
		std1.setScore("����", 95);std1.setScore("����", 20);
		std2.setScore("����", 90);std2.setScore("����", 100);
		std3.setScore("����", 76);std3.setScore("����", 60);
		std4.setScore("����", 85);std4.setScore("����", 89);
		std5.setScore("����", 90);std5.setScore("����", 95);
		
	
		Reporting report = new Reporting();
		report.setReport();
		report.report();
		
		
		

	}

}
