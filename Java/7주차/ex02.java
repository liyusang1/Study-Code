
public class ex02 {

	public static void main(String[] args) {
		
		Point3D p =new Point3D(1,2,3);
		System.out.println(p.toString()+"입니다.");
		
		p.moveUp();
		System.out.println(p.toString()+"입니다.");
		
		p.moveDown();
		p.move(10,10);
		System.out.println(p.toString()+"입니다.");
		
		p.move(100,100,100);
		System.out.println(p.toString()+"입니다.");
	}
}

class Point3D extends Point{
	
	private int z;
	
	Point3D(int x,int y,int z){
		super(x,y);
		this.z=z;
	}
	
	void moveUp() {
		z+=1;
	}
	
	void moveDown() {
		z-=1;
	}
	
	public void move(int x,int y) {
		super.move(x,y);
	}
	
	public void move(int x,int y,int z) {
		super.move(x, y);
		this.z=z;
	}
	
	public String toString() {
		return "("+super.getX()+","+super.getY()+","+z+")"+"의 점";
	}
}


