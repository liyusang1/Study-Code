
public class ex02 {

	public static void main(String[] args) {
		
		Song dancingQueen = new Song("Dancing Queen","ABBA",1978,"������");
		dancingQueen.show();

	}

}

class Song{
	private String Title;
	private String artist;
	private int year;
	private String country;
	
	public Song(String setTitle,String setArtist,int setYear,String setCountry){
		
		Title=setTitle;
		artist= setArtist;
		year =setYear;
		country = setCountry;
	}
	
	public void show() {
		
		System.out.printf("%d�� %s ������ %s�� �θ� %s",year,country,artist,Title);
	}
}