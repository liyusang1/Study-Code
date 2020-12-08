import java.util.Scanner;
import java.util.InputMismatchException;
import java.lang.ArithmeticException;

public class ex03 {

	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		try {
		System.out.print("x값 : ");
		int x =scan.nextInt();
		
		System.out.print("y값 : ");
		int y =scan.nextInt();
		
		System.out.println("x * y = " + mul(x,y));
		System.out.println("x / y = " + div(x,y));
		}catch(InputMismatchException | ArithmeticException e) {
			e.printStackTrace();
		}
		System.out.println("프로그램을 종료합니다");
		scan.close();
		
	}
	static int mul(int x,int y)  {
		return x*y;
	}
	static int div(int x,int y)  {
		return x/y;
	}
}
