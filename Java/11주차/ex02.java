
public class ex02 {

	public static void main(String[] args) {
		
			 PairGen<String, Integer> p1 = new PairGen<>("Apple", 3);
			 PairGen<String, Integer> p2 = new PairGen<>("Apple", 3);
			 System.out.println(CompareGen.compare(p1, p2));

			 PairGen<String, String> p3 = new PairGen<>("°´Ã¼ÁöÇâ", "Java");
			 PairGen<String, String> p4 = new PairGen<>("°´Ã¼ÁöÇâ", "C++");
			 System.out.println(CompareGen.compare(p3, p4));
			 
			 }
	}

class PairGen<L,R>{
	
	private L object;
	private R object2;
	
	PairGen(L object,R object2){
		this.object=object;
		this.object2=object2;
	}
	
	L getObject() {
		return object;
	}
	
	R getObject2() {
		return object2;
	}
}

class CompareGen{
	
	static <L,R> boolean compare(PairGen<L,R>p1,PairGen<L,R>p2) {
		if(p1.getObject().equals(p2.getObject()) && p1.getObject2().equals(p2.getObject2()) )
			return true;
		else
			return false;
	}	
}

