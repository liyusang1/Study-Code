import java.util.TreeSet;
import java.util.SortedSet;

public class ex03 {

	public static void main(String[] args) {
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		
		set.add(80); set.add(100); set.add(70);
		set.add(85); set.add(98); set.add(83);
		
		SortedSet<Integer> subset = new TreeSet<>(set);
		
		Integer first=subset.first();
		System.out.println("���� ���� ���� :"+first);
		
		Integer last=subset.last();
		System.out.println("���� ���� ���� :"+last);
		
		System.out.println("90�� �Ʒ� ���� :"+set.lower(90));
		
		System.out.println("90�� �� ���� :"+set.higher(90));
		
		System.out.println("70������ 90�� ���� ���� :"+subset.subSet(70, 90));
		System.out.println("85�� ������ ���� :"+subset.headSet(85));
		System.out.println("85�� �̻��� ���� :"+subset.tailSet(85));
	}
}
