import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.TreeSet;
import java.util.List;
import java.util.InputMismatchException;

//소프트웨어학부 2016317028 이유상
public class project1 {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		
		System.out.print("# 아르바이트 월급 입력 : ");
		
	try { //예외처리를 이용하여 잘못된 값이 입력되었을때, 오류를 출력하면서 프로그램 종료
			
		Scanner getSalary=new Scanner(System.in); //사용자로부터 아르바이트 월급을 입력받음.
		double salary=getSalary.nextDouble();
		
		
		//while문을 실행하면서 사용자가 프로그램을 종료할 때 까지 계속해서 작동 됨.  
		while(true) {
			double gugminYeongeum; //국민보험을 저장하기 위한 변수
			double geongangboheom; //건강보험을 저장하기 위한 변수
			double goyongboheom; //고용보험을 저장하기 위한 변수
			 
			System.out.println("### 아르바이트 월급 계산기 ###");
			System.out.println("# 1. 국민연금 계산");
			System.out.println("# 2. 건강보험 계산");
			System.out.println("# 3. 고용보험 계산");
			System.out.println("# 4. 한번에 계산");
			System.out.println("# 5. 월급 재입력");
			System.out.println("# 0. 종료");
			System.out.print("-> enter number : ");
			
			
			Scanner sc1=new Scanner(System.in); //while문을 실행하면서 사용자가 어떤 숫자를 입력하느냐에 따라 다른 기능이 작동 됨.
			int selectNum = sc1.nextInt();
			
			if(selectNum == 1 ) {
				
				System.out.println("###############");
				TakeHomePay1<Double> pay1=new TakeHomePay1<Double>(salary); //TakeHomepay1클래스를 이용해 객체를 생성, 이 객체가 국민연금 계산을 해줄것임
				pay1.calculate(); //국민연금을 계산
				
				gugminYeongeum = pay1.calculatedTax();
				pay1.print();
				
				System.out.println(" ");
			}
			
			else if(selectNum == 2 ) {

				System.out.println("###############");
				TakeHomePay2<Double> pay2=new TakeHomePay2<Double>(salary); //TakeHomepay2클래스를 이용해 객체를 생성, 이 객체가 건강보험 계산을 해줄것임
				pay2.calculate(); //건강보험을 계산
				
				geongangboheom = pay2.calculatedTax();
				pay2.print();
				
				System.out.println(" ");	
			}
			
			else if(selectNum == 3 ) {

				System.out.println("###############");
				TakeHomePay3<Double> pay3=new TakeHomePay3<Double>(salary); //TakeHomepay3클래스를 이용해 객체를 생성, 이 객체가 고용보험 계산을 해줄것임
				pay3.calculate(); //고용보험을 계산
				
				goyongboheom = pay3.calculatedTax();
				pay3.print();
				
				System.out.println(" ");	
			}
			
			else if(selectNum == 4 ) {
				
				System.out.println("###############");
				TakeHomePay1<Double> pay1=new TakeHomePay1<Double>(salary); //TakeHomepay1클래스를 이용해 객체를 생성, 이 객체가 국민연금 계산을 해줄것임
				pay1.calculate(); //국민연금을 계산
				TakeHomePay2<Double> pay2=new TakeHomePay2<Double>(salary); //TakeHomepay2클래스를 이용해 객체를 생성, 이 객체가 건강보험 계산을 해줄것임
				pay2.calculate(); //건강보험을 계산
				TakeHomePay3<Double> pay3=new TakeHomePay3<Double>(salary); //TakeHomepay3클래스를 이용해 객체를 생성, 이 객체가 고용보험 계산을 해줄것임
				pay3.calculate(); //고용보험을 계산
				
		
				double taxSum = 0; // 모든 아르바이트의 세금 비용을 더해서 저장하기 위한 변수
				
				gugminYeongeum = pay1.calculatedTax();
				geongangboheom = pay2.calculatedTax();
				goyongboheom = pay3.calculatedTax();
				
				List<Tax> list = new ArrayList<>();   //ArrayList를 생성하고 list에 각각에 세금에 대한 이름과 금액을 저장 함
				list.add(new Tax("국민 연금", gugminYeongeum));
				list.add(new Tax("건강 보험", geongangboheom));
				list.add(new Tax("고용 보험", goyongboheom));
				
				TreeSet<Double> set = new TreeSet<Double>(); //TreeSet을 생성하고 각각 세금의 금액을 TreeSet에 순차적으로 정렬 함
				set.add(gugminYeongeum);
				set.add(geongangboheom);
				set.add(goyongboheom);
				
			    Collections.sort(list, (s1, s2) ->s2.tax-s1.tax);  //람다 표현식을 이용하여 list에 정렬된 각각의 세금을 비용이 높은것을 우선으로 정렬하고 iterator를 이용하여 이를 출력
				System.out.println("#### 세금을 비용 순서대로 출력 ####");
				Iterator<Tax> iter = list.iterator();
				while(iter.hasNext()) {
					System.out.println(iter.next());
				}
				
				System.out.println(" ");
				
				Collections.sort(list, (s1, s2) -> s1.name.compareToIgnoreCase(s2.name));  //람다 표현식을 이용하여 list에 정렬된 각각의 세금을 이름 순서대로 우선으로 정렬하고 iterator를 이용하여 이를 출력
				System.out.println("#### 세금을 이름 순서대로 출력 ####");
				iter = list.iterator();
				while(iter.hasNext()) {
					System.out.println(iter.next());
				}
				
				System.out.println(" ");
				
				for(Iterator<Double> setIter = set.iterator(); setIter.hasNext();) { //set에 저장된 세금을 Iterator를 사용하여 전부 확인하면서 taxSum에 모든 세금의 합을 기록 한다.
					taxSum+=setIter.next();
				}
				
				calculateTaxAll calculateAllTax; //세금을 제외한 아르바이트 월급 실수령액을 계산하기 위한 함수형 인터페이스
				calculateAllTax = (a,b,c,d) -> {return a-b-c-d;}; //람다표현식을 이용하여 아르바이트 월급에서 세금을 제외한 금액을 출력하도록 한다.
			
				System.out.println("비용이 가장 높은 세금 : "+set.last());  //set에 있는 메소드를 활용하여 비용이 가장 높은 세금 출력
				System.out.println("비용이 가장 낮은 세금 : "+set.first());  //set에 있는 메소드를 활용하여 비용이 가장 낮은 세금 출력
				System.out.println("세금의 합 : "+taxSum);
				
				System.out.println("수령 하게 될 아르바이트 월급 : "+calculateAllTax.calculate((int)salary,(int)gugminYeongeum , (int)geongangboheom, (int)goyongboheom));
				System.out.println(" ");	
			}
			
			else if(selectNum == 5 ) { 
				System.out.println("###############");
				System.out.print("# 아르바이트 월급 입력 : ");
				Scanner getSalary2=new Scanner(System.in);  //사용자로부터 아르바이트 월급을 다시 입력받고, 이를 다시 저장함.
				salary=getSalary2.nextDouble();
				System.out.println(" ");
			}
			
			else if(selectNum == 0 ) 
				break;
		}
		
	}
		catch(InputMismatchException e) { //예외처리를 이용하여 잘못된 값이 입력되었을때, 오류를 출력하면서 프로그램 종료
			System.out.println("# 잘못된 입력!!");
		}
		
