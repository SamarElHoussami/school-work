package dataStructAssignment2;

import java.io.File;
import java.util.Scanner;
import java.util.ArrayList;


public class Maze {

	private Scanner file;
	private int size, r1, r2;
	private int[][] maze;				//store maze in 2D array
	private ArrayList<Integer> visited;	//array of visited rooms
	private ArrayList<Integer> path;		//final path
	private String buffer;
	
	/**
	 * Constructs maze from input file
	 * @param s name of file
	 */
	public Maze(String s) {
		    
		//open file
		try {
			file = new Scanner(new File(s));
		}
		catch(Exception e) {
			System.out.println("Could not find file");
		}

		//read size of array and rooms
		size = file.nextInt();
		r1 = file.nextInt();
		r2 = file.nextInt();
		
		//initialize arrays
		maze = new int[size][size];
		visited = new ArrayList<Integer>();
		path = new ArrayList<Integer>();
		
		//read maze and store it into 2D array maze[][]
		buffer = file.nextLine();
		for(int i = 0; i < size; i++) {
			buffer = file.nextLine();
			for(int y = 0; y < buffer.length(); y++) {
				if(y%2 == 0) {
					maze[i][y/2] = Character.getNumericValue(buffer.charAt(y)); 
				}
			}	
		}
		
		//close file
		file.close();
	}
	
	/**
	 * Prints details of maze i.e.:
	 * size, room1, room2, 2D maze
	 */
	public void printDetails() {
		System.out.println("size of maze: " + size);
		System.out.println("Trying to get from " + r1 + " to " + r2);
		System.out.println();
		System.out.println("Maze input:");
		
		for(int i = 0; i < size; i++) {
			for(int y = 0; y < size; y++) 
				System.out.print(maze[i][y] + " ");
			System.out.println();
		}
		
		System.out.println();
	}

	/**
	 * Checks if room has been visited
	 * @param a int (room) to be checked
	 */
	private boolean checkVisited(int a) {
		for(int i = 0; i < visited.size(); i++)
			if(visited.get(i) == a) 
				return true;
		
		return false;
	}
	
	/**
	 * Add 'size' amount of 0s to ArrayList
	 * @param ArrayList<Integer> array to be set
	 */
	private void setArray(ArrayList<Integer> array) {
		for(int i = 0; i < size; i++) {
			array.add(0);
		}
	}
	
	/**
	 * Traverse through 2D array recursively until every possible
	 * path has been visited. End recursion with shortest path
	 * @param t row of 2D array (current room)
	 */
	private void traverse(int t) {
		//if the current room has a door to the final room
		if(maze[t][r2] == 1) {
			//add the final room to list of visited rooms
			//visited[] becomes a possible path from room1 to room2
			visited.add(r2);
		
			//if the visited is shorter than the last recorded path
			//set path = visited
			if(visited.size() < path.size()) 
				path = new ArrayList<Integer>(visited);	
		
			//go back to the previous room
			visited.remove(visited.size() - 1);
			
			return;
		}
	
		//if the current room does not have a door to the final room
		//go through every column of the current row
		for(int i = 0; i < size; i++) {
			//if the current room has a door to room i (which isn't itself)
			if(maze[t][i] == 1 && t != i) {
				//if i hasn't been visited yet
				if(!checkVisited(i)) {
					//add i to visited and visit i
					visited.add(i);
					traverse(i);
					//after a room has been fully traversed, go back to previous room
					visited.remove(visited.size() - 1);
				} 
			}
		}
		
		return;
	}
	
	public void findShortestPath() {
		//add 'size' elements to path
		setArray(path);
		
		//add r1 to beginning of the path and traverse r1
		visited.add(r1);
		traverse(r1);
		
		//if any path is found, it would consist of going through at most 'size-1' rooms
		//if no path is found, path.size() would remain 'size'
		if(path.size() == size)
			System.out.println("No path exists between room " + r1 + " and room " + r2);
			
		else {
			System.out.println("The shortest path between room " + r1 + " and room " + r2 + " is: " + path);
		}
		
		return;
	}
}