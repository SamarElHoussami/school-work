/*	
	Title: Tic Tac Toe
	Date last modified: 02/06/2017
	Objective: Single or multi-player tic tac toe
	
*/
	
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

//Defines


//Prototypes
void compPlay(char [][3]);
void resetBoard(char[][3]);
void printBoard(char [][3]);
void enterBox(char[], char [][3]);
int isBoxTaken(char[], char [][3]);
int isCoordValid(char[]);
int whoWon(char[][3]);
int endGame(char [][3]);

int main()
{
	char select;
	char coord[2];
	char board[3][3] = {{' '}};
	
	//menu display:
	do {
	printf("Welcome to tic-tac-toe! Hit enter to start a game.\n");
	scanf("%c", &select);
	
	if (select == '\n')
	{
		while (!endGame(board)){
		
		do {
			printBoard(board);
			printf("Your move. Enter the coordinates of the box you'd like to choose (eg. A2).\n");
			scanf("%s", coord);
		
			if (!isCoordValid(coord))
				printf("Invalid coordinates.\n");
		
			if (isBoxTaken(coord, board))
				printf("Box taken.\n");
		
		} while (!isCoordValid(coord) || isBoxTaken(coord, board));
	
		enterBox(coord, board);
	
		if (!endGame(board))	
			compPlay(board); 
		
		}
	
		if (endGame(board)){
	
			printBoard(board);
		
			switch(whoWon(board))
			{
			
			case 1: printf("Congratulations you win!\n");
					break;
 
			case 2: printf("Yikes... You lost!\n");
					break;
			
			case 3: printf("The game was a tie!\n");
					break;
				
			default: break;
			}
		}
	
	}
	printf("%c\n", select);
	} while (select != '\n');
	
	
	
	return 0;
	
}

void printBoard(char board[][3])
{
	printf("\tA   B   C\n\n");
	printf("%-7c\t %c | %c | %c \n", '1', board[0][0], board[0][1], board[0][2]);
	printf("\t---+---+---\n");
	printf("%-7c\t  %c | %c | %c \n", '2', board[1][0], board[1][1], board[1][2]);
	printf("\t---+---+---\n");
	printf("%-7c\t  %c | %c | %c \n\n", '3', board[2][0], board[2][1], board[2][2]);
}

int isCoordValid(char coord[2])
{
	if (strcmp(coord, "A1") == 0) return 1;
	if (strcmp(coord, "A2") == 0) return 1;
	if (strcmp(coord, "A3") == 0) return 1; 
	if (strcmp(coord, "B1") == 0) return 1;
	if (strcmp(coord, "B2") == 0) return 1;
	if (strcmp(coord, "B3") == 0) return 1;
	if (strcmp(coord, "C1") == 0) return 1;
	if (strcmp(coord, "C2") == 0) return 1;
	if (strcmp(coord, "C3") == 0) return 1;
	
	return 0;
}

int isBoxTaken(char coord[2], char board[][3])
{
	if ((strcmp(coord, "A1") == 0) && (board[0][0] == 'X' || board[0][0] == 'O')) return 1;
	if ((strcmp(coord, "A2") == 0) && (board[1][0] == 'X' || board[1][0] == 'O')) return 1;
	if ((strcmp(coord, "A3") == 0) && (board[2][0] == 'X' || board[2][0] == 'O')) return 1;
	
	if ((strcmp(coord, "B1") == 0) && (board[0][1] == 'X' || board[0][1] == 'O')) return 1;
	if ((strcmp(coord, "B2") == 0) && (board[1][1] == 'X' || board[1][1] == 'O')) return 1;
	if ((strcmp(coord, "B3") == 0) && (board[2][1] == 'X' || board[2][1] == 'O')) return 1;
	
	if ((strcmp(coord, "C1") == 0) && (board[0][2] == 'X' || board[0][2] == 'O')) return 1;
	if ((strcmp(coord, "C2") == 0) && (board[1][2] == 'X' || board[1][2] == 'O')) return 1;
	if ((strcmp(coord, "C3") == 0) && (board[2][2] == 'X' || board[2][2] == 'O')) return 1;
	
	return 0;
}

