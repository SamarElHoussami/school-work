/* Evaluates a simple expression */

#include <stdio.h>

int main()
{
	double num1, num2, total;
	char op; 
	
	printf("Enter two numbers separated by an operator (+,-,*,/): \n");
	scanf("%lf %c %lf", &num1, &op, &num2);
	
	switch(op)
	{
	case '+':
		total = num1 + num2;
		printf("%.2lf + %.2lf = %.2lf\n", num1, num2, total);
		break;
	case '-':
		total = num1 - num2;
		printf("%.2lf - %.2lf = %.2lf\n", num1, num2, total);
		break;
	case '*':
		total = num1 * num2;
		printf("%.2lf * %.2lf = %.2lf\n", num1, num2, total);
		break;
	case '/':
		if (num2 != 0) {
			total = num1 / num2;
			printf("%.2lf / %.2lf = %.2lf\n", num1, num2, total);
		}
		else 
			printf("can't divide a number by 0.\n");
		
		break;
		
	default:
		printf("Unknown operator!\n");
	}
	
return 0;	
	
}