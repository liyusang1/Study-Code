import java.util.Scanner;
public class ex02 {

	public static void main(String[] args) {
		System.out.println("�ѿ� �ܾ� �˻� ���α׷� �Դϴ�.");
		while(true) {
		System.out.print("�ѱ� �ܾ�?");
		Scanner sc1= new Scanner(System.in);
		String str1= sc1.nextLine();
		if(str1.equals("�׸�"))
			break;
		System.out.printf("%s\n",Dictionary.kor2Eng(str1));
		}
	}
}

class Dictionary{
	
	private static String[] kor = {"���","�Ʊ�","��","�̷�","���"};
	private static String[] eng = {"love","baby","money","future","hope"};
	
	public static String kor2Eng(String word) {
		
		for(int i=0; i<kor.length; i++) {
			
			if(word.equals(kor[i])) {
				String str1=kor[i]+"�� "+eng[i];
				return str1;		
			}
		}
				String str2=word+"�� ���� ������ �����ϴ�.";
				return str2;		
	}							
}