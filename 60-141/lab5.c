/*	
	Title: Assign2.c
	Date last modified: 02/28/2017
	Objective: Bubble sort a pseudo-randomly filled array
	
*/
	
//Includes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Defines
#define SIZE 20


//Prototypes
void FillArray(int *array, int size);	//pseudo-randomly fills the array with integers ranging from 0 to 100
void PrintArray(int *array, int size) ;	//prints the array elements
void BubbleSort(int *array, int size);	//sorts the array in descending order
void Swap(int *a, int *b);				//swaps two values

int main()
{
	srand(time(NULL));
	
	int NumList[SIZE];
	
	FillArray(NumList, SIZE);
	printf("Array before sorting:\n");
	PrintArray(NumList, SIZE);
	printf("\n");
	
	BubbleSort(NumList, SIZE);
	
	printf("Array after sorting:\n");
	PrintArray(NumList, SIZE);
	printf("\n");
	
	return 0;
}

/********************************
Objective: pseudo-randomly fills the array with integers ranging from 0 to 100
Input: An array and size
Output: none
*********************************/
void FillArray(int *NumList, int size)
{
	for(int i = 0; i < size; i++)
		*(NumList+i) = rand() % 100 + 1;
}
/********************************
Objective: Prints every element of array
Input: An array and size
Output: none
*********************************/
void PrintArray(int *NumList, int size)
{
	for(int i = 0; i < size; i++)
	{
		printf("%5d", *(NumList+i));
		if ((i+1)%5==0)
			printf("\n");
	}
}
/********************************
Objective: Sorts array in descending order
Input: An array and size
Output: none
*********************************/
void BubbleSort(int *NumList, int size)
{
	for(int pass = 0; pass < size - 1; pass++)
		for(int i = 0; i < size - 1; i++)
			if (*(NumList+i) < *(NumList+i+1))
				Swap(NumList+i, NumList+i+1);
}
/********************************
Objective: swaps two values
Input: two values
Output: none
*********************************/
void Swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
