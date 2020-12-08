
public class ex01 {

	public static void main(String[] args) {
		
		DVDPlayer d = new DVDPlayer();
		Player p = new DVDPlayer();
		ExPlayer e = new DVDPlayer();
		System.out.println("*** DVDPlayer형 변수 d ***");
		d.play();
		d.stop();
		d.slow();
		System.out.println("*** Player형 변수 p ***");
		p.play();
		p.stop();
		System.out.println("*** ExPlayer형 변수 e ***");
		e.play();
		e.stop();
		e.slow();
	}
}

interface ExPlayer extends Player{	
}

interface Player{
	
	void play();
	void stop();
	void slow();
}

class DVDPlayer implements ExPlayer,Player{
	@Override
	public void play() {
		System.out.println("DVD 재생시작!");
	}

	@Override
	public void stop() {
		System.out.println("DVD 재생종료!");
	}

	@Override
	public void slow() {
		System.out.println("DVD 느린재생 시작!");
	}
	
}


