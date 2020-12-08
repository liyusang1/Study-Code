import java.util.Scanner;

public class ex03 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		MonthSchedule ms = new MonthSchedule(30);
		System.out.println("�̹��� ������ ���� ���α׷�.");
		while(true) {
			System.out.print("����(�Է�:1, ����:2 ,������ :3) >>");
			int menu = scanner.nextInt();
			switch(menu) {
			case 1 :ms.input(); break;
			case 2 :ms.view(); break;
			case 3 :ms.finish(); return;
			default : System.out.println("�߸��Է��ϼ̽��ϴ�.");
			}
			System.out.println();
		}
	}
}

class Day{
	private String work;
	
	public void set(String work) {
		this.work = work;
	}
	
	public String get() {
		return work;
	}
	
	public void show() {
		if(work ==null)
			System.out.println("�����ϴ�.");
		else
			System.out.println(work +"�Դϴ�.");
	}	
}

class MonthSchedule{
	
	private Day[] day;
	private int date;
	
	MonthSchedule(int date){
		this.date=date;
		day =new Day[date];
		for(int i=0; i<date; i++)
			day[i]=new Day();
	}
	
	void input() {
		System.out.print("��¥(1~"+date+")?");
		Scanner sc1=new Scanner(System.in);
		int num=sc1.nextInt();
		if(day[num-1].get()!=null) {
			System.out.println("������ �̹� �ֽ��ϴ�.");
			return;
		}	
		System.out.print("����(��ĭ�����Է�)?");
		Scanner sc2=new Scanner(System.in);
		String str1=sc2.nextLine();
		day[num-1].set(str1);	
	}	
	
	void view() {
		System.out.print("��¥(1~"+date+")?");
		Scanner sc1=new Scanner(System.in);
		int num=sc1.nextInt();
		System.out.print(num+"���� ������ ");
		day[num-1].show();	
	}
	
	void finish() {
		System.out.println("���α׷��� �����մϴ�");
	}
}
