
public class ex01 {

	public static void main(String[] args) {
		
		DVDPlayer d = new DVDPlayer();
		Player p = new DVDPlayer();
		ExPlayer e = new DVDPlayer();
		System.out.println("*** DVDPlayer�� ���� d ***");
		d.play();
		d.stop();
		d.slow();
		System.out.println("*** Player�� ���� p ***");
		p.play();
		p.stop();
		System.out.println("*** ExPlayer�� ���� e ***");
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
		System.out.println("DVD �������!");
	}

	@Override
	public void stop() {
		System.out.println("DVD �������!");
	}

	@Override
	public void slow() {
		System.out.println("DVD ������� ����!");
	}
	
}


