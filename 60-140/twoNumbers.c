/*Prints out two-digit number in words*/

#include <stdio.h>

int main()
{
	int num, first_dig, second_dig;
	
	printf("Enter a two-digit number: ");
	scanf("%d", &num);
	
	first_dig = num / 10;		//Gets first digit of number entered by the user
	second_dig = num % 10;		//Gets second digit of number entered by the user
	
	switch(first_dig)
	{
		case 1:
			switch(second_dig)	//special cases: 11 to 19
			{
				case 1:
				printf("you entered the number eleven.\n");
				break;
				case 2:
				printf("you entered the number twelve.\n");
				break;
				case 3:
				printf("you entered the number thirteen.\n");
				break;
				case 4:
				printf("you entered the number fourteen.\n");
				break;
				case 5:
				printf("you entered the number fifteen.\n");
				break;
				case 6:
				printf("you entered the number sixteen.\n");
				break;
				case 7:
				printf("you entered the number seventeen.\n");
				break;
				case 8:
				printf("you entered the number eighteen.\n");
				break;
				case 9:
				printf("you entered the number nineteen.\n");
				break;
				
				default:
				printf("you entered the number ten.\n");
				break;
			}
			break;
		case 2:
			printf("you entered the number twenty");
			break;
		case 3:
			printf("you entered the number thirty");
			break;
		case 4:
			printf("you entered the number forty");
			break;
		case 5:
			printf("you entered the number fifty");
			break;
		case 6:
			printf("you entered the number sixty");
			break;
		case 7:
			printf("you entered the number seventy");
			break;
		case 8:
			printf("you entered the number eighty");
			break;
		case 9:
			printf("you entered the number ninety");
			break;
		default:													//When the first digit is 0, the number entered is not a two-digit number
			printf("you did not enter a two-digit number\n");
			return 0;												//Ends program 
	}
	
	if (first_dig > 1)												//Checks if number is a two-digit number before outputting second half of number in words
	{	
		switch(second_dig)
		{
			case 1:
			printf("-one.\n");
			printf("%d", first_dig);
			break;
			case 2:
			printf("-two.\n");
			break;
			case 3:
			printf("-three.\n");
			break;
			case 4:
			printf("-four.\n");
			break;
			case 5:
			printf("-five.\n");
			break;
			case 6:
			printf("-six.\n");
			break;
			case 7:
			printf("-seven.\n");
			break;
			case 8:
			printf("-eight.\n");
			break;
			case 9:
			printf("-nine.\n");
			break;
		
			default:												//If the second digit is 0, print a period and make a new line
			printf(".\n");
		}
	}
		
	else 
	{
		return 0;
	}
	
return 0;
}
	
	
	
