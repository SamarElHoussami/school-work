#include<stdio.h>

int main() 
{
	int L[3];
	printf("Enter 3 numbers separated by commas to get the sum of their squares: \n");
	scanf("%d, %d, %d", &L[0], &L[1], &L[2]);
	
	int sumOfSquare = 0;
	
	for (int i=0; i<3; i++) {
		sumOfSquare = sumOfSquare + (L[i] * L[i]);
	}
	
	printf("The sum of squares is: %d\n", sumOfSquare);
	
	return 0; 
}