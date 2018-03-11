/*Lab 03 - Finding Check Digit
   Author: Samar El-Houssami
   Date: 10/09/2016*/

#include <stdio.h>

int main()
{
	
	int i10, i9, i8, i7, i6, i5, i4, i3, i2;
	int sumOfProd, remainder, checkDigit;
	
	
	//divides the 9-digit number into 9 1-digit numbers
	//and assigns them to separate values based on their order
	
	printf("Enter the first 9 digits of ISBN: \n");
	scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i10, &i9, &i8, &i7, &i6, &i5, &i4, &i3, &i2);
	
	
	//calculates the sum of the products
	
	sumOfProd = (i10 * 10) + (i9 * 9) + (i8 * 8) + (i7 * 7) + (i6 * 6) + (i5 * 5) + (i4 *4) + (i3 * 3) + (i2 * 2);
	
	
	//calculates the remainder after dividing by 11
	
	remainder = sumOfProd % 11;
	
	
	//calculates the check digit and multiplies by -1 
	//to get a positive number
	
	checkDigit = (remainder - 11) * (-1);
	
	if (checkDigit == 10)
		printf("Check digit: X\n");
	
	else
	printf("Check digit: %d\n", checkDigit);
	
	return 0;
	
}