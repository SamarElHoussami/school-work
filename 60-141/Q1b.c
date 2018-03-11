#include <stdio.h>
#include <stdlib.h>

#define MAX 10
struct bigNumber {
	char digit[MAX];
};

//prototype
void Add_bigNumber(struct bigNumber, struct bigNumber, struct bigNumber *);

int main()
{
	struct bigNumber N1 = {'0','0','0','9','3','1','4','0','9','1'};
	struct bigNumber N2 = {'0','0','0','4','1','7','4','2','6','5'};
	struct bigNumber N3 = {'0','0','0','0','0','0','0','0','0','0'};
	Add_bigNumber(N1, N2, &N3);
	
	for(int i = 0; i < MAX; i++)
		printf("%c ", N3.digit[i]);
	
	return 0;
}

void Add_bigNumber(struct bigNumber N1, struct bigNumber N2, struct bigNumber *N3)
{
	int hold = 0;
	
	for(int i = MAX-1; i >= 0 ; i--)
	{
		int num1 = N1.digit[i] - '0';
		int num2 = N2.digit[i] - '0';
		
		if((num1 + num2 + hold) > 9)
		{
			N3->digit[i] = (char)( ((num1 + num2 + hold) % 10) + '0');
			hold = (int)((num1 + num2 + hold) / 10);
		}
		
		else
		{
			N3->digit[i] = (char)((num1 + num2 + hold) + '0');
			hold = 0;	
		}	
	}
	
	return;
}