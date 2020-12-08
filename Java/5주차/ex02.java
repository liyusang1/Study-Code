
public class ex02 {

	public static void main(String[] args) {
		CurrencyConverter.setRate(1121);
		System.out.println("환율 1달러 : "+ CurrencyConverter.getRate());
		System.out.println("백만원은 $"+CurrencyConverter.toDollar(1000000)+"입니다");
		System.out.println("$120는 "+CurrencyConverter.toKW(120)+"원 입니다.");

	}

}

class CurrencyConverter{
	
	static public double rate;
	
	static public void setRate(double setRate) {
		rate=setRate;
	}
	static public double getRate() {
		return rate;
	}
	static public double toDollar(double won) {
		return (double)won/rate;
	}
	static public double toKW(double won) {
		return (double)won*rate;
	}
	
	
	
}