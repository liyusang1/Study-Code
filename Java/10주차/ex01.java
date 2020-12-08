import java.util.StringTokenizer;

public class ex01 {

	public static void main(String[] args) {
		String s1 = "동해물과 백두산이 마르고 닳도록";
		String s2 = "2020/11/03";
		String s3 = "2020년11월03일";
		
		StringTokenizer token1 =new StringTokenizer(s1," ");
		StringTokenizer token2 =new StringTokenizer(s2,"/");
		StringTokenizer token3 =new StringTokenizer(s3,"년월일");
		
		System.out.print("s1 count : ");
		int count=token1.countTokens();
		System.out.println(token1.countTokens());
		for(int i=0; i<count; i++)
			System.out.println(token1.nextElement());
		System.out.println(" ");
		
		System.out.print("s2 count : ");
		System.out.println(token2.countTokens());
		count=token2.countTokens();
		for(int i=0; i<count; i++)
			System.out.println(token2.nextElement());
		System.out.println(" ");
		
		System.out.print("s3 count : ");
		count=token3.countTokens();
		System.out.println(token3.countTokens());
		for(int i=0; i<count; i++)
			System.out.println(token3.nextElement());
		System.out.println(" ");


	}

}
