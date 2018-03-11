/* finds the largest and smallest of four integers */ 

#include <stdio.h>

int main()
{
	int numbers[4];
	int largest, smallest;
	
	printf("Enter four integers: ");
	scanf("%d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3]);
	
	largest = numbers[1];
	smallest = numbers[1];
	
for (int i = 0; i < 4; i++) {	//repeats 4 times
	if (numbers[i] > largest) {	//loops through 4 numbers entered and checks if each is largest
		largest = numbers[i];	//if number is bigger than the one before it, assign to largest
	}
	else if (numbers[i] < smallest){ //if number isn't the largest, check if it's the smallest
		smallest = numbers[i];		//if it is smaller than the one before it, assign to smallest
	}
	}
	
	printf("The largest number is: %d and the smallest number is: %d\n", largest, smallest);
	
	return 0;
}