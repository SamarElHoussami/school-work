/*	
	Title: Lab3.c
	Date last modified: 02/06/2017
	Objective: Display interactive menu and allow user to manipulate a 2D array using several functions
	
*/
	
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defines
#define M 6
#define N 5

//Prototypes
void PrintArray2D(int A2D[][N]);			//Print the array
void PopulateRandom2D(int A2D[][N]);		//Populate array with pseudo-random numbers 
int LinearSearch2D(int, int A2D[][N]);		//Search array for value, return true if found
void LeftShift2D(int A2D[][N]);				//Left shift the array
void ResetArray(int A2D[][N]);				//Reset array to 0


int main()
{

int A2D[M][N] = {{0}}, select, a;

do {												//outer loop

		do {
		printf("----- Select a function -----\n");	//displays menu
		printf("0 - Exit\n1 - Fill Array\n2 - Search Array\n3 - Left Shift Array\n4 - Print Array\n");
		scanf("%d", &select);
	
		if (select < 0 || select > 4)				//verifies if input of selection is valid
			printf("Invalid input\n");
	
		} while (select < 0 || select > 4);			//if invalid input, re-displays menu
	
		switch(select)
		{
			case 0: break;							//exit
			
			case 1: PopulateRandom2D(A2D);			//Populate Array
					printf("Populated array:\n\n");
					PrintArray2D(A2D);	
					break;
					
			case 2: printf("Enter a number you would like to search.\n");
					scanf("%d", &a);
					
					if (LinearSearch2D(a, A2D))		//Search Array
						printf("The number %d was found.\n", a);
					
					else
						printf("The number %d was not found.\n", a);
						break;
					
			case 3: LeftShift2D(A2D);				//Left Shift
					printf("Left shifted array:\n\n");
					PrintArray2D(A2D);	
					break;
			
			case 4: printf("Array:\n");
					PrintArray2D(A2D);				//Print Array
					break;
					
			default: printf("Error\n");
					 break;
			}
				
	} while (select != 0);							//loops as long as selection != 0
	
	
	return 0;
}

/********************************
Objective: Prints every element of the array
Input: A 2D array
Output: none
*********************************/
void PrintArray2D(int A2D[][N])
{
	int i, y;
	
	for (i = 0; i < M; i++){
		for (y = 0; y < N; y++)				//for every element in A2D
			printf("%10d ", A2D[i][y]);		//print each element 
		printf("\n");						//new line after every row
	}
	printf("\n");
}

/********************************
Objective: Populates array with 
pseudo-random non-repeating numbers 
from 1 to M*N
Input: A 2D array
Output: none
*********************************/
void PopulateRandom2D(int A2D[][N])
{
	ResetArray(A2D);						//reset every element to 0
	srand(time(NULL));						//seed random function
	
	int i, y, r = 0;
	
	for (i = 0; i < M; i++)
		for (y = 0; y < N; y++){
			while (LinearSearch2D(r, A2D))	//loop while r is found in the array
				r = rand() % (M*N) + 1;		//r = random number between 1 and M*N

			A2D[i][y] = r;
			}
}

/********************************
Objective: Search array for value
Input: a number, a 2D array
Output: True (1) or False (0)
*********************************/
int LinearSearch2D(int a, int A2D[][N])
{
	int i, y;
	
	for (i = 0; i < M; i++)
		for (y = 0; y < N; y++)			//for every element in A2D
			if (A2D[i][y] == a)			//if a is found
				return 1;				//return True
			
	return 0;							//if a is not found, return False
}

/********************************
Objective: Shifts each element of 
array one element to the left
Input: A 2D array
Output: none
*********************************/
void LeftShift2D(int A2D[][N])
{
	int i, y, temp = A2D[0][0];			//save first element as temp
	
	for (i = 0; i < M; i++)
	{
		for (y = 0; y < N-1; y++)		//loops up to the 2nd last element on a row
			A2D[i][y] = A2D[i][y + 1];	//element is replaced with the one proceeding it
		
		if (i == M-1)					//if loop has reached the last row
			A2D[i][y] = temp;			//last element in the row is replaced with temp
		else							//if not
			A2D[i][y] = A2D[i + 1][0];	//last element in the row is replaced with the first element from the row above it
	}
}

/********************************
Objective: Sets every element of array to 0
Input: A 2D array
Output: none
*********************************/
void ResetArray(int A2D[][N])
{
	int i, y;
	
	for (i = 0; i < M; i++)
		for (y = 0; y < N; y++)			//for every element in A2D
			A2D[i][y] = 0;				//set element to 0
}

	
	
	