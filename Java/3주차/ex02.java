
public class ex02 {

	public static void main(String[] args) {
		
		for(int i=2; i<10; i++) {
			
			for(int j=1; j<10; j++) {
				System.out.printf("%dx%d=%-2d   ",i,j,(i*j));
				if(i==j)
					break;
			}
			System.out.println(" ");
		}
	}
}
