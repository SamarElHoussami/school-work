#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//prototypes
char *FindSubstring(char*, char*);

int main()
{
	printf("%c", *FindSubstring("exams are over soon", "over"));
	return 0;
}

char *FindSubstring(char *S, char *T)
{
	int flag = 1;
	
	for(int i = 0, y = 0; *(S+i) != '\0'; i++)
	{
		if(*(T+y) == *(S+i))
		{
			int p = i;
			
			while(*(T+y) != '\0')
			{
				if(*(T+(y++)) != *(S+(p++)))
					flag = 0;
			}
			
			if (flag == 1)
				return S+i;
			else
				y = 0;
		}
	}
		
	return NULL;
}