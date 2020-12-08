
public class ex04 {
	
	public static void main(String[] args) {
		
		Circle c1 = new Circle("Pizza",0);
		Circle c2 = new Circle("donut",0);
		Circle c3 = new Circle("hamburger",0);
		
		c1.setRad(12);
		c2.setRad(-2);
		c3.setRad(7);
		c1.show();
		c2.show();
		c3.show();
		
		double Max=c3.getArea();
		if(c2.getArea()>Max) {
			Max=c2.getArea();
			System.out.printf("가장 큰 면적은 %s",c2.getName());
			}
		else if(c1.getArea()>Max) {
			Max=c1.getArea();
			System.out.printf("가장 큰 면적은 %s",c1.getName());	
			}
		else
			System.out.printf("가장 큰 면적은 %s",c3.getName());	
		
	}		
}

class Circle{
	
	final double PI=3.14;
	private double radius;
	private String name;
	
	Circle(String setName,double setRadius){
		if(setRadius<0)
			setRadius=0;
		name = setName;
		radius = setRadius;	
	}
	public void setRad(double setRad) {
		if(setRad<0)
			setRad=0;
		radius = setRad;
	}
	
	public String getName() {
		String getName=name;
		return getName;
	}
	
	public double getArea() {
		return radius*radius*PI;
	}
	
	public void show() {
		System.out.printf("%s의 넓이 : %.2f\n",name,getArea());
	}
	
	
	
}