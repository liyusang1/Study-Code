
public class ex05 {

	public static void main(String[] args) {
		
		Calc c = new Calc();	
		c.setValue(2, 5, '+');
		c.result();
		
		c.setValue(2, 5, '$');
		c.result();
		
		c.setValue(2, 5, '-');
		c.result();
		
		c.setValue(2, 5, '*');
		c.result();
		
		c.setValue(2, 5, '/');
		c.result();
	}
}

class Calc{
	
	private int result;
	private boolean check = true;
	
	public void add(int a,int b) {
		result = a+b;
	}
	
	public void sub(int a,int b) {
		result = a-b;
	}
	
	public void mul(int a,int b) {
		result = a*b;
	}
	
	public void div(int a,int b) {
		result = a/b;
	}
	
	public void setValue(int a, int b,char value){
		
		check=true;
		switch(value) {
		case '+':
			add(a,b);
			break;
		case '-':
			sub(a,b);
			break;
		case '*':
			mul(a,b);
			break;
		case '/':
			div(a,b);
			break;
		default:
			check=false;
			break;
		}
	}
	
	public void result() {
	if(check==false)
		System.out.println("잘못된 연산자 입니다.");
	else
		System.out.printf("result = %d\n",result);
	}	
}