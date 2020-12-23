import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.TreeSet;
import java.util.List;
import java.util.InputMismatchException;

//����Ʈ�����к� 2016317028 ������
public class project1 {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		
		System.out.print("# �Ƹ�����Ʈ ���� �Է� : ");
		
	try { //����ó���� �̿��Ͽ� �߸��� ���� �ԷµǾ�����, ������ ����ϸ鼭 ���α׷� ����
			
		Scanner getSalary=new Scanner(System.in); //����ڷκ��� �Ƹ�����Ʈ ������ �Է¹���.
		double salary=getSalary.nextDouble();
		
		
		//while���� �����ϸ鼭 ����ڰ� ���α׷��� ������ �� ���� ����ؼ� �۵� ��.  
		while(true) {
			double gugminYeongeum; //���κ����� �����ϱ� ���� ����
			double geongangboheom; //�ǰ������� �����ϱ� ���� ����
			double goyongboheom; //��뺸���� �����ϱ� ���� ����
			 
			System.out.println("### �Ƹ�����Ʈ ���� ���� ###");
			System.out.println("# 1. ���ο��� ���");
			System.out.println("# 2. �ǰ����� ���");
			System.out.println("# 3. ��뺸�� ���");
			System.out.println("# 4. �ѹ��� ���");
			System.out.println("# 5. ���� ���Է�");
			System.out.println("# 0. ����");
			System.out.print("-> enter number : ");
			
			
			Scanner sc1=new Scanner(System.in); //while���� �����ϸ鼭 ����ڰ� � ���ڸ� �Է��ϴ��Ŀ� ���� �ٸ� ����� �۵� ��.
			int selectNum = sc1.nextInt();
			
			if(selectNum == 1 ) {
				
				System.out.println("###############");
				TakeHomePay1<Double> pay1=new TakeHomePay1<Double>(salary); //TakeHomepay1Ŭ������ �̿��� ��ü�� ����, �� ��ü�� ���ο��� ����� ���ٰ���
				pay1.calculate(); //���ο����� ���
				
				gugminYeongeum = pay1.calculatedTax();
				pay1.print();
				
				System.out.println(" ");
			}
			
			else if(selectNum == 2 ) {

				System.out.println("###############");
				TakeHomePay2<Double> pay2=new TakeHomePay2<Double>(salary); //TakeHomepay2Ŭ������ �̿��� ��ü�� ����, �� ��ü�� �ǰ����� ����� ���ٰ���
				pay2.calculate(); //�ǰ������� ���
				
				geongangboheom = pay2.calculatedTax();
				pay2.print();
				
				System.out.println(" ");	
			}
			
			else if(selectNum == 3 ) {

				System.out.println("###############");
				TakeHomePay3<Double> pay3=new TakeHomePay3<Double>(salary); //TakeHomepay3Ŭ������ �̿��� ��ü�� ����, �� ��ü�� ��뺸�� ����� ���ٰ���
				pay3.calculate(); //��뺸���� ���
				
				goyongboheom = pay3.calculatedTax();
				pay3.print();
				
				System.out.println(" ");	
			}
			
			else if(selectNum == 4 ) {
				
				System.out.println("###############");
				TakeHomePay1<Double> pay1=new TakeHomePay1<Double>(salary); //TakeHomepay1Ŭ������ �̿��� ��ü�� ����, �� ��ü�� ���ο��� ����� ���ٰ���
				pay1.calculate(); //���ο����� ���
				TakeHomePay2<Double> pay2=new TakeHomePay2<Double>(salary); //TakeHomepay2Ŭ������ �̿��� ��ü�� ����, �� ��ü�� �ǰ����� ����� ���ٰ���
				pay2.calculate(); //�ǰ������� ���
				TakeHomePay3<Double> pay3=new TakeHomePay3<Double>(salary); //TakeHomepay3Ŭ������ �̿��� ��ü�� ����, �� ��ü�� ��뺸�� ����� ���ٰ���
				pay3.calculate(); //��뺸���� ���
				
		
				double taxSum = 0; // ��� �Ƹ�����Ʈ�� ���� ����� ���ؼ� �����ϱ� ���� ����
				
				gugminYeongeum = pay1.calculatedTax();
				geongangboheom = pay2.calculatedTax();
				goyongboheom = pay3.calculatedTax();
				
				List<Tax> list = new ArrayList<>();   //ArrayList�� �����ϰ� list�� ������ ���ݿ� ���� �̸��� �ݾ��� ���� ��
				list.add(new Tax("���� ����", gugminYeongeum));
				list.add(new Tax("�ǰ� ����", geongangboheom));
				list.add(new Tax("��� ����", goyongboheom));
				
				TreeSet<Double> set = new TreeSet<Double>(); //TreeSet�� �����ϰ� ���� ������ �ݾ��� TreeSet�� ���������� ���� ��
				set.add(gugminYeongeum);
				set.add(geongangboheom);
				set.add(goyongboheom);
				
			    Collections.sort(list, (s1, s2) ->s2.tax-s1.tax);  //���� ǥ������ �̿��Ͽ� list�� ���ĵ� ������ ������ ����� �������� �켱���� �����ϰ� iterator�� �̿��Ͽ� �̸� ���
				System.out.println("#### ������ ��� ������� ��� ####");
				Iterator<Tax> iter = list.iterator();
				while(iter.hasNext()) {
					System.out.println(iter.next());
				}
				
				System.out.println(" ");
				
				Collections.sort(list, (s1, s2) -> s1.name.compareToIgnoreCase(s2.name));  //���� ǥ������ �̿��Ͽ� list�� ���ĵ� ������ ������ �̸� ������� �켱���� �����ϰ� iterator�� �̿��Ͽ� �̸� ���
				System.out.println("#### ������ �̸� ������� ��� ####");
				iter = list.iterator();
				while(iter.hasNext()) {
					System.out.println(iter.next());
				}
				
				System.out.println(" ");
				
				for(Iterator<Double> setIter = set.iterator(); setIter.hasNext();) { //set�� ����� ������ Iterator�� ����Ͽ� ���� Ȯ���ϸ鼭 taxSum�� ��� ������ ���� ��� �Ѵ�.
					taxSum+=setIter.next();
				}
				
				calculateTaxAll calculateAllTax; //������ ������ �Ƹ�����Ʈ ���� �Ǽ��ɾ��� ����ϱ� ���� �Լ��� �������̽�
				calculateAllTax = (a,b,c,d) -> {return a-b-c-d;}; //����ǥ������ �̿��Ͽ� �Ƹ�����Ʈ ���޿��� ������ ������ �ݾ��� ����ϵ��� �Ѵ�.
			
				System.out.println("����� ���� ���� ���� : "+set.last());  //set�� �ִ� �޼ҵ带 Ȱ���Ͽ� ����� ���� ���� ���� ���
				System.out.println("����� ���� ���� ���� : "+set.first());  //set�� �ִ� �޼ҵ带 Ȱ���Ͽ� ����� ���� ���� ���� ���
				System.out.println("������ �� : "+taxSum);
				
				System.out.println("���� �ϰ� �� �Ƹ�����Ʈ ���� : "+calculateAllTax.calculate((int)salary,(int)gugminYeongeum , (int)geongangboheom, (int)goyongboheom));
				System.out.println(" ");	
			}
			
			else if(selectNum == 5 ) { 
				System.out.println("###############");
				System.out.print("# �Ƹ�����Ʈ ���� �Է� : ");
				Scanner getSalary2=new Scanner(System.in);  //����ڷκ��� �Ƹ�����Ʈ ������ �ٽ� �Է¹ް�, �̸� �ٽ� ������.
				salary=getSalary2.nextDouble();
				System.out.println(" ");
			}
			
			else if(selectNum == 0 ) 
				break;
		}
		
	}
		catch(InputMismatchException e) { //����ó���� �̿��Ͽ� �߸��� ���� �ԷµǾ�����, ������ ����ϸ鼭 ���α׷� ����
			System.out.println("# �߸��� �Է�!!");
		}
		
