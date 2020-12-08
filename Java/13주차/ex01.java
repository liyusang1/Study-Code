
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
			System.out.printf("4위 FACEBOOK 기업가치 %d조\n",Company.FACEBOOK.getValue());
		
		else if(s.equals("AMAZON"))
			System.out.printf("1위 AMAZON 기업가치 %d조\n",Company.AMAZON.getValue());
		
		else if(s.equals("APPLE"))
			System.out.printf("2위 APPLE 기업가치 %d조\n",Company.APPLE.getValue());
		
		else if(s.equals("GOOGLE"))
			System.out.printf("3위 GOOGLE 기업가치 %d조\n",Company.GOOGLE.getValue());
		
		else if(s.equals("MICROSOFT"))
			System.out.printf("5위 MICROSOFT 기업가치 %d조\n",Company.MICROSOFT.getValue());
		}
		
			System.out.printf("세계 기업가치 Top5 중에서 %d개 기업이 있습니다.",vargs.length);
			System.out.println("");
			System.out.println("");
	}

	public static void main(String[] args) {
		showAll("FACEBOOK");
		showAll("APPLE", "MICROSOFT");
		showAll("AMAZON", "APPLE", "GOOGLE");
	}
}
