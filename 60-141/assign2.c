/*	
	Title: Assign2.c
	Author: Samar El-Houssami
	Date last modified: 02/12/2017
	Objective: Go through a maze using the right hand on wall method
	
*/
	
//Includes
#include <stdio.h>

//Defines
#define E 1			//East
#define W -1		//West
#define N 2			//North
#define S -2		//South
#define SIZE 12

//Prototypes
void findStart(char maze[][SIZE]);								//locates entrance of maze
void mazeTraversal(char maze[][SIZE], int x, int y, int dir);	//decides which move to make next
void printMaze(char maze[][SIZE]);								//prints maze
int validMove(int x, int y);									//checks if move is valid
int coordsAreEdge(int x, int y);								//determines if coordinates are edges


int main()
{
	char maze[SIZE][SIZE] ={{'1','1','1','1','1','1','1','1','1','1','1','1'},
							{'1','0','0','0','1','0','0','0','0','0','0','1'},
							{'0','0','1','0','1','0','1','1','1','1','0','1'},
							{'1','1','1','0','1','0','0','0','0','1','0','1'},
							{'1','0','0','0','0','1','1','1','0','1','0','0'},
							{'1','1','1','1','0','1','0','1','0','1','0','1'},
							{'1','0','0','1','0','1','0','1','0','1','0','1'},
							{'1','1','0','1','0','1','0','1','0','1','0','1'},
							{'1','0','0','0','0','0','0','0','0','1','0','1'},
							{'1','1','1','1','1','1','0','1','1','1','0','1'},
							{'1','0','0','0','0','0','0','1','0','0','0','1'},
							{'1','1','1','1','1','1','1','1','1','1','1','1'}};
						 
	findStart(maze);
	
	return 0;
}

/*****************************************
Objective: Locates starting point of maze 
Input:	   2D array maze
Output:    none
******************************************/
void findStart(char maze[][SIZE])
{
	for (int i = 0; i < SIZE; i++)				//for each element of the first column
		if (maze[i][0] == '0')					//if the element is 0	
		{
			maze[i][0] = 'X';					//replace it with X
			mazeTraversal(maze, 0, i, E);		//send the coordinates of entrance to mazeTraversal()
			return;
		}
	
		printf("Failure to locate entrance.\n");
		return;
}

/*****************************************
Objective: Traverse through the maze, leaving
		   'X' in the path, until edge is found
Input:	   2D array maze, x and y coordinates, 
		   direction
Output:    none
******************************************/
void mazeTraversal(char maze[][SIZE], int x, int y, int dir)
{
	/*
	char c;
	printMaze(maze);
	printf("Hit return to see next move.\n");	
	
	do{
		scanf("%c", &c);
	} while(c != '\n');
	*/
	

	if (!coordsAreEdge(x,y))										//while the coordinates are not edges
	{	

		//if facing right (East)
		if (dir == E)	
		{
			if (maze[y+1][x] == '0' || maze[y+1][x] == 'X')			//if element on right is 0 or X
				if (validMove(x,y+1))								//if moving right is valid
				{
					maze[y+1][x] = 'X';								//move right
					return mazeTraversal(maze, x, y+1, S);			//face South
				}
			
			if (maze[y+1][x] == '1')								//if element on right is 1
				return mazeTraversal(maze, x, y, N);				//change direction (face North)
		}
		
		//if facing left (West)
		if (dir == W)	
		{
			if (maze[y-1][x] == '0' || maze[y-1][x] == 'X')			//if element on right is 0 or X
				if (validMove(x-1,y))								//if moving right is valid
				{
					maze[y-1][x] = 'X';								//move right
					return mazeTraversal(maze, x, y-1, N);			//face North
				}
		
			if (maze[y-1][x] == '1')								//if element on right is 1
				return mazeTraversal(maze, x, y, S);				//change direction (face South)
		}
		
		//if facing up (North)
		if (dir == N)	
		{
			if (maze[y][x+1] == '0' || maze[y][x+1] == 'X')			//if element on right is 0 or X
				if (validMove(x+1,y))								//if moving right is valid
				{
					maze[y][x+1] = 'X';								//move right
					return mazeTraversal(maze, x+1, y, E);			//face East
				}
		
			if (maze[y][x+1] == '1' && validMove(x+1,y))			//if element on right is 1
				return mazeTraversal(maze, x, y, W);				//change direction (West)
		}
		
		//if facing down (South)
		if (dir == S)	
		{
			if (maze[y][x-1] == '0' || maze[y][x-1] == 'X')			//if element on right is 0 or X
				if (validMove(x-1,y))								//if moving right is valid
				{
					maze[y][x-1] = 'X';								//move right
					return mazeTraversal(maze, x-1, y, W);			//face West
				}
		
			if (maze[y][x-1] == '1' && validMove(x-1,y))			//if element on right is 1
				return mazeTraversal(maze, x, y, E);				//change direction (face East)
		}
	}

	else
		printMaze(maze); return;									//when coordinates of edges are reached, print maze 
}	

/*****************************************
Objective: Determines if next move is valid
		   (within the perimeters of the array)
Input:	   Coordinates x and y
Output:    1 if valid, 0 if not valid
******************************************/
int validMove(int x, int y)
{
	if ((x < SIZE) && (y < SIZE)) return 1;			//if x and y are still within the perimeters of the array, the move is valid
	else return 0;
}

/*****************************************
Objective: Print maze 
Input:	   2D array maze
Output:    none
******************************************/
void printMaze(char maze[][SIZE])
{
	int i, j;
	
	printf("\n");
	
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
			printf("%3c", maze[i][j]);				//print every element of array "maze"
		
		printf("\n");
	}
	printf("\n");
}

/*****************************************
Objective: Determines if coordinates are edges
Input:	   x and y coordinates
Output:    1 if they're edges, 0 if not
******************************************/
int coordsAreEdge(int x, int y)
{
	if ((x == SIZE-1) || (y == SIZE-1) || (y == 0)) return 1;	//if coordinates are edges, return 1
	return 0;
}