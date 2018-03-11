package assignment3;


public class prob4 {

	public static void main(String[] args) {
		int size = 4;
		Terrain t1 = new Terrain(size);
		
		t1.readInputs();
		
		System.out.println("Lowest height: " + t1.getLowest());
		System.out.println("Highest height: " + t1.getHighest());		
		
		t1.drawFloodMap(5);
	}

}
