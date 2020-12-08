
enum Company{
	AMAZON(170), APPLE(165), GOOGLE(136), FACEBOOK(101),MICROSOFT(91);
	
    int value;
    
    Company(int value){
    	this.value=value;
    }
    
    public int getValue(){
        return value;
    }
}

public class ex01 {
	
	static void showAll(String...vargs) {
		
		for(String s: vargs) {
		if(s.equals("FACEBOOK"))
			System.out.printf("4�� FACEBOOK �����ġ %d��\n",Company.FACEBOOK.getValue());
		
		else if(s.equals("AMAZON"))
			System.out.printf("1�� AMAZON �����ġ %d��\n",Company.AMAZON.getValue());
		
		else if(s.equals("APPLE"))
			System.out.printf("2�� APPLE �����ġ %d��\n",Company.APPLE.getValue());
		
		else if(s.equals("GOOGLE"))
			System.out.printf("3�� GOOGLE �����ġ %d��\n",Company.GOOGLE.getValue());
		
		else if(s.equals("MICROSOFT"))
			System.out.printf("5�� MICROSOFT �����ġ %d��\n",Company.MICROSOFT.getValue());
		}
		
			System.out.printf("���� �����ġ Top5 �߿��� %d�� ����� �ֽ��ϴ�.",vargs.length);
			System.out.println("");
			System.out.println("");
	}

	public static void main(String[] args) {
		showAll("FACEBOOK");
		showAll("APPLE", "MICROSOFT");
		showAll("AMAZON", "APPLE", "GOOGLE");
	}
}
