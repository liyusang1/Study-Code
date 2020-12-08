
public class ex01 {

	public static void main(String[] args) {
		String text = "I love you";
		for(int i=0; i<text.length(); i++) {
		System.out.println(text.substring(i+1)+text.substring(0,i+1));
		}
	}

}
