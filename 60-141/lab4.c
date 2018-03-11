/*	
	Title: Lab4.c
	Date last modified: 02/06/2017
	Objective: Runs functions to find biggest element of given array and swap two elements
	
*/
	
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Prototypes
int *Largest(int *array, int size);		//Finds largest element in array
void Swap(int *x, int *y);				//swaps values of two integers


int main()
{
	srand( time(NULL) );
	int A[10], a = 2, b = 3;
	
	//Populates array
	for (int i = 0; i < 10; i++)
		A[i] = rand () % 100 + 1;
	
	printf("The largest element of the array is located at: %p.\n", Largest(A, 10));
	
	printf("Before swap: a = %d, b = %d.\n", a, b);
	Swap(&a, &b);
	printf("After swap: a = %d, b = %d.\n", a, b);
	
	return 0;
}

/********************************
Objective: Finds largest element in an array
Input: an array, size of the array
Output: the address of the largest number
*********************************/
int *Largest(int *array, int size)
{
	int *biggest = array;				//*biggest = value of first element in array
	for (int i = 0; i < size; i++){
		printf("val: %d\nAddress: %p\n\n", array[i], &array[i]);
		if (array[i] > *biggest)
			biggest = &array[i];		
	}
		return biggest;
}

/********************************
Objective: Swap 2 numbers
Input: address of two ints
Output: none
*********************************/
void Swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
	
}

	
	