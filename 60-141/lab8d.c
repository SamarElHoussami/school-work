/*	
	Title: lab8.c
	Author: Samar El-Houssami
	Date last modified: 03/12/2017
	Objective: define simple functions
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
};
typedef struct employee Employee;

void printList();
void sortList();

int main()
{
	printList();
	printf("\n");
	sortList();
	printList();

	return 0;
}
// Input: none
// Objective: Display the contents of Employee records from the list
// Output: list of employees
void printList()
{
	Employee Emp;
	
	FILE *cfPtr;
	
	if ((cfPtr = fopen("employeeDA.dat", "rb")) == NULL)
		puts("File could not be opened.");
	
	else {
		while( !feof(cfPtr) )
		{
			fread(&Emp, sizeof(struct employee), 1, cfPtr);
				while( !feof(cfPtr) )
				{
				printf("%d %s %s %.2f\n", Emp.id, Emp.firstname, Emp.lastname, Emp.GPA);
				fread(&Emp, 1, sizeof(struct employee), cfPtr);
				}
		}
		
		fclose(cfPtr);
	}
	
	return;
}

// Input: none
// Objective: Sort list of employees based on their GPA
// Output: sorted list of employees
void sortList()
{
	Employee Emp1, Emp2;
	size_t size = sizeof(struct employee);
	
	FILE *cfPtr;
	
	if ((cfPtr = fopen("employeeDA.dat", "rb+")) == NULL)
		puts("File could not be opened.");
	
	else {
		int flag = 1;
		while (flag) {
			
			flag = 0;
			fread(&Emp1, size, 1, cfPtr);	//cfPtr points to size bytes into file
			fread(&Emp2, size, 1, cfPtr);	//cfPtr points to (size*2) bytes into file
	
			while( !feof(cfPtr) ) {
					if (Emp1.GPA < Emp2.GPA)
					{
						fseek(cfPtr, -(size * 2), SEEK_CUR);	//move (size * 2) backwards to get to the beginning of both employee records
						fwrite(&Emp2, size, 1, cfPtr);			//write over Emp1 with Emp2
						fwrite(&Emp1, size, 1, cfPtr);			//write over Emp2 with Emp1
						flag = 1;
					}

				else
					Emp1 = Emp2;
				
				fread(&Emp2, size, 1, cfPtr);	//read next employee info
				}
				
				if (flag) rewind(cfPtr);
			}
		
		fclose(cfPtr);
		}
		
	return;
}