		System.out.println("###############");
		System.out.println("# �ý��� ���� !");

	}
}

interface calculateTax{
	public void print();    //����� ������ ����ϴ� �Լ�
	public void calculate(); //������ ������ ����ϴ� �Լ�
	public double calculatedTax(); //���� ������ ����� ��� �Լ�
	
}

@FunctionalInterface  //������ ������ �Ƹ�����Ʈ ���� �Ǽ��ɾ��� ����ϱ� ���� �Լ��� �������̽�
interface calculateTaxAll{
	int calculate(int salary,int gugminYeongeum,int geongangboheom,int goyongboheom);
}

//���ο����� ����ϱ� ���� Ŭ����
class TakeHomePay1<T extends Number> implements calculateTax{   
	
	private T salary;            //����ڷκ��� �Ƹ�����Ʈ ������ �Է¹���
	private double calculatedSalary;  //���� ���ɾ��� ����
	private double gugminYeongeum; // ����ڷκ��� �Է¹��� ������ ���ο����� ���
	private final double gugminYeongeumTax = 0.045; //�Ƹ�����Ʈ ���޿��� ���ο����� ���� ����
	
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
		System.out.println("# ���� ���� : "+gugminYeongeum);
		System.out.println("# ���� ������ ������ �Ƹ�����Ʈ ���� ���ɾ� : "+calculatedSalary);
	}
}

//�ǰ������� ����ϱ� ���� Ŭ����
class TakeHomePay2<T extends Number> implements calculateTax{   
	
	private T salary;           //����ڷκ��� �Ƹ�����Ʈ ������ �Է¹���
	private double calculatedSalary;  //���� ���ɾ��� ����
	private double geongangboheom; // ����ڷκ��� �Է¹��� ������ �ǰ������ ���
	private final double geongangboheomTax = 0.0335; //�Ƹ�����Ʈ ���޿��� �ǰ������� ���� ����
	
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
		System.out.println("# �ǰ� ����  : "+geongangboheom);
		System.out.println("# �ǰ� ������ ������ �Ƹ�����Ʈ ���� ���ɾ� : "+calculatedSalary);
	}
}

//��뺸���� ����ϱ� ���� Ŭ����
class TakeHomePay3<T extends Number> implements calculateTax{   
	
	private T salary;          //����ڷκ��� �Ƹ�����Ʈ ������ �Է¹���
	private double calculatedSalary;  //���� ���ɾ��� ����
	private double goyongboheom; // ����ڷκ��� �Է¹��� ������ ��뺸��� ���
	private final double goyongboheomTax = 0.008; //�Ƹ�����Ʈ ���޿��� ��뺸���� ���� ����
	
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
		System.out.println("# ��� ����  : "+goyongboheom);
		System.out.println("# ��� ������ ������ �Ƹ�����Ʈ ���� ���ɾ� : "+calculatedSalary);
	}
}

//�Ƹ�����Ʈ ������ ���� ���ݵ��� �̸����� �����ؼ� �����ϱ� ���� Ŭ����
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
