public class ex01 {

	public static void main(String[] args) {
		ColorPoint cp = new ColorPoint(5,5,"Yellow");
		cp.setXY(10,20);
		cp.setColor("Red");
		String str = cp.toString();
		System.out.println(str + "입니다.");
	}
}

class ColorPoint extends Point{
	
	private String color;
	public ColorPoint(int x,int y,String color){
		super(x,y);
		this.color=color;
	}
	
	void setXY(int x,int y) {
		super.move(x, y);
	}
	
	void setColor(String color) {
		this.color =color;
	}
	
	public String toString() {
		return color+"색의 "+"("+super.getX()+","+super.getY()+")의 점";
	}
}