void enterBox(char coord[2], char board[][3])
{
	if (strcmp(coord, "A1") == 0)
		board[0][0] = 'X';
	if (strcmp(coord, "A2") == 0)
		board[1][0] = 'X';
	if (strcmp(coord, "A3") == 0)
		board[2][0] = 'X';
	if (strcmp(coord, "B1") == 0)
		board[0][1] = 'X';
	if (strcmp(coord, "B2") == 0)
		board[1][1] = 'X';
	if (strcmp(coord, "B3") == 0)
		board[2][1] = 'X';
	if (strcmp(coord, "C1") == 0)
		board[0][2] = 'X';
	if (strcmp(coord, "C2") == 0)
		board[1][2] = 'X';
	if (strcmp(coord, "C3") == 0)
		board[2][2] = 'X';
	return;
}

void compPlay(char board[][3])
{
	srand( time(NULL) );
	int r1, r2;
	
	//try winning
	if ((board[0][0]=='O' && board[0][1]=='O') && !isBoxTaken("C1", board))
	{board[0][2] ='O'; return;}
	if ((board[0][0]=='O' && board[1][1]=='O') && !isBoxTaken("C3", board))
	{board[2][2]='O'; return;}
	if ((board[0][0]=='O' && board[1][0]=='O') && !isBoxTaken("A3", board))
	{board[2][0]='O'; return;}
	
	if ((board[0][1]=='O' && board[1][1]=='O') && !isBoxTaken("B3", board))
	{board[2][1]='O'; return;}
	if ((board[0][1]=='O' && board[0][2]=='O') && !isBoxTaken("A1", board))
	{board[0][0]='O'; return;}
	
	if ((board[0][2]=='O' && board[1][2]=='O') && !isBoxTaken("C3", board))
	{board[2][2]='O'; return;}
	if ((board[0][2]=='O' && board[1][1]=='O') && !isBoxTaken("A3", board))
	{board[2][0]='O'; return;}
	
	if ((board[1][0]=='O' && board[1][1]=='O') && !isBoxTaken("C2", board))
	{board[1][2]='O'; return;}
	if ((board[1][0]=='O' && board[2][0]=='O') && !isBoxTaken("A1", board))
	{board[0][0]='O'; return;}
	
	if ((board[1][1]=='O' && board[1][2]=='O') && !isBoxTaken("A2", board))
	{board[1][0]='O'; return;}
	if ((board[1][1]=='O' && board[2][2]=='O') && !isBoxTaken("A1", board))
	{board[0][0]='O'; return;}
	if ((board[1][1]=='O' && board[2][1]=='O') && !isBoxTaken("B1", board))
	{board[0][1]='O'; return;}
	if ((board[1][1]=='O' && board[2][0]=='O') && !isBoxTaken("C1", board))
	{board[0][2]='O'; return;}
	
	if ((board[1][2]=='O' && board[2][2]=='O') && !isBoxTaken("C1", board))
	{board[0][2]='O'; return;}

	if ((board[2][2]=='O' && board[2][1]=='O') && !isBoxTaken("A3", board))
	{board[2][0]='O'; return;}
	if ((board[2][0]=='O' && board[2][1]=='O') && !isBoxTaken("C3", board))
	{board[2][2]='O'; return;}

	if ((board[0][0]=='O' && board[2][2]=='O') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[0][0]=='O' && board[2][0]=='O') && !isBoxTaken("A2", board))
	{board[1][0] ='O'; return;}
	if ((board[0][0]=='O' && board[0][2]=='O') && !isBoxTaken("B1", board))
	{board[0][1] ='O'; return;}
	if ((board[0][1]=='O' && board[2][1]=='O') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[0][2]=='O' && board[2][2]=='O') && !isBoxTaken("C2", board))
	{board[1][2] ='O'; return;}
	if ((board[0][2]=='O' && board[2][0]=='O') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[1][0]=='O' && board[1][2]=='O') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[2][0]=='O' && board[2][2]=='O') && !isBoxTaken("B3", board))
	{board[2][1] ='O'; return;}

	//block first
	if ((board[0][0]=='X' && board[0][1]=='X') && !isBoxTaken("C1", board))
	{board[0][2] ='O'; return;}
	if ((board[0][0]=='X' && board[1][1]=='X') && !isBoxTaken("C3", board))
	{board[2][2]='O'; return;}
	if ((board[0][0]=='X' && board[1][0]=='X') && !isBoxTaken("A3", board))
	{board[2][0]='O'; return;}
	
	if ((board[0][1]=='X' && board[1][1]=='X') && !isBoxTaken("B3", board))
	{board[2][1]='O';return;}
	if ((board[0][1]=='X' && board[0][2]=='X') && !isBoxTaken("A1", board))
	{board[0][0]='O'; return;}
	
	if ((board[0][2]=='X' && board[1][2]=='X') && !isBoxTaken("C3", board))
	{board[2][2]='O'; return;}
	if ((board[0][2]=='X' && board[1][1]=='X') && !isBoxTaken("A3", board))
	{board[2][0]='O'; return;}
	
	if ((board[1][0]=='X' && board[1][1]=='X') && !isBoxTaken("C2", board))
	{board[1][2]='O'; return;}
	if ((board[1][0]=='X' && board[2][0]=='X') && !isBoxTaken("A1", board))
	{board[0][0]='O';return;}
	
	if ((board[1][1]=='X' && board[1][2]=='X') && !isBoxTaken("A2", board))
	{board[1][0]='O'; return;}
	if ((board[1][1]=='X' && board[2][2]=='X') && !isBoxTaken("A1", board))
	{board[0][0]='O'; return;}
	if ((board[1][1]=='X' && board[2][1]=='X') && !isBoxTaken("B1", board))
	{board[0][1]='O'; return;}
	if ((board[1][1]=='X' && board[2][0]=='X') && !isBoxTaken("C1", board))
	{board[0][2]='O'; return;}
	
	if ((board[1][2]=='X' && board[2][2]=='X') && !isBoxTaken("C1", board))
	{board[0][2]='O'; return;}
	
	if ((board[2][0]=='X' && board[2][1]=='X') && !isBoxTaken("C3", board))
	{board[2][2]='O'; return;}
	if ((board[2][2]=='X' && board[2][1]=='X') && !isBoxTaken("A3", board))
	{board[2][0]='O'; return;}

	if ((board[0][0]=='X' && board[2][2]=='X') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[0][0]=='X' && board[2][0]=='X') && !isBoxTaken("A2", board))
	{board[1][0] ='O'; return;}
	if ((board[0][0]=='X' && board[0][2]=='X') && !isBoxTaken("B1", board))
	{board[0][1] ='O'; return;}
	if ((board[0][1]=='X' && board[2][1]=='X') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[0][2]=='X' && board[2][2]=='X') && !isBoxTaken("C2", board))
	{board[1][2] ='O'; return;}
	if ((board[0][2]=='X' && board[2][0]=='X') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[1][0]=='X' && board[1][2]=='X') && !isBoxTaken("B2", board))
	{board[1][1] ='O'; return;}
	if ((board[2][0]=='X' && board[2][2]=='X') && !isBoxTaken("B3", board))
	{board[2][1] ='O'; return;}
	
	
	
	//first moves
	if (!isBoxTaken("B2", board))
	{board[1][1] ='O'; return;} 

	if ((board[0][0]=='X' && board[1][1]=='O') && board[2][2]=='X')
	{ 
	  if (!isBoxTaken("B1", board))
		{
	      board[0][1] ='O';
		  return;
		}
	  if (!isBoxTaken("C2", board))
		{
	      board[1][2] ='O';
		  return;
		}
	  if (!isBoxTaken("B3", board))
		{
	      board[2][1] ='O';
		  return;
		}  
	 if (!isBoxTaken("A2", board))
		{
	      board[1][0] ='O';
		  return;
		}  
	}

	if ((board[2][0]=='X' && board[1][1]=='O') && board[0][2]=='X')
	{ 
	  if (!isBoxTaken("B1", board))
		{
	      board[0][1] ='O';
		  return;
		}
	  if (!isBoxTaken("C2", board))
		{
	      board[1][2] ='O';
		  return;
		}
	  if (!isBoxTaken("B3", board))
		{
	      board[2][1] ='O';
		  return;
		}  
	 if (!isBoxTaken("A2", board))
		{
	      board[1][0] ='O';
		  return;
		}  
	}
	
	if (board[1][1]=='X')
	{ 
	  if (board[0][0]=='X' && board[2][2]=='O' && !isBoxTaken("C1", board))
		{
	      board[0][2] ='O';
		  return;
		}
	  if (board[0][2]=='X' && board[2][0]=='O' && !isBoxTaken("C3", board))
		{
	      board[2][2] ='O';
		  return;
		}
	  if (board[2][0]=='X' && board[0][2]=='O' && !isBoxTaken("A1", board))
		{
	      board[0][0] ='O';
		  return;
		}  
	 if (board[2][2]=='X' && board[0][0]=='O' && !isBoxTaken("A3", board))
		{
	      board[2][0] ='O';
		  return;
		}  
	if (!isBoxTaken("C1", board))
		{
	      board[0][2] ='O';
		  return;
		}
	if (!isBoxTaken("C3", board))
		{
	      board[2][2] ='O';
		  return;
		}
	if (!isBoxTaken("A1", board))
		{
	      board[0][0] ='O';
		  return;
		}
	if (!isBoxTaken("A3", board))
		{
	      board[2][0] ='O';
		  return;
		}
	}
	
	//move randomly
	do {
			r1 = rand() % 3;
			r2 = rand() % 3;
			
		if ((board[r1][r2] != 'X') && (board[r1][r2] != 'O'))
		{
			board[r1][r2] = 'O';  
			return;
		}
		
	} while ((board[r1][r2] == 'X') || (board[r1][r2] == 'O'));
}


