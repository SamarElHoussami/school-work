package assignment3;
import java.util.Scanner;

public class Terrain {
	Scanner in = new Scanner(System.in);
	private int [][] heights;
	private int lowestH, highestH, size;
	
	/**
	Constructs 2D array with given size
	@param s size of square terrain
	*/
	public Terrain(int s) {
		size = s;
		heights = new int[size][size];
	}
	
	/**
	Reads user input and stores data into 2D array
	*/
	public void readInputs() {
		for(int i = 0; i < size; i++)
			for(int y = 0; y < size; y++) {
				System.out.print("Enter height: ");
				heights[i][y] = in.nextInt();
			}
	}
	
	/**
	Finds lowest height on 2D array
	@return lowestH the lowest height
	*/
	public int getLowest() {
		lowestH = heights[0][0];
		for(int i = 0; i < size; i++)
			for(int y = 0; y < size; y++)
				if(heights[i][y] < lowestH)
						lowestH = heights[i][y];
		
		return lowestH;	
	}
	
	/**
	Finds the highest height in 2D array
	@return heighestH the highest height
	*/
	public int getHighest() {
		highestH = heights[0][0];
		for(int i = 0; i < size; i++)
			for(int y = 0; y < size; y++)
				if(heights[i][y] > highestH)
						highestH = heights[i][y];
		
		return highestH;	
	}
	
	/**
	Draws flood map of terrain
	@param waterLvl the water level
	*/
	public void drawFloodMap(int waterLvl) {
		for(int i = 0; i < size; i++) {
			for(int y = 0; y < size; y++) {
				if(heights[i][y] < waterLvl)
					System.out.print("* ");
				else
					System.out.print("- ");
			}
			
			System.out.println();
		}		
	}
}
