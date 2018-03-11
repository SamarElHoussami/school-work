#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
  char FirstName[41];
  char LastName[41];
  int id;
  struct contact *ptrNext;
};

void PrintList(struct contact*);
void ClearList(struct contact*);

int main() {
	struct contact Contact = {"","",0,NULL};
	
	strcpy(Contact.FirstName, "John");
	strcpy(Contact.LastName, "Doe");
	Contact.id = 10;
	
	Contact.ptrNext = (struct contact*)malloc(sizeof(struct contact));
	
	stpcpy(Contact.ptrNext->FirstName, "Will");
	strcpy(Contact.ptrNext->LastName, "Smith");
	Contact.ptrNext->id = 20;
	
	PrintList(&Contact);
	ClearList(&Contact);
	
  return 0;
}

void PrintList(struct contact *Contact)
{
	if(Contact == NULL)
		return;
	
		printf("%d: %s %s\n", Contact->id, Contact->FirstName, Contact->LastName);
		PrintList(Contact->ptrNext);
	return;
}

void ClearList(struct contact *Contact)
{
	
	if(Contact == NULL)
		return;
	
		ClearList(Contact->ptrNext);
		free(Contact);
		printf("success");
	return;
}