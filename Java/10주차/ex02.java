import java.util.Random;

public class ex02 {

	public static void main(String[] args) {
		
		Random rand = new Random();
		int[] count=new int[10];
		
		for(int i=0; i<100; i++) {
			int number = rand.nextInt(9);
				count[number]++;
			System.out.print(number);
		}
		System.out.println("");
		
		for(int i=0; i<9; i++) {
			System.out.print(i+"°³¼ö:");
			for(int j=0; j<count[i]; j++) {
				System.out.print("*");
			}
			System.out.println(" ");
		}

	}

}
