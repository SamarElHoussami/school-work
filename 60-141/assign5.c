/*	
	Title: Assign5.c
	Date last modified: 03/29/2017
	Objective: Create a linked list of student information and allow user to add, delete, and search
			   for students using menu options.
	
	
*/
	
//Includes
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//Structs
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
studentInfo *loadStudentInfo(studentInfo *SLIST);
studentInfo *storeInList(char *, char *, char *, int, courseInfo[], studentInfo *SLIST);
void saveStudentInfo(studentInfo *SLIST);
void displayStrudentInfo(studentInfo *SLIST);
studentInfo *addStudent(studentInfo *SLIST);
void searchStudentID(studentInfo *SLIST);
void searchStudentlName(studentInfo *SLIST);
void deleteStudent(studentInfo **SLIST);
void Exit();

int main()
{
	studentInfo *SLIST = NULL;	//empty struct pointer
	
	int select;	//menu selection
	
	SLIST = loadStudentInfo(SLIST);

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
		case 1: SLIST = addStudent(SLIST);
				break;
		case 2: deleteStudent(&SLIST);
				break;
		case 3: searchStudentlName(SLIST);
				break;
		case 4: displayStrudentInfo(SLIST);
				break;
		case 5: saveStudentInfo(SLIST);
				break;
		case 6: Exit(SLIST);
				break;
		}

	} while (select != 6);
	
	if(SLIST)
		free(SLIST);
	
	return 0;
}

// Objective: read the student information from a file
// Input: pointer to linked list
// Output: modified list of student information
studentInfo *loadStudentInfo(studentInfo *SLIST)
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
				SLIST = storeInList(StudentID, firstName, lastName, numberCourses, courses, SLIST);	
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

	//close file
	fclose(fptr); 
	
	return SLIST;
} 

// Objective: Store the student information from the file into the linked list
// Input: StudentID, firstName, lastName, number of courses, array of course structures, pointer to list
// Output: modified list of student information
studentInfo *storeInList(char sID[9], char fName[20], char lName[25], int numCourses, courseInfo nCourses[10], studentInfo *SLIST)
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
		 return aStudent;
	
		 studentInfo *pStudent = SLIST;

    while(pStudent->next != NULL)
        pStudent = pStudent->next;

    pStudent->next = aStudent;
	
	
return SLIST;

} 

// Objective: Print every node in the linked list
// Input: pointer to linked list
// Output: none
void displayStrudentInfo(studentInfo *SLIST)
{
	int k = 1;
	
	while(SLIST != NULL) {
		printf("Student %d:\n", k);
        printf("%s\n%s\n%s\n%d\n", SLIST->StudentID, SLIST->firstName, SLIST->lastName, SLIST->numberCourses);
       
	   for(int i = 0; i < (SLIST->numberCourses); i++)
		   printf("%s %d\n", SLIST->courses[i].courseName, SLIST->courses[i].courseID);
	  
	  //go to next node
	  SLIST = SLIST->next;
	  printf("\n");
	  
	  k++;
    }

	return;
}

// Objective: Search for a student information using a student ID and display information if student is found
// Input: pointer to linked list
// Output: none
void searchStudentID(studentInfo *SLIST)
{
	char searchID[9];
	printf("Enter student's ID:  ");
	scanf("%s", searchID);
	
	//search through entire list
	while(SLIST != NULL)
	{
		if(strcmp(SLIST->StudentID, searchID) == 0)
		{
			printf("%s\n%s\n%s\n%d\n", SLIST->StudentID, SLIST->firstName, SLIST->lastName, SLIST->numberCourses);
			for(int i = 0; i < SLIST->numberCourses; i++)
				printf("%s %d\n", SLIST->courses[i].courseName, SLIST->courses[i].courseID);
		return;
		}
		SLIST = SLIST->next;	//go to next node
	}
	
	printf("Student not found.");
	return;
}

// Objective: Search for a student information using a last name and display information if student is found
// Input: pointer to linked list
// Output: none
void searchStudentlName(studentInfo *SLIST)
{
	char searchName[25];
	printf("Enter student's last name:  ");
	scanf("%s", searchName);
	
	//search through entire list
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
		
		SLIST = SLIST->next;	//go to next node
	}
	
	printf("Student not found.");
	return;
}

