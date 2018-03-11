#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int GPAFreq[4] = {0};
	srand( time(NULL) );
	int gpa, students, number = 1;
	
	printf("Enter the number of students:\t");
	scanf("%d", &students);
	
	for (int i = 0; i < students; i++) {
		gpa = rand ( ) % 5; //random number between 0 and 5
		
		printf("GPA of student #%d is:\t%d\n", number, gpa);
		
		if (gpa > 4 || gpa < 1) {
			printf("invalid number!\n");
			i--;
		}
		
		else {
			GPAFreq[--gpa]++;
			number++;
		}
	}
	
	printf("\nThe total number of students is %d.\n", students);
	printf("GPA 1 -- %d student(s)\nGPA 2 -- %d student(s)\n", GPAFreq[0], GPAFreq[1]);
	printf("GPA 3 -- %d student(s)\nGPA 4 -- %d student(s)\n", GPAFreq[2], GPAFreq[3]);
	
	return 0;
		
}