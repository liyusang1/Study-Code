import java.util.TreeSet;
import java.util.SortedSet;

public class ex03 {

	public static void main(String[] args) {
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		set.add(80); set.add(100); set.add(70);
		set.add(85); set.add(98); set.add(83);
		
		SortedSet<Integer> subset = new TreeSet<>(set);
		
		Integer first=subset.first();
		System.out.println("가장 낮은 점수 :"+first);
		
		Integer last=subset.last();
		System.out.println("가장 높은 점수 :"+last);
		
		System.out.println("90점 아래 점수 :"+set.lower(90));
		
		System.out.println("90점 위 점수 :"+set.higher(90));
		
		System.out.println("70점부터 90점 사이 점수 :"+subset.subSet(70, 90));
		System.out.println("85점 까지의 점수 :"+subset.headSet(85));
		System.out.println("85점 이상의 점수 :"+subset.tailSet(85));
	}
}
