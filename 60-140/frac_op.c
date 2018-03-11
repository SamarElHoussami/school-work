#include <stdio.h>

int main()
{
		int top1, top2, bot1, bot2, finaltop, finalbot;
		char op;
		
		printf("Enter two fractions separated by an operator (+,-,*,/):\n");
		scanf("%d/%d %c %d/%d", &top1, &bot1, &op, &top2, &bot2);
		
			
		switch(op)
		{
			case '+':
			finaltop = (top1 * bot2) + (top2 * bot1);
			finalbot = (bot1 * bot2);
			printf("%d/%d + %d/%d = %d/%d\n", top1, bot1, top2, bot2, finaltop, finalbot);
			break;
			
			case '-':
			finaltop = (top1 * bot2) - (top2 * bot1);
			finalbot = (bot1 * bot2);
			printf("%d/%d - %d/%d = %d/%d\n", top1, bot1, top2, bot2, finaltop, finalbot);
			break;
			
			case '*':
			finaltop = (top1 * top2);
			finalbot = (bot1 * bot2);
			printf("%d/%d * %d/%d = %d/%d\n", top1, bot1, top2, bot2, finaltop, finalbot);
			break;
			
			case '/':
			if (bot1 != 0 && bot2 != 0)
			{
			finaltop = (top1 * bot2);
			finalbot = (bot1 * top2);
			printf("%d/%d / %d/%d = %d/%d\n", top1, bot1, top2, bot2, finaltop, finalbot);
			}
			else {
				printf("Can't divide by 0!\n");
			}
			break;
			
			default:
				printf("Invalid operator.\n");
		}
		
		
		return 0;
}