package dataStructAssignment2;

public class MazeTester {

	public static void main(String[] args) {
		Maze myMaze = new Maze("input.txt");
		myMaze.printDetails();
		myMaze.findShortestPath();
	}

}
