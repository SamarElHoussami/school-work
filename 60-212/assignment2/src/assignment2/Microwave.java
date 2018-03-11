package assignment2;

public class Microwave {
private int time;
private int level;

	Microwave() {
		time = 0;
		level = 1;
	}

	void increaseTime() {
		time += 30;
	}
	
	void switchLevels() {
	if (level == 1)
		level = 2;
	
	else
		level = 1;
	}
	
	void reset() {
		time = 0;
		level = 1;
	}
	
	void start() {
		System.out.println("Cooking for " + time + " seconds at level " + level);
		reset();
	}
}
