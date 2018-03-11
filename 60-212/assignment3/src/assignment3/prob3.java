package assignment3;

import java.util.Scanner;

public class prob3 {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int x, y;
		
		System.out.println("Welcome to TicTacToe! Player 1 is 'X' and Player 2 is 'O'.");
		//creates new tic tac toe board
		TicTacToe board = new TicTacToe();
		
		//Play until it's a tie or someone wins
		do {
			board.draw();
			
			//Loops until valid coordinates are entered
			do {
				System.out.println("Player " + board.player() + " : Enter x and y coordinates. (1 to 3)");
				x = in.nextInt();
				y = in.nextInt();
				
				if(y > 3 || x > 3 || !board.isValid(x, y))
					System.out.println("Invalid coordinates");
				
			} while(x > 3 || y > 3  || !board.isValid(x, y));
			
			//insert element in the board
			board.insert(board.player(), x, y);
			
			//switch players
			board.switchPlayer();
			
		} while(board.totalMoves() < board.maxMoves() && !board.didWin());
		
		//if no one won when the loop stops, it's a tie
		if(!board.didWin()) {
			board.draw();
			System.out.println("It's a tie!");
		}
		
		else {
			board.draw();	
			board.switchPlayer();
			System.out.println("Player " + board.player() + " wins!");
		}
	}

}