int endGame(char board[][3])
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') return 1;
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') return 1;
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') return 1;
	
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') return 1;
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') return 1;
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') return 1;
	
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return 1;
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return 1;
	
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') return 1;
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') return 1;
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') return 1;
	
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') return 1;
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') return 1;
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') return 1;
	
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return 1;
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return 1;
	
	if ((board[0][0]=='X' || board[0][0]=='O') && (board[0][1]=='X' || board[0][1]=='O') && (board[0][2]=='X' || board[0][2]=='O') && (board[1][0]=='X' || board[1][0]=='O') && (board[1][1]=='X' || board[1][1]=='O') && (board[1][2]=='X' || board[1][2]=='O') && (board[2][0]=='X' || board[2][0]=='O') && (board[2][1]=='X' || board[2][1]=='O') && (board[2][2]=='X' || board[2][2]=='O'))
		return 1;
	
	return 0;
}

int whoWon(char board[][3])
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') return 1;
	if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') return 1;
	if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') return 1;
	
	if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') return 1;
	if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') return 1;
	if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') return 1;
	
	if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return 1;
	if (board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X') return 1;
	
	if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') return 2;
	if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') return 2;
	if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') return 2;
	
	if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') return 2;
	if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') return 2;
	if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') return 2;
	
	if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return 2;
	if (board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O') return 2;
	
	if ((board[0][0]=='X' || board[0][0]=='O') && (board[0][1]=='X' || board[0][1]=='O') && (board[0][2]=='X' || board[0][2]=='O') && (board[1][0]=='X' || board[1][0]=='O') && (board[1][1]=='X' || board[1][1]=='O') && (board[1][2]=='X' || board[1][2]=='O') && (board[2][0]=='X' || board[2][0]=='O') && (board[2][1]=='X' || board[2][1]=='O') && (board[2][2]=='X' || board[2][2]=='O'))
		return 3;
	
	return 0;
}
