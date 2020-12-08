import java.util.Arrays;

public class ex03 {

	public static void main(String[] args) {
		Circle[] c = { new Circle("Cup", 3),
				new Circle("Apple", 4),
				new Circle("Doughnut", 5),
				new Circle("Pizza", 7),
				new Circle("Ball", 2) };
		
		Arrays.sort(c);
		for(int i=0; i<c.length; i++) {
			c[i].showInfo();
		}
		int dix = Arrays.binarySearch(c, new Circle ("Apple",4));
		System.out.println("Index of Apple : "+dix);
		
	}

}

class Circle implements Comparable{
	private String name;
	private int radius;
	
	Circle(String name,int radius){
		this.name=name;
		this.radius=radius;
	}

	@Override
	public int compareTo(Object o) {
		Circle circle=(Circle)o;
		if(this.radius>circle.radius)
			return 1;
		else if(this.radius<circle.radius)
			return -1;
		return this.name.compareTo(circle.name);
	}
	
	void showInfo() {
		double width = radius*radius*3.14;
		System.out.println(name + " "+ width);
	}
}
