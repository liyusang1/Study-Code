import java.util.List;
import java.util.Collections;
import java.util.Comparator;
import java.util.ArrayList;
import java.util.Iterator;


public class ex01 {

	public static void main(String[] args) {
		List<Person> list = new ArrayList<>();
		list.add(new Person("Yoon", 23));
		list.add(new Person("Hong", 53));
		list.add(new Person("Kim", 37));
		list.add(new Person("Park", 67));
		list.add(new Person("Lee", 15));
		
		Collections.sort(list);
		System.out.println("***나이순 정렬 ***");
		Iterator<Person> iter = list.iterator();
		while(iter.hasNext()) {
			System.out.println(iter.next());
		}
		
		Com com =new Com();
		System.out.println(" ");
		
		Collections.sort(list,com);
		System.out.println("***이름순 정렬 ***");
		iter = list.iterator();
		while(iter.hasNext()) {
			System.out.println(iter.next());
		}
	}
}

class Com implements Comparator<Person>{
	
	public int compare(Person p1,Person p2) {
		return p1.name.compareToIgnoreCase(p2.name);
	}
	
}

class Person implements Comparable<Person> {
	
	 String name;
	 int age;
	 
	 public Person(String name, int age) {
	this.name = name; this.age = age;
	 }
	 
	 public String toString() { return name + " : " + age; }
	 
	@Override
	public int compareTo(Person o) {

		return this.age-o.age;
	}
	
}