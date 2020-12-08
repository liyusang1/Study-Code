import java.util.Scanner;
public class ex02 {

	public static void main(String[] args) {
		System.out.println("한영 단어 검색 프로그램 입니다.");
		while(true) {
		System.out.print("한글 단어?");
		Scanner sc1= new Scanner(System.in);
		String str1= sc1.nextLine();
		if(str1.equals("그만"))
			break;
		System.out.printf("%s\n",Dictionary.kor2Eng(str1));
		}
	}
}

class Dictionary{
	
	private static String[] kor = {"사랑","아기","돈","미래","희망"};
	private static String[] eng = {"love","baby","money","future","hope"};
	
	public static String kor2Eng(String word) {
		
		for(int i=0; i<kor.length; i++) {
			
			if(word.equals(kor[i])) {
				String str1=kor[i]+"은 "+eng[i];
				return str1;		
			}
		}
				String str2=word+"는 저의 사전에 없습니다.";
				return str2;		
	}							
}