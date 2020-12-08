
public class ex03 {

	public static void main(String[] args) {
		Rectangle r = new Rectangle(2,2,8,7);
		Rectangle s = new Rectangle(5,5,6,6);
		Rectangle t = new Rectangle(1,1,10,10);
		
		r.show();
		
		System.out.println("s의 면적은 "+s.square());
		if(t.contains(r))
			System.out.println("t는 r을 포함합니다.");
		
		if(t.contains(s))
			System.out.println("t는 s를 포함합니다.");
		
	}

}

class Rectangle{
	
	private int x;
	private int y;
	private int width;
	private int height;
	
	Rectangle(int setX,int setY,int setWidth,int setHeight){
		x=setX;
		y=setY;
		width=setWidth;
		height=setHeight;
	}
	
	public int square() {
		return width*height;
	}
	
	public void show() {
		System.out.printf("(%d,%d)에서 크기가 %dx%d인 사각형\n",x,y,width,height);
	}
	
	public boolean contains(Rectangle r) {
		
		if(r.x<x+width && r.x>x && r.y<y+height && r.y>y && r.x+r.width <x+width && r.y+r.height < y+height)
			return true;
		else 
			return false;	
	}	
}

