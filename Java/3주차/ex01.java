
public class ex01 {

	public static void main(String[] args) {
		
		int countEight= 0;
		int countNine = 0;
		
		for(int i=1; i<=100;i++) {
			if((i%9==0) && (i%8==0))
				break;
			
			else if(i%8==0)
				countEight++;
			
			else if(i%9==0)
				countNine++;
		}
		
		System.out.println("8의 배수  : "+countEight);
		System.out.println("9의 배수  : "+countNine);
	}

}
