#include <stdio.h>

#define MAX 10
struct bigNumber {
	char digit[MAX];
};

//prototype
void Shift_bigNumber(struct bigNumber, struct bigNumber*, unsigned int);

int main()
{
	struct bigNumber N1 = {'2','0','5','7','3','1','4','0','9','1'};
	struct bigNumber N2;
	unsigned int R = 4;
	Shift_bigNumber(N1, &N2, R);
	
	for(int i = 0; i < MAX; i++)
		printf("%c ", N2.digit[i]);
	
	return 0;
}

void Shift_bigNumber(struct bigNumber N1, struct bigNumber *N2, unsigned int R)
{
	for(int i = 0; i < MAX; i++)
	{
		if(i<R)
			N2->digit[MAX-R+i] = N1.digit[i];
		
		else
			N2->digit[i-R] = N1.digit[i];
	}
	
	return;
}