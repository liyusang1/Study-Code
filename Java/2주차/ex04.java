class JavaPractice {

		public static void main(String[] args) {
			
			int money =65367;
			System.out.println("오만원    : "+money/50000);
			System.out.println("만원      : "+(money%50000)/10000);
			System.out.println("오천원    : "+(money%10000)/5000);
			System.out.println("천원      : "+(money%5000)/1000);
			System.out.println("오백원    : "+(money%1000)/500);
			System.out.println("백원      : "+(money%500)/100);
			System.out.println("오십원    : "+(money%100)/50);
			System.out.println("십원      : "+(money%50)/10);
			System.out.println("일원      : "+(money%10)/1);
	}


}
