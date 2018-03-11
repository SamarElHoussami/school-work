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

struct CourseInfo{ 
	int courseID;
	char courseName[50]; 
	char courseCode[12]; 
	char Term[6];
};

typedef struct CourseInfo courseInfo;

//global variables
courseInfo courses[20];
int courseCount = 0;

//Prototypes
void loadCourseInfo();
void displayCourseInfo();
void addCourseInfo(char *, char *, char *);
void searchCourseInfo(int);
void displayMenu();
void addNewCourse();

int main()
{
	int select;

	loadCourseInfo();

	//display menu
	do {
		printf("\n\nSelect a menu option:\n");
		printf("1. Add new course\n");
		printf("2. Search for a course by course ID\n");
		printf("3. Search for a course by course Name\n");
		printf("4. Display courses\n");
		printf("5. Exit\n\n");	
		
		scanf("%d", &select);
		
		while (select < 1 || select > 5)
		{
			printf("Invalid input\n");
			scanf("%d", &select);
		}
		
		switch(select)
		{
		case 1: addNewCourse();
				break;
		case 2: searchCourseInfo(1);
				break;
		case 3: searchCourseInfo(2);
				break;
		case 4: displayCourseInfo();
				break;
		}

	} while (select != 5);
	
	return 0;
}

void loadCourseInfo()
{
	FILE *fptr;
	
	char *tok;
	char courseName[50];
	char courseCode[12];
	char line[100];
	char term[6];
	
	int next = 0;

	if((fptr = fopen("input.csv","r")) == NULL)	
		printf("File could not be opened.\n");
	
	else
	{
	
	//read every line
	while (fscanf(fptr, "%s\n", line) != EOF)
	{
		//split input using ","
		tok = strtok(line, ",");

		while(tok != NULL)
		{
			switch(next){
				case 0:
					strcpy(courseName, tok);
					break;
				case 1:
					strcpy(courseCode, tok);
					break;
				case 2:
					strcat(courseCode, tok);
					strcat(courseCode, "-");
					break;
				case 3:
					strcat(courseCode, tok);
					strcat(courseCode, "-");
					break;
				case 4:
					strcat(courseCode, tok);
					break;
				case 5:
					strcpy(term, tok);
					break;
				case 6:
					strcat(term, tok);
					break;
			}
			next++;
			tok = strtok(NULL, ",");
		}
		
		next = 0;	//resets for every line	

		addCourseInfo(courseName, courseCode, term);	//adds course every line
		
		}
	}
	
	fclose(fptr); 
	
	return;
} 

// Objective: Prints every course information.
// Input: void
// Output: none

void displayCourseInfo()
{
	printf("ID\tName\t\tCode\t\tTerm\n\n");

	for (int i = 0; i < courseCount; i++)
	{
			printf("%-8d", courses[i].courseID);
			printf("%-16s", courses[i].courseName);
			printf("%-16s", courses[i].courseCode);
			printf("%s", courses[i].Term);
			printf("\n");
	}
	
	printf("\n");
	
return;

} 

// Objective: Add a new course with unique CourseID and CourseCode
// Input: Three character arrays
// Output: none

void addCourseInfo(char aName[50], char aCode[12], char aTerm[6])
{
	//turn course name into uppercase letters
	for (int i = 0; i < strlen(aName); i++)
		aName[i] = toupper(aName[i]); 
	
	strcpy(courses[courseCount].courseName, aName);
	strcpy(courses[courseCount].courseCode, aCode);
	strcpy(courses[courseCount].Term, aTerm);
	courses[courseCount].courseID = courseCount + 1;
	courseCount++;

	return;

}

// Objective: Search for course information using courseID or course Name
// Input: menu option
// Output: none

void searchCourseInfo(int menuChoice)
{
	int searchID;
	char searchName[50];
	int flag = 0;

//  search by course ID
	if (menuChoice == 1) {

		printf("\nEnter the course ID to look for.\n");
		scanf("%d", &searchID);
		printf("\nCourse found: \n\n");

		if(searchID <= courseCount)
		{
			printf("%-8d", searchID);
			printf("%-16s", courses[searchID-1].courseName);
			printf("%-16s", courses[searchID-1].courseCode);
			printf("%s\n", courses[searchID-1].Term);
		}
		
		else
			printf("Course ID %d was not found.\n", searchID);
	}

// search by course name
	else {

		printf("\nEnter the course name to search for.\n");
		scanf("%s", searchName);

		for (int j = 0; j < strlen(searchName); j++)
			searchName[j] = toupper(searchName[j]); // convert to uppercase

		printf("\nResults:\n");

		for (int i = 0; i < courseCount; i++)
		{
			if (strcmp(courses[i].courseName, searchName) == 0)
			{

				printf("%-8d", courses[i].courseID);
				printf("%-16s", courses[i].courseName);
				printf("%-16s", courses[i].courseCode);
				printf("%s", courses[i].Term);
				printf("\n");

				flag++;
			}
		}

		if (flag == 0)
			printf("Course not found.\n");
		
	}
	
	return;
}

// Objective: Add new course information from user input
// Input: user input
// Output: none

void addNewCourse()
{
	char courseName[50];
	char courseCode[12];
	char semester[2];
	char term[8];
	char year[4];
	int flag = 0;

	printf("\nEnter the Course Name: ");
	scanf("%s", courseName);
			
	printf("Enter the Course Faculty code (format xxxx-xxx-xx): ");
	scanf("%s", courseCode);
	
	//check for duplicate.
	for (int i = 0; i < courseCount; i++)
		if (strcmp(courses[i].courseCode, courseCode) == 0)
			flag++;	

	
	if (flag > 0)
	{
		printf("Course code already exists.\n");		
		return;
	}
			
	printf("Enter the Course Semester (S, F or W): ");
	scanf("%s", semester);
	
	semester[0] = toupper(semester[0]);
	
	//copy semester into term
	strcpy(term, semester);
	
	printf("Enter the Course Year (format yyyy): ");
	scanf("%s", year);		
	
	//add year into term
	strcat(term, year);
		
	addCourseInfo(courseName,courseCode,term);	
}
