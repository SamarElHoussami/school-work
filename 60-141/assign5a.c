/*	
	Title: Assign4.c
	Date last modified: 03/26/2017
	Objective: use string processing functions to properly format a 
	Comma Separated Values (csv) file of course Information and store them 
	into an array of structures
	
*/
	
//Includes
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct CourseInfo{
	int courseID;
	char courseName[30];
} courseInfo;


typedef struct StudentInfo{ 
	char StudentID[20];
	char firstName[20]; 
	char lastName[25]; 
	int numberCourses;
	courseInfo courses[10];
	struct StudentInfo *next;
} studentInfo;

//Prototypes
void loadStudentInfo(studentInfo **SLIST);
void storeInList(char *, char *, char *, int, courseInfo[], studentInfo **SLIST);
void saveStudentInfo(studentInfo *SLIST);
void displayStrudentInfo(studentInfo *SLIST);
void addStudent(studentInfo **SLIST);
void searchStudentID(studentInfo *SLIST);
void searchStudentlName(studentInfo *SLIST);
void deleteStudent(studentInfo **SLIST);
void exit();

int main()
{
	studentInfo *SLIST = NULL;
	int select;
	
	//loadStudentInfo(&SLIST);

	//display menu
	do {
		printf("\n\nSelect a menu option:\n");
		printf("1. Add new student\n");
		printf("2. Delete a student\n");
		printf("3. Search for a student\n");
		printf("4. Display current students\n");
		printf("5. Save student information to a file\n");
		printf("6. Exit\n\n");	
		
		scanf("%d", &select);
		
		while (select < 1 || select > 6)
		{
			printf("Invalid input\n");
			scanf("%d", &select);
		}
		
		switch(select)
		{
		case 1: addStudent(&SLIST);
				break;
		case 2: deleteStudent(&SLIST);
				break;
		case 3: searchStudentlName(SLIST);
				break;
		case 4: displayStrudentInfo(SLIST);
				break;
		//case 5: saveStudentInfo();
		//		break;
		//case 6: Exit();
		//		break;
		}

	} while (select != 6);
	
	return 0;
}

void loadStudentInfo(studentInfo **SLIST)
{
	char StudentID[10];
	char firstName[20]; 
	char lastName[25]; 
	int numberCourses;
	courseInfo courses[10];
	char line[100];
	
	int next = 0;
	
	FILE *fptr;
	
	if((fptr = fopen("studentList.txt","r")) == NULL)	
		printf("File could not be opened.\n");
	
	else
	{
		fscanf(fptr, "%20s\n", line);
	
		while(strcmp(line, "***") != 0)
		{
			switch(next)
			{
				case 0: strcpy(StudentID, line);
						break;
				case 1: strcpy(firstName, line);
						break;
				case 2: strcpy(lastName, line);
						break;
				case 3: numberCourses = atoi(line);
						break;
				case 4: for(int i = 0; i < numberCourses; i++)	
							fscanf(fptr, "%s %d\n", courses[i].courseName, &courses[i].courseID);
						break;
			}
			
	
			if(next == 4)
			{
				storeInList(StudentID, firstName, lastName, numberCourses, courses, SLIST);	
				next = 0; //reset for every student
				fscanf(fptr, "%s\n", line);	//read next line
			}
		
			else
			{
				next++;
		
				if(next != 4)
					fscanf(fptr, "%s\n", line);
			}
		}
	}

	fclose(fptr); 
} 

// Objective: Prints every course information.
// Input: void
// Output: none

void storeInList(char sID[9], char fName[20], char lName[25], int numCourses, courseInfo nCourses[10], studentInfo **SLIST)
{
	studentInfo *aStudent = (studentInfo *) malloc(sizeof(studentInfo));
	
	strcpy(aStudent->StudentID, sID);
	strcpy(aStudent->firstName, fName);
	strcpy(aStudent->lastName, lName);
	aStudent->numberCourses = numCourses;
	
	for(int i = 0; i < (aStudent->numberCourses); i++)
	{
		aStudent->courses[i].courseID = nCourses[i].courseID;
		strcpy(aStudent->courses[i].courseName, nCourses[i].courseName);
	}	
	
	if (SLIST == NULL)
		 return;
	
		 studentInfo *pStudent = *SLIST;

    while(pStudent->next != NULL)
        pStudent = pStudent->next;

    pStudent->next = aStudent;

} 

// Objective: Add a new course with unique CourseID and CourseCode
// Input: Three character arrays
// Output: none

