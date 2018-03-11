#include<stdio.h>

int main()
{
	int array[3];
	
	printf("Enter three numbers separated by commas: \n");
	scanf("%d, %d, %d", &array[0], &array[1], &array[2]);
	
	int biggestNumber = array[0];
	
	for (int i = 0; i < 3; i++) {
		if (array[i] > biggestNumber) { //if any other number from the array is bigger
			biggestNumber = array[i];   //than the first one then that's the biggest num
		}
	}	
	
	printf("The biggest number is: %d\n", biggestNumber); 
	//no need for else statement cause if not then biggestNumber = array[0]
	
	return 0;
}