// Objective: add a student into the linked list using the student ID to make it in increasing order
// Input: pointer to linked list
// Output: modified list of student information
studentInfo *addStudent(studentInfo *SLIST)
{
	studentInfo *aStudent = (studentInfo *) malloc(sizeof(studentInfo));
	
	//get student information from keyboard
	printf("Adding new student:\n");
	printf("Student ID: ");
	scanf("%s", aStudent->StudentID);
	
	//look for duplicate ID
	studentInfo *tStudent = SLIST;
	
	while(tStudent != NULL)
		
	{
		if(strcmp(tStudent->StudentID, aStudent->StudentID) == 0)
		{
			printf("Student ID already exists.\n");
			return SLIST;
		}
		
		tStudent = tStudent->next;
	}
	
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
		 return aStudent;

    studentInfo *pStudent = SLIST;
	studentInfo *temp;

	int flag = 0;
   
   //add student in increasing student ID order
   while(1)
	{
		//the new student ID < the first student ID in SLIST
		if((strcmp(aStudent->StudentID, pStudent->StudentID) <= 0) && (flag == 0)) 
		{
			//add student to top of list
			SLIST = aStudent;
			aStudent->next = pStudent;	
			break;
		}
		//the new student ID > the current student ID in SLIST
		else if(strcmp(aStudent->StudentID, pStudent->StudentID) >= 0)
		{
			//the current student is the last one in SLIST
			if(pStudent->next == NULL)
		{
			//add student to end of list
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
	        
	return SLIST;
}

// Objective: Search for a student using a student ID and delete student if found
// Input: pointer to linked list
// Output: none
void deleteStudent(studentInfo **SLIST)
{
	char searchID[10];
	printf("Student ID: ");
	scanf("%s", searchID);
	
	studentInfo *temp = *SLIST, *prev;
	
	//if the student information to be deleted is the first one on the list
	if(strcmp(temp->StudentID, searchID) == 0)
	{
		//make the head of list the next student info
		*SLIST = temp->next;
		free(temp);
		return;
	}
	
	//go through list until tempID = searchID
	while(temp != NULL && strcmp(temp->StudentID, searchID) != 0)
	{
		prev = temp;
		temp = temp->next;
	}
	
	//student not found
	if (temp == NULL) 
	{
		printf("Student not found.");
		return;
	}
	
	//skip temp
	prev->next = temp->next;
	
	//delete temp
	free(temp);
}

// Objective: Save student info list into file
// Input: pointer to linked list
// Output: none
void saveStudentInfo(studentInfo *SLIST)
{
	FILE *fptr;
	
	//open file
	if((fptr = fopen("studentList.txt","w")) == NULL)
		printf("Unable to open file.\n");
	
	else{
		//go through entire list and print each node
		while(SLIST != NULL) {
        fprintf(fptr, "%s\n%s\n%s\n%d\n", SLIST->StudentID, SLIST->firstName, SLIST->lastName, SLIST->numberCourses);
       
	   for(int i = 0; i < (SLIST->numberCourses); i++)
		   fprintf(fptr, "%s %d\n", SLIST->courses[i].courseName, SLIST->courses[i].courseID);
	  
	  SLIST = SLIST->next;
		}
	}
	
	fprintf(fptr, "***");
	return;
}

// Objective: Ask user to save list into file before exiting the program
// Input: pointer to linked list
// Output: none
void Exit(studentInfo *SLIST)
{
	char c[1];
	printf("Save student information to file before leaving? (Y/N): ");
	
	do{
		scanf("%s", c);
		c[0] = toupper(c[0]);
	
	//Save student list
	if(strcmp(c,"Y") == 0)
	{
		printf("Student List saved successfully.\nBye!\n");
		saveStudentInfo(SLIST);
	}
	//Don't save student list
	else if (strcmp(c,"N") == 0)
		printf("OK! Bye!\n");
	
	else
		printf("Invalid input.\n");
	} while((strcmp(c,"Y")) != 0 && (strcmp(c,"N") != 0));
	
	return;
}