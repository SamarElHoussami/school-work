#include<stdio.h>

int main(void)
{
	int a;
	int b;
	int c;
	
	printf("Enter the first number: ");
	scanf("%d", &a);
	printf("Enter the second number: ");
	scanf("%d", &b);
	
	printf("Before swapping, the first number was %d and the second number was %d.\n", a, b);
	
	c = a;
	a = b;
	b = c;

	printf("After swapping, the first number is %d and the second number is %d.\n", a, b);	
	
	return 0;
}
	