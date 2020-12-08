
public class ex03 {

	public static void main(String[] args) {
		
		Shape[] arr= {
				new Circle("Circle",5),
				new Rectangle("Rectangle",3,4),
				new Triangle("Triangle",5,5)	
		};
		
		double sum=0;
		for(Shape a: arr) {
			System.out.println(a.getName()+"면적 : "+a.getArea());
			sum+=a.getArea();
		}
		System.out.println("면적의 합 : "+ sum);
	}

}

class Shape{
	protected String name;
	
	Shape(String name){
		this.name=name;
	}
	
	String getName() {
		return name;
	}
	
	double getArea() {
		return 0;
	}
}

class Circle extends Shape{
	private double radius;
	private final double PI=3.141592;
	Circle(String name,double radius){
		super(name);
		this.radius=radius;
	}
	@Override
	double getArea() {
		return radius*radius*PI;
	}
}

class Rectangle extends Shape{
	private double length;
	private double height;
	
	Rectangle(String name,double length,double height){
		super(name);
		this.length=length;
		this.height=height;	
	}
	@Override
	double getArea() {
		return length*height;
	}
}

class Triangle extends Shape{
	private double length;
	private double height;
	
	Triangle (String name,double length,double height){
		super(name);
		this.length=length;
		this.height=height;	
	}
	@Override
	double getArea() {
		return length*height*0.5;
	}
}
        
          





