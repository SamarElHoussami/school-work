/*Lab 02 - Part A
   Author: Samar El-Houssami
   Date: 10/05/2016*/

#include <stdio.h>

int main()
{
	int item_number, month, day, year;	//initiate int and float variables
	float unit_price;
	
	printf("Enter item number: ");
	scanf("%d", &item_number); 		//scan item number entered by user and assign
	
	printf("Enter unit price: ");
	scanf("%f", &unit_price);			//scan unit price entered by user and assign 
	
	printf("Enter purchase date (mm/dd/yyyy): ");
	scanf("%d/%d/%d", &month, &day, &year);			//scan date entered by user and assign
	
	//formatted output
	
	printf("Item\tUnit\tPurchase\n\tPrice\tDate\n----\t------\t--------------\n");
	printf("%-d\t$%4.2f\t%02d/%02d/%02d\n", item_number, unit_price, month, day, year);

	return 0;
	
}
