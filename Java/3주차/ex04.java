
public class ex04 {

	public static void main(String[] args) {
		int number1=12321, number2=1232, result;
		
		result = pailndrome(number1);
		resultPrint(number1,result);
		
		result = pailndrome(number2);
		resultPrint(number2,result);
	}
	
	public static void resultPrint(int num1,int num2) {
		if(num1 == num2)
			System.out.println(num2 + "�� ȸ���� �Դϴ�.");
		else
			System.out.println(num2 + "�� ȸ������ �ƴմϴ�.");	
	}
	
	public static int pailndrome(int num) {
		
		int tmp = num;   
		int result =0;
		
		while(tmp!=0) {
		result = result*10 + tmp%10;
		tmp/=10;  
		}
		
		return result;
	}

}
