
public class ex02 {

	public static void main(String[] args) {
		Shape[] arr = { 
				new Circle("Circle", 5),
				new Rectangle("Rectangle", 3, 4),
				new Triangle("Triangle", 5, 5)
				};
		
	double sum = 0;
	for (Shape a : arr) {
	System.out.println(a.getName() + "면적 : " + a.getArea());
	sum += a.getArea();
	}
	
	System.out.println("면적의 합 : " + sum);
	
	}
}

abstract class Shape{
	String name;
	final double PI = 3.141592;
	Shape(String name){
		this.name=name;
	}
	String getName() {
		return name;
	}
	abstract double getArea();
}

class Circle extends Shape{
	
	int radius;
	
	Circle(String name,int radius) {
		super(name);
		this.radius=radius;
	}
	double getArea() {
		return PI*radius*radius;
	}
}

class Rectangle extends Shape{
	
	int width;
	int height;
	
	Rectangle(String name,int width,int height) {
		super(name);
		this.width=width;
		this.height=height;
	}
	double getArea() {
		return width*height;
	}
}

class Triangle extends Shape{
	
	int width;
	int height;
	
	Triangle(String name,int width,int height) {
		super(name);
		this.width=width;
		this.height=height;
	}
	double getArea() {
		return width*height*0.5;
	}
}
