/*	
	Title: lab8.c
	Author: Samar El-Houssami
	Date last modified: 03/20/2017
	Objective: Input data of employee records and save into a file using binary file
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
	char firstname[40];
	char lastname[40];
	int id;
	float GPA;
};
typedef struct employee Employee;

void InputEmpRecord(Employee *EmpList);
void PrintEmpList(const Employee *EmpList);
void SaveEmpList(const Employee *EmpList, const char *FileName);

int main()
{
	Employee EmpList[4];
	InputEmpRecord(EmpList);
	PrintEmpList(EmpList);
	SaveEmpList(EmpList, "employeeDA.dat");
	
	return 0;
}


// Input: Employee list
// Objective: Input the employee data interactively from the keyboard
// Output: updated list of employees
void InputEmpRecord(Employee *EmpList)
{
	printf("Enter employee's:\n");
	printf("ID FIRSTNAME LASTNAME GPA\n");
	
	//read employee info into array of structs
	for(int i = 0; i < 4; i++)
		scanf("%d %40s %40s %f", &EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, &EmpList[i].GPA);
	
	
	printf("\n");
	return;
}

// Input: Employee list
// Objective: Display the contents of Employee records from the list
// Output: list of employees
void PrintEmpList(const Employee *EmpList)
{
	printf("ID\tFIRSTNAME\tLASTNAME\tGPA\n");
	for(int i = 0; i < 4; i++)
		printf("%d\t%-12s\t%-12s\t%.2f\n", EmpList[i].id, EmpList[i].firstname, EmpList[i].lastname, EmpList[i].GPA);
	
	return;
}

// Input: Employee list, file name
// Objective: Save the employee records from the list to the newly created text file specified by FileName
// Output: new file with list of employees
void SaveEmpList(const Employee *EmpList, const char *FileName)
{
	FILE *cfPtr;	//file pointer
	cfPtr = fopen(FileName, "wb");	//open file
	
	if((cfPtr) == NULL)
		puts("File could not be opened.");
	
	else {
		//print list of structs
		fwrite(EmpList, sizeof(struct employee), 4, cfPtr);
	
	fclose(cfPtr);
	}
	
	return;
}