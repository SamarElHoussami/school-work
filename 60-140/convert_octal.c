/* Displays integer in octal */

#include <stdio.h>

int main()
{
	int orig_num;
	int octal[5];
	
	printf("Enter a number between 0 and 32767: ");
	scanf("%d", &orig_num);
	
	for (int i = 4; i >= 0; --i) //repeats 5 times for 5 digits of the octal 
	{ 
		octal[i] = orig_num % 8; //finds the remainder of orig_num / 8 and assigns it to the ith digit of the octal array, starting at 4 (the last one)
		orig_num = orig_num / 8; //divides orig_num by 8 
	}
	
	printf("In octal, your number is: %1d%1d%1d%1d%1d\n", octal[0], octal[1], octal[2], octal[3], octal[4]);
	
	return 0;
	
}