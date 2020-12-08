
public class ex04 {

	public static void main(String[] args) {
		Circle a = new Circle (2,3,30);
		Circle b = new Circle (5);
		Circle c = new Circle (2,3);
		
		System.out.println("�� a :"+a);
		System.out.println("�� b :"+b);
		System.out.println("�� b :"+c);
		
		if(a.equals(b))
			System.out.println("���� ��");
		else
			System.out.println("���� �ٸ� ��");
		if(a.equals(c))
			System.out.println("���� ��");
		else
			System.out.println("���� �ٸ� ��");
	}
}

class Circle{
	
	private int x;
	private int y;
	private int radius;
	
	Circle(int x,int y,int radius){
		this.x=x;
		this.y=y;
		this.radius=radius;
	}
	
	Circle(int radius){
		x=0;
		y=0;
		this.radius=radius;
	}
	
	Circle(int x,int y){
		this.x=x;
		this.y=y;
		radius=5;
	}
	void showCircle() {
		System.out.println(x);
	}
	
	public String toString() {
		return ("Circle(" + x + "," + y + ")" + " ������" + radius);
	}
	
	boolean equals(Circle a) {
		if((a.x==x)&&(a.y==y))
			return true;
		else
			return false;	
	}
	
	
}
