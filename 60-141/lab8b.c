/*	
	Title: lab8b.c
	Author: Samar El-Houssami
	Date last modified: 03/12/2017
	Objective: modify file to capitalize first and last name
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	int GPA;
};
typedef struct employee Employee;

void WordCap(char *word);

int main()
{
	Employee EmpList[3];	//list of employees
	char ch;
	
	FILE *cfPtr;	//open file
	
	if ((cfPtr = fopen("employee.dat", "r")) == NULL)
		puts("File could not be opened.");
	
	else {
		for(int i = 0; i < 3; i++)
		{
			//read all 3 employee info and put them into array of struct
			fscanf(cfPtr, "%d %40s %40s %d\n", &EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, &EmpList[i].GPA);
			WordCap(EmpList[i].firstname); //capitalize first letter of first name
			WordCap(EmpList[i].lastname);  //capitalize first letter of last name
		}
		
			//open file (blank)
			cfPtr = fopen("employee.dat", "w");
			
			//print info into file
			for(int i = 0; i < 3; i++)
				fprintf(cfPtr, "%d %s %s %d\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);		
	}

	fclose(cfPtr);

	return 0;
}

// Input: string
// Objective: Capitalize first letter of a word
// Output: none
void WordCap(char *word)
{
	word[0] = toupper(word[0]);
	return;
}


