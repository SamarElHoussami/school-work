/*Calculates e*/

#include <stdio.h>

int main()
{
	double e = 1.0;
	int n, i, fact;

	printf("Enter a positive integer: ");
	scanf("%d", &n);

	while (n > 0)					//Repeats n times
	{
		fact = 1;					//Sets factorial to 1 for every loop
		
		for (i = 1; i <= n; i++)
		{
			fact *= i; 				//Calculates factorial of n
		}
		
		e = e + (double)1/fact;		//Sets e to 1 + 1/n!
		n-=1;						//Allows loop to calculate e=1 + 1/n! + 1/(n-1)! + ... + 1/1!
	}
	
	printf("ε = %.5lf\n", e);		//Prints e with 5 numbers after the decimal point
	
	return 0;
}
