/*	
	Title: lab6.c
	Date last modified: 02/28/2017
	Objective: Uses strings and pointers to strings
	
*/
	
//Includes
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//Prototypes
void Reverse(char[]);			//Reverses sentence
void ParseSentence(char[]);		//Splits sentence and puts each word on a separate line


int main()
{
	
	char buffer1[] = {'t','h','i','s',' ','i','s',' ','t','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'};
	char buffer2[] = "this is the second buffer";
	char sentence[] = "hello world, how are you today.";
	char buffer3[80];
	char *pBuffer = buffer3;
	
	printf("Initialize buffer3: ");
	scanf("%[^\n]s", buffer3);
	printf("\n");
	
	printf("buffer1: %s\nbuffer2: %s\nbuffer3: %s\n", buffer1, buffer2, buffer3);
	
	printf("\n");
	printf("buffer3 using *pBuffer: ");
	
	while(*pBuffer != '\0')
		printf("%c", *(pBuffer++));
	
	printf("\n\n");
	
	printf("buffer1 before reversing: %s\n", buffer1);
	Reverse(buffer1);
	printf("buffer1 after reversing: %s\n", buffer1);
	
	printf("\n");
	
	printf("ParseSentence of: %s\n", sentence);
	ParseSentence(sentence);
	
	
	return 0;
}

/********************************
Objective: Reverses elements in array
Input: An array
Output: none
*********************************/
void Reverse(char string[])
{
	char temp;
		
	for (int i = 0; i < (24/2); i++)
	{
		temp = string[i];
		string[i] = string[24-i-1];
		string[24-i-1] = temp;
	}
	
}
/********************************
Objective: Extracts each word and
		   puts in on a new line
Input: An array
Output: Each word on a new line
*********************************/
void ParseSentence(char string[])
{
	int i = 0;
	
	do {
		for (;isalpha(string[i]) || string[i] == ' '; i++)
		{
			printf("%c", string[i]);
	
			if (string[i] == ' ')
				printf("\n");
		}
		
		if (!isalpha(string[i]))
			i++;
		
		if (string[i] == '\0')
			printf("\n");
		
	} while (string[i] != '\0');
}


