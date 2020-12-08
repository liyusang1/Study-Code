
public class ex03 {

	public static void main(String[] args) {
		
		for(int i=0; i<5; i++) {
	
		char a='a';
		System.out.print(a);
		if(i==4) {
			System.out.println(" ");
			continue;
		}
		
		a='b';
		System.out.print(a);
		
		if(i==3) {
			System.out.println(" ");
			continue;
		}
		
		a='c';
		System.out.print(a);
		
		if(i==2) {
			System.out.println(" ");
			continue;
		}
		
		a='d';
		System.out.print(a);
		
		if(i==1) {
			System.out.println(" ");
			continue;
		}
		
		a='e';
		System.out.print(a);
		System.out.println(" ");
		}
	}
}
