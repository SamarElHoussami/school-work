package dataStructAssignment2;
import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

public class MazeWithCommentary {

	private Scanner file;
	private int size, r1, r2;
	ArrayList<Integer> visited = new ArrayList<Integer>();
	ArrayList<Integer> path = new ArrayList<Integer>();
	private int[][] maze;
	//private int[] visited;
	//private int[] path;
	private String buffer;
	
	//CONSTRUCTOR
	public MazeWithCommentary(String s) {
		try {
			file = new Scanner(new File(s));
		}
		catch(Exception e) {
			System.out.println("Could not find file ");
		}
		
		size = file.nextInt();
		r1 = file.nextInt();
		r2 = file.nextInt();
		
		//visited = new int[size];
		//path = new int[size];
		maze = new int[size][size];
		
		buffer = file.nextLine();
		for(int i = 0; i < size; i++) {
			buffer = file.nextLine();
			for(int y = 0; y < buffer.length(); y++) {
				if(y%2 == 0) {
					maze[i][y/2] = Character.getNumericValue(buffer.charAt(y)); 
				}
			}	
		}
		
		file.close();
	}
	
	public void printDetails() {
		System.out.println("size of maze: " + size);
		System.out.println("Trying to get from " + r1 + " to " + r2);
		System.out.println("MAZE:");
		
		for(int i = 0; i < size; i++) {
			for(int y = 0; y < size; y++) 
				System.out.print("[" + i + "][" + y + "] = " + maze[i][y] + " ");
			System.out.println();
		}
	}

	private boolean checkVisited(int a) {
		for(int i = 0; i < visited.size(); i++)
			if(visited.get(i) == a) {
				System.out.println();
				System.out.println("room " + a + " already visited");
				System.out.print("path so far: " + visited);
			
				System.out.println();
				return true;
			}
				
		
		return false;
	}
	
	private void resetArray(ArrayList<Integer> array) {
		for(int i = 0; i < size; i++) {
			array.add(0);
		}
	}
	
	
	private void traverse(int t) {
		System.out.println();
		System.out.println("room: " + t);
		if(maze[t][r2] == 1) {
			System.out.println("room " + r2 + " has been found");
			//visited.add(index++, r2);
			visited.add(r2);
			System.out.println("visited size: " + visited.size() + " path size: " + path.size());
			if(visited.size() < path.size()) {
				path = new ArrayList<Integer>(visited);
				System.out.print("new path: " + path);
				System.out.println();
			}
			//visited[--index] = -1;
			visited.remove(visited.size() - 1);

			return;
		}
		
		//printArray(visited);
		//visited.toString();
		System.out.println(visited);
		for(int i = 0; i < size; i++) {
			System.out.println("[" +t+ "]["+i+"] = " + maze[t][i]);
			if(maze[t][i] == 1 && t != i) {
				if(!checkVisited(i)) {
					System.out.println("Door to room " + i + " found!");
					//visited[index++] = i;
					//visited.add(index++,  i);
					visited.add(i);
					traverse(i);
					System.out.println("go back to previous room");
					visited.remove(visited.size() - 1);
					System.out.println(visited);
					//visited[--index] = -1;
				} 
				
			}
			
		}
			
	}
	
	public void findShortestPath() {
		resetArray(path);
		
		visited.add(r1);
		
		traverse(r1);
		
		System.out.println("The shortest path is: ");
		System.out.println(path);
		return;
	}
}