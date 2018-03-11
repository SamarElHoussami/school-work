#include <stdio.h>

int main()
{
	
	int last_dig;
	long num;
		
		printf("Enter a number: ");
		scanf("%ld", &num);
		
		while (num > 0) {
			
		int seen_digit[10] = {0};
		
		while (num > 0) {
			last_dig = num % 10;
			if (seen_digit[last_dig] == 1)
				break;
			
			seen_digit[last_dig] = 1;
			num /= 10;
		}
		
		if (num > 0) 
			printf("Repeated digit.\n");
		else
			printf("No repeated digit.\n");
		
		printf("Enter a number: ");
		scanf("%d", &num);
		
	} 
	
	return 0;
}