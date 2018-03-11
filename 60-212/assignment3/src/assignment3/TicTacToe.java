package assignment3;

public class TicTacToe {
	private final int MAX_MOVES = 9;
	private int totalMoves;		//keeps track of moves so far
	private char[][] board;		//2D array of chars
	private int player;			//current player (1 or 2)
	
	/**
	Constructs an empty 3x3 board (array)
	*/
	public TicTacToe() {
		board = new char[3][3];
		
		for(int i = 0; i < 3; i++)
			for(int y = 0; y < 3; y++)
				board[i][y] = ' ';
		
		totalMoves = 0;
		player = 1;
	}
	
	/**
	Draws tic tac toe board
	*/
	public void draw() {
		System.out.println(board[0][0] + " | " + board[0][1] + " | " + board[0][2]);
		System.out.println("-----------");
		System.out.println(board[1][0] + " | " + board[1][1] + " | " + board[1][2]);
		System.out.println("-----------");
		System.out.println(board[2][0] + " | " + board[2][1] + " | " + board[2][2]);
	}
	
	/**
	Checks if the box at given coordinates in the board is empty
	@param x x coordinate
	@param y y coordinate
	@return true if the box at given coordinates in the board is empty
	*/
	public boolean isValid(int x, int y) {
		if(board[x-1][y-1] == ' ')
			return true;
		
		return false;
	}
	
	/**
	Inserts element into the board (array)
	@param player current player
	@param x x coordinate
	@param y y coordinate
	*/
	public void insert(int player, int x, int y) {
		if(player == 1) 
			board[x-1][y-1] = 'X';
		
		else
			board[x-1][y-1] = 'O';
		
		totalMoves++;
	}
	
	/**
	Determines if a winning sequence exists on the board
	@return true if a winning sequence exists
	*/
	public boolean didWin() {
		int flagX;
		int flagY;
		
		//check horizontally
		for(int i = 0; i < 3; i++) {
			flagX = 0;
			flagY = 0;
			for(int y = 0; y < 3; y++) {
				if(board[i][y] != 'X')
					flagX = 1;
				
				if(board[i][y] != 'O')
					flagY = 1;
			}
			
			if (flagX == 0 || flagY == 0) 
				return true;
		}
				
		//check vertically
		for(int y = 0; y < 3; y++) {
			flagX = 0;
			flagY = 0;
			for(int i = 0; i < 3; i++) {
				if(board[i][y] != 'X')
					flagX = 1;
				
				if(board[i][y] != 'O')
					flagY = 1;
			}
			
			if (flagX == 0 || flagY == 0) 
				return true;
		}
		
		//check diagonally
		if(board[0][0] == 'X')
			if(board[1][1] == 'X')
				if(board[2][2] == 'X') 
					return true;
				
		
		if(board[0][0] == 'O')
			if(board[1][1] == 'O')
				if(board[2][2] == 'O')
					return true;
				
		
		if(board[2][0] == 'X')
			if(board[1][1] == 'X')
				if(board[0][2] == 'X')
					return true;
				
		
		if(board[2][0] == 'O')
			if(board[1][1] == 'O')
				if(board[0][2] == 'O') 
					return true;
				
	
		return false;
	}
	
	/**
	Returns maximum moves allowed
	@return MAX_MOVES maximum moves allowed
	*/
	public int maxMoves() {
		return MAX_MOVES;
	}
	
	/**
	Returns number of moves played
	@return totalMoves number of moves played
	*/
	public int totalMoves() {
		return totalMoves;
	}
	
	/**
	Switches between player 1 and 2
	*/
	public void switchPlayer() {
		if(player == 1)
			player = 2;
		else 
			player = 1;
	}
	
	/**
	Returns current player
	@return player current player
	*/
	public int player() {
		return player;
	}
}
