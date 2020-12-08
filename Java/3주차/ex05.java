
public class ex05 {

	public static void main(String[] args) {
		
		System.out.println("f(0) = "+recursion(0));
		System.out.println("f(1) = "+recursion(1));
		System.out.println("f(2) = "+recursion(2));
		System.out.println("f(3) = "+recursion(3));
		System.out.println("f(4) = "+recursion(4));
		System.out.println("f(5) = "+recursion(5));

	}
	
	static int recursion(int num) {
		
		if(num==0)
			return 1;
		else 
			return 2*recursion(num-1)+1;
		
	}

}
