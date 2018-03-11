#include <stdio.h>

int main()
{
	float epsilon;
	float eps = 0.0;
	float term = 1.0;
	int i = 1;
	int fact = 1;
	
	printf("Enter a small float value for epsilon: ");
	scanf("%f", &epsilon);
	
	while (term > epsilon)
	{
		eps += term;
		fact *= i;
		i += 1;
		term = (double)1/fact;
	}
	
	printf("Approximation of e: %.4f\n", eps);
	
	return 0;
}