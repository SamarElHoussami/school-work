#include <stdio.h>

int main()
{
	int grade;
	
	do {
		printf("Enter a grade between 0 and 4: \n");
		scanf("%d", &grade);
		
		if (grade < 0 || grade > 4)
			printf("%d Invalid", grade);
		
		else if (grade < 2)
			printf("%d Fail", grade);
		
		else 
			printf("%d Pass", grade);
	}
	
	while (grade != 0);
	
	if (grade == 0)
		printf("Get help!");
	
	return 0;
}