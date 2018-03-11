#include <stdio.h>

int main() {
	
	int change, quarters, dimes, nickels, pennies;
	
	printf("Please enter the amount for change in the range from 0 to 99 cents: \n");
	scanf("%d", &change);
	
	//if, switch, do, for
	
	
		
		/*if (change > 0 && change < 5)
		printf("The change is %d penny/pennies.\n", change);
		
		else if (change >= 5 && change < 10) {
		nickels = change / 5;
		pennies = change % 5;
		printf("The change is %d nickel(s), and %d penny/pennies.\n", nickels, pennies); 
		}
		
		else if (change >= 10 && change < 25){
		dimes = change / 10;
		nickels = (change - (10 * dimes)) / 5;
		pennies = (change - (10 * dimes)) % 5;
		printf("The change is %d dime(s), %d nickel(s), and %d penny/pennies.\n", dimes, nickels, pennies);
		}
		
		else if (change >= 25 && change <= 99){
		quarters = change / 25;
		dimes = (change - (25 * quarters)) / 10;
		nickels = (change - (25 * quarters) - (10 * dimes)) / 5;
		pennies = (change - (10 * dimes)) % 5;
		printf("The change is %d quarter(s), %d dime(s), %d nickel(s), and %d penny/pennies.\n", quarters, dimes, nickels, pennies);
		}
		*/
		
		else if (change == 0)
		printf("There is no change.\n");
	
	return 0;
	
	
}