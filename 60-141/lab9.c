/*	
	Title: lab9.c
	Author: Samar El-Houssami
	Date last modified: 03/26/2017
	Objective: Add nodes to linked list and print all nodes 
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
   int ID;
   char name[40];
   struct student *next;
};
typedef struct student Student;

//prototypes
int getChoice();
Student *addToList(Student *List);
void printList(Student *List);
void printListRR(Student *List);
void searchList(Student *List);

int main() {
    int choice = 0;
    Student *SLIST = NULL;	//create an empty struct pointer

    choice = getChoice();

    while(choice >= 0) {
        switch(choice) {
            case 0 : printf("Bye...\n"); exit(0);
            case 1 : SLIST = addToList(SLIST); break;
            case 2 : printList(SLIST); break;
            case 3 : printListRR(SLIST); break;
            case 4 : searchList(SLIST); break;
            default: printf("That is not a valid choice\n");
        }
        choice = getChoice();
    }

    if(SLIST) free(SLIST);
    return 0;
}

// Input: none
// Objective: Display menu and get input from user
// Output: user input
int getChoice() {
    int choice = 0;

    printf("\n****** MENU ******\n");
    printf("1. Add new student to list.\n");
    printf("2. Print the student list, beginning to end.\n");
    printf("3. Recursively print the student list from the end.\n");
    printf("4. Search the list for a student.\n");
    printf("0. Quit.\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    return choice;
}

// Input: pointer to linked list 
// Objective: Add student to list
// Output: new list with added student
Student *addToList(Student *List) {

    Student *aStudent = (Student *) malloc(sizeof(Student));	//allocate memory

    printf("Enter student's ID: ");
    scanf("%d", &(aStudent->ID));
    printf("Enter student's name: ");
    scanf(" %[^\n]", aStudent->name);

	//if list is empty
    if (List == NULL) return aStudent;

    Student *tempStudent = List;

	//go through entire list until end is reached
    while(tempStudent->next != NULL)
        tempStudent = tempStudent->next;

    tempStudent->next = aStudent;
	
    return List;
}

// Input: pointer to linked list
// Objective: print list of students from list
// Output: list of students in the list
void printList(Student *List) {
    while(List != NULL) {
        printf("%d %s\n", List->ID, List->name);
        List = List->next;
    }
	
	return;
}

// Input: pointer to linked list
// Objective: Sort list of employees based on their GPA
// Output: sorted list of employees
void printListRR(Student *List) {
    if(List == NULL) return;
    printListRR(List->next);
    printf("%d %s\n", List->ID, List->name);
	
	return;
}

// Input: pointer to linked list
// Objective: Search list using student ID
// Output: Info of student with ID if found. If not, nothing.
void searchList(Student *List) {
    int searchID;
    printf("Enter student's ID: ");
    scanf("%d", &searchID);

    while(List != NULL) {
        if(List->ID == searchID){
            printf("%d %s\n", List->ID, List->name);
            return;
        }
        List = List->next;
    }
    printf("ID %d not found", searchID);
	
	return;
}
