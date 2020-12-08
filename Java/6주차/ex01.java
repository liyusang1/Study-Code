
public class ex01 {

	public static void main(String[] args) {
		int [][] a= {{1,2,3},{4,5,6}};
		int [][] b= {{6,3,4},{5,1,2}};
		int [][] c= new int[2][3];
		
		Matrix mx = new Matrix();
		System.out.println("행렬 a");
		mx.printMatrix(a);
		System.out.println("행렬 b");
		mx.printMatrix(b);
		System.out.println("행렬 c");
		mx.addMatrix(a,b,c);
		mx.printMatrix(c);
	}
}

class Matrix{
	
	void printMatrix(int [][]array) {
		for(int i=0; i<array.length; i++) {
			for(int j=0; j<array[i].length; j++) {
				System.out.print(array[i][j]+ " ");
			}
			System.out.println(" ");
		}
		System.out.println(" ");
	}
	void addMatrix(int [][]arrayA,int [][]arrayB,int [][]arrayC) {
		
		for(int i=0; i<arrayC.length; i++) {
			for(int j=0; j<arrayC[i].length; j++) {
				arrayC[i][j]=arrayA[i][j]+arrayB[i][j];
			}
		}
	}	
}

