
public class ex02 {

	public static void main(String[] args) {
		CurrencyConverter.setRate(1121);
		System.out.println("ȯ�� 1�޷� : "+ CurrencyConverter.getRate());
		System.out.println("�鸸���� $"+CurrencyConverter.toDollar(1000000)+"�Դϴ�");
		System.out.println("$120�� "+CurrencyConverter.toKW(120)+"�� �Դϴ�.");

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