void displayStrudentInfo(studentInfo *SLIST)
{
	int k = 1;
	while(SLIST != NULL) {
		printf("Student %d:\n", k);
        printf("%s\n%s\n%s\n%d\n", SLIST->StudentID, SLIST->firstName, SLIST->lastName, SLIST->numberCourses);
       
	   for(int i = 0; i < (SLIST->numberCourses); i++)
		   printf("%s %d\n", SLIST->courses[i].courseName, SLIST->courses[i].courseID);
	  
	  SLIST = SLIST->next;
	  printf("\n");
	  
	  k++;
    }

	return;

}

// Objective: Search for course information using courseID or course Name
// Input: menu option
// Output: none

void searchStudentID(studentInfo *SLIST)
{
	char searchID[9];
	printf("Enter student's ID:  ");
	scanf("%s", searchID);
	
	while(SLIST != NULL)
	{
		if(strcmp(SLIST->StudentID, searchID) == 0)
		{
			printf("%s\n%s\n%s\n%d\n", SLIST->StudentID, SLIST->firstName, SLIST->lastName, SLIST->numberCourses);
			for(int i = 0; i < SLIST->numberCourses; i++)
				printf("%s %d\n", SLIST->courses[i].courseName, SLIST->courses[i].courseID);
		return;
		}
		SLIST = SLIST->next;
	}
	
	printf("Student not found.");
	return;
}

void searchStudentlName(studentInfo *SLIST)
{
	char searchName[25];
	printf("Enter student's last name:  ");
	scanf("%s", searchName);
	
	while(SLIST != NULL)
	{	
		if(strcmp(SLIST->lastName, searchName) == 0)
		{
			printf("Results:\n");
			printf("%s\n%s\n%s\n%d\n", SLIST->StudentID, SLIST->firstName, SLIST->lastName, SLIST->numberCourses);
			for(int i = 0; i < SLIST->numberCourses; i++)
				printf("%s %d\n", SLIST->courses[i].courseName, SLIST->courses[i].courseID);
		return;
		}
		
		SLIST = SLIST->next;
	}
	
	printf("Student not found.");
	return;
}

void addStudent(studentInfo **SLIST)
{
	studentInfo *aStudent = (studentInfo *) malloc(sizeof(studentInfo));
	
	printf("Adding new student:\n");
	printf("Student ID: ");
	scanf("%s", aStudent->StudentID);
	printf("First name: ");
	scanf("%s", aStudent->firstName);
	printf("Last name: ");
	scanf("%s", aStudent->lastName);
	printf("Number of courses: ");
	scanf("%d", &(aStudent->numberCourses));
	for(int i = 0; i < (aStudent->numberCourses); i++)
	{
		printf("Course ID: ");
		scanf("%d", &(aStudent->courses[i].courseID));
		printf("Course Name: ");
		scanf("%s", aStudent->courses[i].courseName);
	}	
	
	 if (SLIST == NULL) 
		 return;

    studentInfo *pStudent = *SLIST;
	studentInfo *temp;

	int flag = 0;
   
   while(1)
	{
				//the new student ID < the first student ID in SLIST
		if((strcmp(aStudent->StudentID, pStudent->StudentID) <= 0) && (flag == 0)) 
		{
			*SLIST = aStudent;
			aStudent->next = pStudent;	
			break;
		}
				//the new student ID > the current student ID in SLIST
		else if(strcmp(aStudent->StudentID, pStudent->StudentID) >= 0)
		{
			//the current student is the last one in SLIST
			if(pStudent->next == NULL)
		{
			pStudent->next = aStudent;
			break;
		}
			//the new student ID < the next student ID in SLIST
			else if(strcmp(aStudent->StudentID, (pStudent->next)->StudentID) < 0)
			{
			temp->next = pStudent->next;
			pStudent->next = aStudent;
			aStudent->next = temp->next;
			break;
			}
		}
		
		pStudent = pStudent->next;
		flag++;
	}
	
	//free(aStudent);
        
	return;
}

void deleteStudent(studentInfo **SLIST)
{
	char searchID[10];
	printf("Student ID: ");
	scanf("%s", searchID);
	
	studentInfo *temp = *SLIST, *prev;
	
	if(strcmp(temp->StudentID, searchID) == 0)
	{
		*SLIST = temp->next;
		free(temp);
		return;
	}
	
	while(temp != NULL && strcmp(temp->StudentID, searchID) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	
	if (temp == NULL) 
	{
		printf("Student not found.");
		return;
	}
	
	prev->next = temp->next;
	
	free(temp);
}
