import java.util.HashMap;
import java.util.Set;
import java.util.Map;
import java.util.TreeMap;


public class ex04 {
	
	public static void main(String[] args) {
		 
			 String[] data = { "A", "K", "A", "K", "D", "A",
			 "K", "K", "K", "Z", "D" };
			 
			 Map<String, Integer> map = new HashMap<String, Integer>();
			 
				/*for(String key : data) {
					map.put(key, map.getOrDefault(key, 0)+1);
				}*/
				
				for(int i=0; i<data.length; i++) {
					map.put(data[i], map.getOrDefault(data[i], 0)+1);
				}
					
			TreeMap<String,Integer> tm = new TreeMap<String,Integer>(map);

			Set<String> ks = tm.keySet();
			
	
			for(String n :ks)
				System.out.println(n+ " : "+tm.get(n));		
	}
}
	


