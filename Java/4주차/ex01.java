
public class ex01 {

	public static void main(String[] args) {
		
		Tv myTv=new Tv("LG",2017,32);
		myTv.show();

	}

}

 class Tv{
	private String company;
	private int year;
	private int inch;
	
	public Tv(String setCompany,int setYear,int setInch){
		company=setCompany;
		year = setYear;
		inch = setInch;
	}
	
	public void show() {
		System.out.printf("%s에서 만든 %d년형 %d인치 TV", company,year,inch);
	}
}
