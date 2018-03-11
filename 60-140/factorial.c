#include<stdio.h>

int main()
{
	int a;
	
	printf("Enter an integer: \n");
	scanf("%d", &a);
	
	int factorial = a;
	
	for (int i = (a-1); i > 1; i--) {
		factorial = factorial * i;
	}
	
	printf("%d! = %d\n", a, factorial);
}