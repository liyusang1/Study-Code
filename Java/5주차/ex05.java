
public class ex05 {

	public static void main(String[] args) {
		Exid a =new Exid();
		Exid b =new Exid();
		Exid.setStep(3);
		Exid c =new Exid();
		Exid d =new Exid();
		
		System.out.println("a�� �ĺ� ��ȣ : "+ a.getId());
		System.out.println("b�� �ĺ� ��ȣ : "+ b.getId());
		System.out.println("c�� �ĺ� ��ȣ : "+ c.getId());
		System.out.println("d�� �ĺ� ��ȣ : "+ d.getId());
		Exid.setStep(1);
		int max = Exid.getMaxId();
		System.out.println("������ �ο��� �ĺ���ȣ  : "+ max);
		System.out.println("������ �ο��� �ĺ���ȣ  : "+ (max+Exid.getStep()));

	}

}

class Exid{
	
	private static int counter = 0;
	private static int step=1;
	private int id=0;
	
	Exid(){
		counter +=step;
		id = counter;
	}
	public int getId() {
		return id;
	}
	public static int getStep() {
		return step;
	}
	public static void setStep(int s){
		step = s;
	}
	public static int getMaxId() {
		return counter;
	}
	
	
	
	
	
}
