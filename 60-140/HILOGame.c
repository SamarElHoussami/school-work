#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand( time(NULL) );
	int goal = rand ( ) % 50 + 1; //random number between 1 and 50
	int guess;
	int i;
	
	for (i = 10; i > 0; i--)
	{
		printf("Enter your guess (between 1 and 50): \n");
		scanf("%d", &guess);
		
		if (guess < goal) 
		{
			printf("Too low...\n"); 
		}
		
		else if (guess > goal) 
		{
			printf("Too high...\n");
		}
		
		else 
		{
			printf("Correct, the number was %d.\n", goal);
			return 0;
		}
		
	}
	
		printf("Sorry, the number was %d.\n", goal);
	
	
	return 0;
}