#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//structure definition
typedef struct student{
	int sid;
	char name[50];
	float gpa;
	struct student *next;
} student;

//global variables
student *SLIST = NULL;
int num_students = 0;

//function prototypes
void readRecords();
void loadRecords(int, char[], float);
void displayRecords(student *);
//void saveRecords();

//main
int main()
{
	readRecords();
	displayRecords(SLIST);
	//saveRecords();
	
	return 0;
}

void readRecords()
{
	FILE *fptr;
	
	char *tok;
	char name[50];
	int sid;
	char line[100];
	float gpa;
	
	int next = 0;

	if((fptr = fopen("employeelist.dat","r")) == NULL)	
		printf("File could not be opened.\n");
	
	else
	{
	
	//read every line
	while (fscanf(fptr, "%d %s %f\n", &sid, name, &gpa) != EOF)
		loadRecords(sid, name, gpa);
	
	fclose(fptr); 
	}
	return;
}

void loadRecords(int aSid, char aName[50], float aGpa)
{
	student *aStudent = (student*)malloc(sizeof(student));
	
	aStudent->sid = aSid;
	strcpy(aStudent->name, aName);
	aStudent->gpa = aGpa;
	
	if(SLIST == NULL)
	{
		SLIST = aStudent;
		return;
	}
	
	else
	{
		student *pStudent, *nextStudent;
		pStudent = SLIST;
		nextStudent = pStudent->next;
		
		while(pStudent != NULL)
		{
			if(aStudent->sid <= pStudent->sid)
			{
				SLIST = aStudent;
				aStudent->next = pStudent;
				return;
			}
			
			else if(nextStudent != NULL)
			{
				if(aStudent->sid <= nextStudent->sid)
				{
					pStudent->next = aStudent;
					aStudent->next = nextStudent;
					return;
				}
			}
			
			else if(nextStudent == NULL)
			{
				pStudent->next = aStudent;
				return;
			}
					
			pStudent = nextStudent;
			nextStudent = pStudent->next;
		}
	}
}



void displayRecords(student *SLIST)
{
	if(SLIST == NULL)
		return;
	
	displayRecords(SLIST->next);
	
	char *tok = strtok(SLIST->name, "_");
	printf("%d %s ", SLIST->sid, tok);
	tok = strtok(NULL, " ");
	printf("%s %.2lf\n", tok, SLIST->gpa);
	
	return;
}
