package assignment2;

public class prob2 {

	public static void main(String[] args) {
		Microwave microwave = new Microwave();
		
		microwave.increaseTime();
		microwave.increaseTime();
		microwave.switchLevels();
		//Expected: 60 sec at lvl 2
		microwave.start();
		microwave.increaseTime();
		microwave.reset();
		microwave.increaseTime();
		//Expected: 30 sec at lvl 1
		microwave.start();
	}

}
