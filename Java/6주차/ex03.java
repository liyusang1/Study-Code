import java.util.Scanner;

public class ex03 {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		MonthSchedule ms = new MonthSchedule(30);
		System.out.println("이번달 스케쥴 관리 프로그램.");
		while(true) {
			System.out.print("할일(입력:1, 보기:2 ,끝내기 :3) >>");
			int menu = scanner.nextInt();
			switch(menu) {
			case 1 :ms.input(); break;
			case 2 :ms.view(); break;
			case 3 :ms.finish(); return;
			default : System.out.println("잘못입력하셨습니다.");
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
			System.out.println("없습니다.");
		else
			System.out.println(work +"입니다.");
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
		System.out.print("날짜(1~"+date+")?");
		Scanner sc1=new Scanner(System.in);
		int num=sc1.nextInt();
		if(day[num-1].get()!=null) {
			System.out.println("할일이 이미 있습니다.");
			return;
		}	
		System.out.print("할일(빈칸없이입력)?");
		Scanner sc2=new Scanner(System.in);
		String str1=sc2.nextLine();
		day[num-1].set(str1);	
	}	
	
	void view() {
		System.out.print("날짜(1~"+date+")?");
		Scanner sc1=new Scanner(System.in);
		int num=sc1.nextInt();
		System.out.print(num+"일의 할일은 ");
		day[num-1].show();	
	}
	
	void finish() {
		System.out.println("프로그램을 종료합니다");
	}
}