		System.out.println("###############");
		System.out.println("# 시스템 종료 !");

	}
}

interface calculateTax{
	public void print();    //계산한 세금을 출력하는 함수
	public void calculate(); //각각의 세금을 계산하는 함수
	public double calculatedTax(); //계산된 세금의 비용을 얻는 함수
	
}

@FunctionalInterface  //세금을 제외한 아르바이트 월급 실수령액을 계산하기 위한 함수형 인터페이스
interface calculateTaxAll{
	int calculate(int salary,int gugminYeongeum,int geongangboheom,int goyongboheom);
}

//국민연금을 계산하기 위한 클래스
class TakeHomePay1<T extends Number> implements calculateTax{   
	
	private T salary;            //사용자로부터 아르바이트 월급을 입력받음
	private double calculatedSalary;  //세후 수령액을 저장
	private double gugminYeongeum; // 사용자로부터 입력받은 월급의 국민연금을 계산
	private final double gugminYeongeumTax = 0.045; //아르바이트 월급에서 국민연금의 세금 비율
	
	TakeHomePay1(T salary){
		this.salary=salary;
	}
	
	@Override
	public void calculate() {
		gugminYeongeum = salary.doubleValue() * gugminYeongeumTax;
		calculatedSalary = salary.doubleValue() - gugminYeongeum;
	}
	
