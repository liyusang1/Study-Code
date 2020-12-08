
public class ex03 {

	public static void main(String[] args) {
		String text1 = "eW";
		String text2 = "LOVE";
		String text3 = "C++";
		String text4 = "programming.";
		
		StringBuilder Text1 =new StringBuilder(text1);
		Text1.reverse();
		Text1.append(' ').append(text2.toLowerCase());
		Text1.append(' ').append(text3.replace("C++", "JAVA"));
		Text1.append(' ').append(text4);
		
		System.out.println(Text1.toString());
	}

}
