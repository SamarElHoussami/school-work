/*	
	Title: Lab1.c
	Date last modified: 01/20/2016
	Objective: Display interactive menu and allow user to call 5 iterative functions
	
*/
	
//Includes
#include <stdio.h>

//Prototypes
int funcSum(int);			//Calculates summation
int funcFact(int);			//Calculates factorial 
int funcFib(int);			//Calculates the fibonacci number
int funcGCD(int, int);		//Calculates gcd
int funcPow(int, int);		//Calculates number to the power of another number

int main()
{
	int select, a, b;
		
	do {										//outer loop
     
		a = 0;									//resets variables a and b
		b = 0;
		
		do {
		printf("----- Select a function -----\n");	//displays menu
		printf("0 - Exit\n1 - Summation\n2 - Factorial\n3 - Fibonacci\n4 - gcd\n5 - Power\n");
		scanf("%d", &select);
	
		if (select < 0 || select > 5)			//verifies if input of selection is valid
			printf("Invalid input\n");
	
		} while (select < 0 || select > 5);		//if invalid input, re-displays menu
	
		switch(select)
		{
			case 0: break;				//exit
			
			case 1: do {				//Summation 
					printf("Enter a number (>=1)\n");
					scanf("%d", &a);
					
					if (a < 1)
						printf("Invalid input.\n");	
					} while (a < 1);	
					
					printf("The summation of the number: %d is %d\n", a, funcSum(a));
					break;
					
			case 2: do {				//Factorial
					printf("Enter a number (>=0)\n");
					scanf("%d", &a);
					
					if (a < 0)
						printf("Invalid input.\n");
					} while (a < 0); 
					
					printf("Factorial(%d) = %d\n", a, funcFact(a));
					break;
					
			case 3: do {				//Fibonacci
					printf("Enter a number (>=0)\n");
					scanf("%d", &a);
					
					if (a < 0)
						printf("Invalid input.\n");
					} while (a < 0); 
					
					printf("Fibonacci(%d) = %d\n", a, funcFib(a));
					break;
			
			case 4: do {				//GCD
					printf("Enter two numbers (>=0)\n");
					scanf("%d %d", &a, &b);
					
					if (a < 0 || b < 0)
						printf("Invalid input.\n");
					} while (a < 0 || b < 0); 
					
					printf("gcd(%d, %d) = %d\n", a, b, funcGCD(a, b));
					break;
			
			case 5: do {				//Power
					printf("Enter two numbers (1st number > 0) (2nd number >= 0)\n");
					scanf("%d %d", &a, &b);
					
					if (a <= 0 || b < 0)
						printf("Invalid input.\n");
					} while (a <= 0 || b < 0); 
					
					printf("Power(%d, %d) = %d\n", a, b, funcPow(a, b));
					break;
					
			default: printf("Error\n");
					 break;
			}
				
	} while (select != 0);			//loops as long as selection != 0
	
	return 0;
}

	/********************************
	Objective: Calculate summation
	Input: Number (a) >= 0
	Output: Summation of input
	*********************************/
	int funcSum(int a)
	{
		int count, sum = 0;
		
		for (count = 1; count <= a; count++)
			sum += count;
		
		return sum;
	}
	
	/********************************
	Objective: Calculate factorial
	Input: Number (a) >= 0
	Output: Factorial of input
	*********************************/
	int funcFact(int a)
	{
		int x, result = 1;
		
		for (x = 1; x <= a; x++)
			result *= x;
		
		return result;
	}
	
	/********************************
	Objective: Calculate fibonacci number
	Input: Number (a) >= 0
	Output: Fibonacci number of input
	*********************************/
	int funcFib(int a)
	{
		if ((a == 0) || (a == 1)) return a;
	
		else 
		{	
			int one = 0, two = 1, next, x;
		
			for (x = 1; x < a; x++)
			{
				next = one + two;
				one = two;
				two = next;
			}
		
			return next;
		}
	}
	
	/********************************
	Objective: Calculate GCD of two numbers
	Input: Two numbers (a) >= 0 and (b) >=0
	Output: GCD of both inputs
	*********************************/
	int funcGCD(int a, int b)
	{
		int i, gcd;
		
		for (i = 1; i <= a || i <= b; i++)
		{
			if ((a%i == 0) && (b%i == 0))
				gcd = i;
		}
		
		return gcd;
	}
	
	/********************************
	Objective: Calculate a number to the power
	of another number
	Input: Two number (a) > 0 and (b) >=0
	Output: a to the power of b
	*********************************/
	int funcPow(int a, int b)
	{
		//int result = a;
		
		if (b == 0) return 1;
	
		else {
			
			for (; b > 1; b--) 
				a *= a;
			}
		
		//return result;
		return a;
	}
		
	
	