	@Override
	public double calculatedTax() {
		return gugminYeongeum;
	}
	
	@Override
	public void print() {
		System.out.println("# 국민 연금 : "+gugminYeongeum);
		System.out.println("# 국민 연금을 제외한 아르바이트 월급 수령액 : "+calculatedSalary);
	}
}

//건강보험을 계산하기 위한 클래스
class TakeHomePay2<T extends Number> implements calculateTax{   
	
	private T salary;           //사용자로부터 아르바이트 월급을 입력받음
	private double calculatedSalary;  //세후 수령액을 저장
	private double geongangboheom; // 사용자로부터 입력받은 월급의 건강보험비를 계산
	private final double geongangboheomTax = 0.0335; //아르바이트 월급에서 건강보험의 세금 비율
	
	TakeHomePay2(T salary){
		this.salary=salary;
	}
	
	@Override
	public void calculate() {
		geongangboheom = salary.doubleValue() * geongangboheomTax;
		calculatedSalary = salary.doubleValue() - geongangboheom;
	}
	
	@Override
	public double calculatedTax() {
		return geongangboheom;
	}
	
	@Override
	public void print() {
		System.out.println("# 건강 보험  : "+geongangboheom);
		System.out.println("# 건강 보험을 제외한 아르바이트 월급 수령액 : "+calculatedSalary);
	}
}

//고용보험을 계산하기 위한 클래스
class TakeHomePay3<T extends Number> implements calculateTax{   
	
	private T salary;          //사용자로부터 아르바이트 월급을 입력받음
	private double calculatedSalary;  //세후 수령액을 저장
	private double goyongboheom; // 사용자로부터 입력받은 월급의 고용보험비를 계산
	private final double goyongboheomTax = 0.008; //아르바이트 월급에서 고용보험의 세금 비율
	
	TakeHomePay3(T salary){
		this.salary=salary;
	}
	
	@Override
	public void calculate() {
		goyongboheom = salary.doubleValue() * goyongboheomTax;
		calculatedSalary = salary.doubleValue() - goyongboheom;
	}
	
	@Override
	public double calculatedTax() {
		return goyongboheom;
	}
	
	@Override
	public void print() {
		System.out.println("# 고용 보험  : "+goyongboheom);
		System.out.println("# 고용 보험을 제외한 아르바이트 월급 수령액 : "+calculatedSalary);
	}
}

//아르바이트 월급의 각각 세금들을 이름으로 저장해서 보관하기 위한 클래스
class Tax {
	
	 String name;
	 double salaryTax;
	 int tax;
	 
	 public Tax(String name, double salaryTax) {
		 this.name = name; 
		 this.salaryTax = salaryTax;
		 tax =(int) salaryTax;
		 }
	 
	 public double returnTax() {
		 return salaryTax;
	 }
	 
	 public String toString() { return name + " : " + salaryTax; }
}
