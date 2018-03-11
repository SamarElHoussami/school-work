#include <stdio.h>

int main()
{
	int tries = 1; 
	int code_1, code_2, check;
	
	do {
		printf("Enter pin code (attempt %d):\t", tries);
		scanf("%d", &code_1);
		printf("\n");
		
		if (code_1 <= 99999 && code_1 > 9999)	//checks is code is 5 digits
		{
			int i = 5;
			code_2 = code_1;
			check = code_1 % 10;		//sets check to last digit of code entered
			
			while (i > 0){				//checks if each digit is divisible by 3
				
				if ((check != 0) && ((check % 3) == 0))	//if check/3 and check != 0
				{
					code_2/= 10;
					check = code_2 % 10;	//sets check to second, third, fourth, fifth last numbers
					i--;
				}
				else		//a digit is not divisible by 3
				{
					printf("Code %d is invalid!\n", code_1);
					tries++;
					i = -1;		//breaks while loop and asks for another code
				}
			}
			
			if (i != -1)		//if all the digits are divisible by 3
			{
				printf("Code %d is success!\n", code_1);
				return 0;
			}
			
		}
		
		else 
		{
			printf("Code %d is invalid!\n", code_1);
			tries++;
		}
		
	} while (tries <= 6);
	
	if (tries > 6)
		printf("Intruder alert!\n");
		
	return 0;
}