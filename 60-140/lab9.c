#include <stdio.h>

int readNum();
int iterativeTriangularNumber(int number);
int recursiveTriangularNumber(int number);

int number, triangularNumber = 0;

int main() 
{
	number = readNum();
	printf("Iterative: Triangular number of %d is %d.\n", number, iterativeTriangularNumber(number));
	printf("Recursive: Triangular number of %d is %d.\n", number, recursiveTriangularNumber(number));
	
	return 0;
}

int readNum() 
{
	do {
		printf("Enter valid number (>0): ");
		scanf("%d", &number);
		
		if (number <= 0)
			printf("Invalid number.\n");
		
	}	while (number <= 0);
	
	return number;
}

int iterativeTriangularNumber(int number)
{
	int triangularNumber = 0;
	
	for (int i = 1; i <= number; i++)
		triangularNumber += i;

	return triangularNumber;
}

int recursiveTriangularNumber(int number)
{
	if (number != 0) {
		triangularNumber += number;
		return recursiveTriangularNumber(number-1);
	}
	
	else 
		return triangularNumber;
}