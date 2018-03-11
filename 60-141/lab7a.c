/*	
	Title: lab7a.c
	Author: Samar El-Houssami
	Date last modified: 03/12/2017
	Objective: define simple functions
	
*/

//includes
#include<stdio.h>
#include<stdlib.h>

//prototypes
int AtoI ( const char * str1 );							//converts numeric string into an int
int StrCmp ( const char * str1, const char * str2 );	//Compare two strings
char *StrCpy ( char * str2, const char * str1 );		//copy string one into string two
char *StrCat ( char * str2, const char * str1 );		//add two strings together
char *StrChr ( char * str1, int ch );					//search for character in string

int main()
{
	int choice, result;
	char ch, str1[256], str2[256];

	printf("Enter a numeric string to convert: ");
	scanf(" %[^\n]", str1);
	printf("%s to integer = %d\n", str1, AtoI(str1));
	printf("\n");

	printf("Enter string 1: ");
	scanf(" %[^\n]", str1);
	printf("Enter string 2: ");
	scanf(" %[^\n]", str2);
	
	result = StrCmp(str1, str2);
	if(result > 0)
		printf("String 1 is greater than String 2.\n");
	else if(result < 0)
		printf("String 1 is less than String 2.\n");
	else
		printf("String 1 and String 2 are equal.\n");

	printf("\n");
	printf("Enter a string: ");
	scanf(" %[^\n]", str1);
	
	StrCpy(str2, str1);
	
	printf("Original string is: %s.\n", str1);
	printf("Copied  string  is: %s.\n", str2);

	printf("\n");
	printf("Enter string 1: ");
	scanf(" %[^\n]", str2);
	printf("Enter string 2: ");
	scanf(" %[^\n]", str1);
	StrCat(str2, str1);
	printf("String 1 + String 2: %s.\n", str2);
	printf("\n");

	printf("Enter a string: ");
	scanf(" %[^\n]", str1);
	printf("Enter a charcter to search: ");
	scanf(" %c", &ch);
	printf("Character %c %s in the string %s.\n", ch, StrChr(str1, ch)?"is":"is not", str1);
	printf("\n");

}

// Input: a pointer to a string
// Objective: converts numeric string into an int
// Output: converted numeric string or 0 if not available
int AtoI ( const char * str1 )
{
	int i = 0, num = 0;
	while(str1[i] != '\0')
	{
		if(str1[i] == '.') break;
		if(str1[i] >= '0' && str1[i] <= '9')
			num = (num*10) + str1[i] - '0';
		i++;
	}
	return num;
}

// Input: two string pointers
// Objective: Compare two strings
// Output: Which string is bigger
int StrCmp ( const char * str1, const char * str2 )
{
	int i = 0;
	while(str1[i] != '\0' && str2[i] != '\0')
	{
		if(str1[i] < str2[i]) return -1;
		if(str1[i] > str2[i]) return 1;
		i++;
	}
	
	if(str1[i] == '\0') return -1;	//if the first string ends first
	if(str2[i] == '\0') return 1;	//if the second string ends first
	
	return 0;
}

// Input: two string pointers
// Objective: copy string one into string two
// Output: string two after being overwritten by string one
char *StrCpy ( char * str2, const char * str1 )
{
	int i = 0;

	while(str1[i] != '\0')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';

	return str2;
}

// Input:two string pointers
// Objective: add two strings together
// Output: string one with string two added
char *StrCat ( char * str2, const char * str1 )
{
	int i = 0, j = 0;
	
	//find the length of first string
	while(str2[i] != '\0') i++;

	while(str1[j] != '\0')
		str2[i++] = str1[j++];
	
	str2[i] = '\0';

	return str2;
}

// Input: a string pointer
// Objective: search for character in string
// Output: The address of the character found in string, NULL otherwise
char *StrChr ( char * str1, int ch )
{
	int i = 0;
	
	while(str1[i] != ch && str1[i] != '\0') 
		i++;

	if(str1[i] == ch) return &str1[i];
	
	return NULL;
}