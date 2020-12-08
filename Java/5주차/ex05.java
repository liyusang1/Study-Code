
public class ex05 {

	public static void main(String[] args) {
		Exid a =new Exid();
		Exid b =new Exid();
		Exid.setStep(3);
		Exid c =new Exid();
		Exid d =new Exid();
		
		System.out.println("a의 식별 번호 : "+ a.getId());
		System.out.println("b의 식별 번호 : "+ b.getId());
		System.out.println("c의 식별 번호 : "+ c.getId());
		System.out.println("d의 식별 번호 : "+ d.getId());
		Exid.setStep(1);
		int max = Exid.getMaxId();
		System.out.println("마지막 부여한 식별번호  : "+ max);
		System.out.println("다음에 부여할 식별번호  : "+ (max+Exid.getStep()));

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
