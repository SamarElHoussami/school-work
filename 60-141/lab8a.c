/*	
	Title: lab8.c
	Author: Samar El-Houssami
	Date last modified: 03/12/2017
	Objective: Input data of employee records and save into a file
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	int GPA;
};
typedef struct employee Employee;

void InputEmpRecord(Employee *EmpList);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);

int main()
{
	Employee EmpList[3];
	InputEmpRecord(EmpList);
	PrintEmpList(EmpList);
	SaveEmpList(EmpList, "employee.dat");
	
	return 0;
}


// Input: Employee list
// Objective: Input the employee data interactively from the keyboard
// Output: updated list of employees
void InputEmpRecord(Employee *EmpList)
{
	printf("Enter employee's:\n");
	printf("\tID FIRSTNAME LASTNAME GPA\n");
	for(int i = 0; i < 3; i++)
	{
		printf("%d:\t", (i+1));
		//read employee info into array of structs
		scanf("%d %40s %40s %d", &EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, &EmpList[i].GPA);
	}
	
	printf("\n");
	return;
}

// Input: Employee list
// Objective: Display the contents of Employee records from the list
// Output: list of employees
void PrintEmpList(const Employee *EmpList)
{
	printf("ID\tFIRSTNAME\tLASTNAME\tGPA\n");
	//print employee info on screen
	for(int i = 0; i < 3; i++)
		printf("%d\t%-12s\t%-12s\t%d\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
	
	return;
}

// Input: Employee list, file name
// Objective: Save the employee records from the list to the newly created text file specified by FileName
// Output: new file with list of employees
void SaveEmpList(const Employee *EmpList, const char *FileName)
{
	FILE *cfPtr;	//open file
	
	if((cfPtr = fopen(FileName, "w")) == NULL)
		puts("File could not be opened.");
	
	else {
		for(int i = 0; i < 3; i++)
			fprintf(cfPtr, "%d %s %s %d\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
	
	fclose(cfPtr);
	}
	
	return;
}