package assignment3;


public class Reporting { // reporting class
	NEXTuniv next = NEXTuniv.getInstance();
	StringBuilder report = new StringBuilder();
	
	public void setReport(){
		for(int i = 0; i<next.getStudentList().size(); i++){
			Student s = next.getStudentList().get(i);
			report.append(s.getStudentName());report.append(" | ");
			report.append(s.getStudentId());report.append(" | ");
			report.append(s.getMajor());report.append("  |  ");
			for(int j = 0; j< s.getGradeList().size(); j++){
				Grade g = s.getGradeList().get(j);
				report.append(g.getGrade());report.append("  |  ");
			}
			report.append("\n");
		}
	}
	
	public void report(){
		System.out.println("�� �� |  ��  ��  | �� �� | �� �� | �� �� |");
		System.out.println(report);
	}
	
}
