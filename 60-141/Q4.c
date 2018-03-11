#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
char *FindToken(char*, char*);

int main()
{
	printf("%s", FindToken("are exams over yet?", "zypqt"));
	return 0;
}

char *FindToken(char *S, char *T)
{
	for(int i = 0; *(S+i) != '\0'; i++)
		for(int y = 0; *(T+y) != '\0'; y++)
			if(*(T+y) == *(S+i))
				return S+i;
		
	return NULL;
}