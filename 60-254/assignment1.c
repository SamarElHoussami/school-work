/*
	Title: assignment1.c
	Author: Samar El-Houssami
	Date last modified: 09/18/2017
	Objective: allow user to add/delete/sort/find/print posts
	
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

//Struct declaration
struct fbPost {
    int numLikes;
    int numComments;
    char postOwner[40];
    int sizeOfPost;
    int dateOfPost;
    
    struct fbPost *next;
};
typedef struct fbPost FBPost;

//Functions
int getChoice();                        //Display menu and get input from user
void printPosts(FBPost*);               //Display all posts
FBPost *findPost(FBPost*, int);         //Find post with a given attribute/delete if required
int findNumberOfPosts(FBPost*, int);         //find the number of posts saved
void delNode(FBPost*, FBPost*);
FBPost *addPost(FBPost*);               //Add a new post
FBPost *deletePost(FBPost*);            //Delete post by post date or owner
FBPost *deleteAllPosts(FBPost*);        //Delete all posts in list
FBPost *sortPosts(FBPost*, int, int);   //Sort posts option-inputs:(struct pointer, sorting option, size of list)

//Main
int main()
{
    int select;
    int sizeOfList;
    FBPost *postList = NULL;    //Empty struct pointer/lost of posts
    
    select = getChoice();       //user selection
    
    
    while (select >= 1){
        switch (select) {
            case 1: sizeOfList = findNumberOfPosts(postList, 1);
                select = getChoice();
                break;
            case 2: findPost(postList, 0);              //0-not deleting
                select = getChoice();
                break;
            case 3: sizeOfList = findNumberOfPosts(postList, 0);
                printf("You have %d posts saved.\n", sizeOfList);
                select = getChoice();
                break;
            case 4: postList = addPost(postList);
                select = getChoice();
                break;
            case 5: postList = findPost(postList, 1);   //1-deleting
                select = getChoice();
                break;
            case 6: postList = deleteAllPosts(postList);
                sizeOfList = 0;
                select = getChoice();
                break;
            case 7: sizeOfList = findNumberOfPosts(postList, 0);
                postList = sortPosts(postList, 0, sizeOfList);
                sizeOfList = findNumberOfPosts(postList, 1);
                select = getChoice();
                break;
            case 8: printf("See you next time!\n"); exit(0);
                
            default:
                printf("Wabba lubba dub dub!\n");
                break;
        }
    }
    
    return 0;
}

/*
 *Objective: Print menu, recieve input from user, return said input
 * Input: Nothing
 * Output: User selection
 */
int getChoice()
{
    int select;
    
    do {
        //Display menu
        printf("\n---Welcome to your personal Facebook post storing program!---\n\n");
        printf("Using your keyboard, select an option from the following menu:\n");
        printf("1. Display stored posts\n");
        printf("2. Find a post\n");
        printf("3. Display total number of posts\n");
        printf("4. Add a new post\n");
        printf("5. Delete a post\n");
        printf("6. Delete all posts\n");
        printf("7. Sort list of posts\n");
        printf("8. Exit\n\n");
        
        scanf("%d", &select);
        
        if (select < 0 || select > 8) {
            printf("Invalid input. Please enter a number from 1-8.\n");
        }
        
        //input must be valid (1-8) before continuing
    } while(select < 0 || select > 8);
    
    return select;
}

/*
 *Objective: Print every post saved in linked list
 * Input: Pointer to linked list
 * Output: Nothing
 */
void printPosts(FBPost *postList)
{
        printf("Post owner:\t\t%s\n", postList->postOwner);
        printf("Date of post:\t\t%d\n", postList->dateOfPost);
        printf("Number of likes:\t%d\n", postList->numLikes);
        printf("Number of comments:\t%d\n", postList->numComments);
        printf("Size of post:\t\t%d\n\n\n", postList->sizeOfPost);
    
    return;
}

/*
 *Objective: Find number of nodes in linked list
 * Input: Pointer to linked list
 * Output: Number of nodes in linked list
 */
int findNumberOfPosts(FBPost *postList, int prnt)
{
    int count = 1;
    
    if (postList == NULL)
        return 0;
    
    else {
        while ((postList -> next) != NULL) {
            if (prnt) {
                printPosts(postList);
            }
            
            count++;
            postList = postList -> next;
        }
        
        if (prnt) {
            printPosts(postList);
        }
    }

    return count;
}

/*
 *Objective: Allow user to search for post and delete post
 * Input: Pointer to linked list, delete option (0 for no, 1 for yes)
 * Output: Modified linked list
 */
FBPost *findPost(FBPost *postList, int del)
{
    int select, delOption;
    int results = 0;
    int flag = 0;
    int sizeOfList = findNumberOfPosts(postList, 0);
    char searchName[40];
    int searchLikes;
    int searchComments;
    int searchSize;
    int searchDate;
    
    FBPost *firstOcc, *temp, *searchList, *prev;
    
    if (postList == NULL)
    {
        printf("No posts have been stored yet! Add a new post with option 4.\n");
        return postList;
    }
    
    do {
        printf("How would you like to search through the list?\n");
        printf("1. Using name of owner\n");
        printf("2. Using number of likes\n");
        printf("3. Using number of comments\n");
        printf("4. Using size of post\n");
        printf("5. Using date of post\n");
        
        scanf("%d", &select);
        
        if (select < 1 || select > 5)
            printf("Invalid input.\n");
        
    } while (select < 1 || select > 5);
    
    
    switch (select) {
            //SEARCH BY POST OWNER
        case 1:
            //sort list alphabetically so that if multiple result are found, they will follow each other in the list and can be accessed knowing
            //the position of the first occuring result and the post #
            postList = sortPosts(postList, 1, sizeOfList);
            
            printf("Enter the name of the owner you're looking for: ");
            scanf("%s", searchName);
            
            searchList = postList;
            
            //go through list and print nodes which have the desired post owner
            while (searchList != NULL) {
                if(strcmp(searchName,searchList->postOwner) == 0)
                {
                    printf("Post #%d:\n", ++results);
                    printPosts(searchList);
                    
                    //if function is being used to delete a post
                    if (del) {
                        if (flag == 0) {
                            //save postition of the first occuring node
                            firstOcc = searchList;
                        }
                    }
                    
                    flag = 1;
                }
                
                searchList = searchList->next;
            }
            
            //no post was found
            if (flag == 0) {
                printf("\nNo post with owner %s has been found.\n", searchName);
                break;
            }
            
            printf("\n%d reults found matching your search.\n", results);
            
            //***********************if function is being used to delete a post***********************
            if (del) {
                //if only one post is found, no need to ask for post #
                if (results == 1) {
                    if (postList == firstOcc && sizeOfList == 1) {
                        deleteAllPosts(postList);
                        return postList;
                    }
                    
                    delNode(postList, firstOcc);
                }
                
                else {
                    //if multiple results found
                    do {
                        printf("Which post # would you like to delete?\n");
                        scanf("%d", &delOption);
                        
                        if(delOption < 0 || delOption > results)
                            printf("Invalid input.\n");
                    } while (delOption < 0 || delOption > results);
                    
                    
                    //starting from first occuring post, go through list 'post #' amount of times
                    while (delOption > 1) {
                        firstOcc = firstOcc -> next;
                        delOption--;
                    }
                    
                     delNode(postList, firstOcc);
                }
                
                printf("Post successfully deleted!\n");
            }
            
            //****************************************************************************************
            break;
            
            //SEARCH BY NUMBER OF LIKES
        case 2:
            flag = 0;
            
            //sort list in acending order
            postList = sortPosts(postList, 2, sizeOfList);
            
            printf("Enter the number of likes the post has: ");
            scanf("%d", &searchLikes);
            
            searchList = postList;
            
            while (searchList != NULL) {
                if (searchLikes == searchList->numLikes)
                {
                    printf("Post #%d:\n", ++results);
                    printPosts(searchList);
                    
                    //if function is being used to delete a post
                    if (del)
                        if (flag == 0) {
                            //save postition of the first occuring node
                            firstOcc = searchList;
                        }
                    
                    flag = 1;
                }
                
                searchList = searchList->next;
            }
            
            printf("\n%d reults found matching your search.\n", results);
            
            if (flag == 0)
                printf("\nNo post with %d likes has been found.\n", searchLikes);
            
            //***********************if function is being used to delete a post***********************
            if (del) {
                //if only one post is found, no need to ask for post #
                if (results == 1) {
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        //go through entire list until we reach the node before desired deleted node
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    printf("Post successfully deleted!\n");
                    break;
                }
                
                else {
                    //if multiple results found
                    do {
                        printf("Which post # would you like to delete?\n");
                        scanf("%d", &delOption);
                        
                        if(delOption < 0 || delOption > results)
                            printf("Invalid input.\n");
                    } while (delOption < 0 || delOption > results);
                    
                    //starting from first occuring post, go through list 'post #' amount of times
                    while (delOption > 1) {
                        firstOcc = firstOcc -> next;
                        delOption--;
                    }
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    
                }
                
                printf("Post successfully deleted!\n");
            }
            
            //****************************************************************************************
            break;
            
            //SEARCH BY NUMBER OF COMMENTS
        case 3:
            flag = 0;
            postList = sortPosts(postList, 3, sizeOfList);
            
            printf("Enter the number of comments the post has: ");
            scanf("%d", &searchComments);
            
            searchList = postList;
            
            while (searchList != NULL) {
                if (searchComments == searchList->numComments)
                {
                    printf("Post #%d:\n", ++results);
                    printPosts(searchList);
                    
                    //if function is being used to delete a post
                    if (del)
                        if (flag == 0) {
                            //save postition of the first occuring node
                            firstOcc = searchList;
                        }
                    
                    flag = 1;
                    
                }
                
                searchList = searchList->next;
            }
            
            
            if (flag == 0)
                printf("\nNo post with %d comments has been found.\n", searchComments);
            
            printf("\n%d reults found matching your search.\n", results);
            
            //***********************if function is being used to delete a post***********************
            if (del) {
                //if only one post is found, no need to ask for post #
                if (results == 1) {
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        //go through entire list until we reach the node before desired deleted node
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    printf("Post successfully deleted!\n");
                    break;
                }
                
                else {
                    //if multiple results found
                    do {
                        printf("Which post # would you like to delete?\n");
                        scanf("%d", &delOption);
                        
                        if(delOption < 0 || delOption > results)
                            printf("Invalid input.\n");
                    } while (delOption < 0 || delOption > results);
                    
                    //starting from first occuring post, go through list 'post #' amount of times
                    while (delOption > 1) {
                        firstOcc = firstOcc -> next;
                        delOption--;
                    }
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    
                }
                
                printf("Post successfully deleted!\n");
            }
            
            //****************************************************************************************
            break;
            
            //SEARCH
        case 4:
            flag = 0;
            
            postList = sortPosts(postList, 4, sizeOfList);
            
            printf("Enter the size of the post: ");
            scanf("%d", &searchSize);
            
            searchList = postList;
            
            while (postList != NULL) {
                if (searchSize == searchList->sizeOfPost)
                {
                    printf("Post #%d:\n", ++results);
                    printPosts(searchList);
                    
                    //if function is being used to delete a post
                    if (del){
                        if (flag == 0) {
                            //save postition of the first occuring node
                            firstOcc = searchList;
                        }
                    }
                    
                    flag = 1;
                }
                
                searchList = searchList->next;
            }
            
            printf("\n%d reults found matching your search.\n", results);
            
            if (flag == 0)
                printf("\nNo post with %d likes has been found.\n", searchSize);
            
            //***********************if function is being used to delete a post***********************
            if (del) {
                //if only one post is found, no need to ask for post #
                if (results == 1) {
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        //go through entire list until we reach the node before desired deleted node
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    printf("Post successfully deleted!\n");
                    break;
                }
                
                else {
                    //if multiple results found
                    do {
                        printf("Which post # would you like to delete?\n");
                        scanf("%d", &delOption);
                        
                        if(delOption < 0 || delOption > results)
                            printf("Invalid input.\n");
                    } while (delOption < 0 || delOption > results);
                    
                    //starting from first occuring post, go through list 'post #' amount of times
                    while (delOption > 1) {
                        firstOcc = firstOcc -> next;
                        delOption--;
                    }
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    
                }
                
                printf("Post successfully deleted!\n");
            }
            
            //****************************************************************************************
            break;
            
        case 5:
            flag = 0;
            
            postList = sortPosts(postList, 5, sizeOfList);
            
            printf("Enter the date of the post (YYYYMMDD): ");
            scanf("%d", &searchDate);
            
            searchList = postList;
            
            while (searchList != NULL) {
                if (searchDate == searchList->dateOfPost)
                {
                    printf("Post #%d:\n", ++results);
                    printPosts(searchList);
                    
                    //if function is being used to delete a post
                    if (del)
                        if (flag == 0) {
                            //save postition of the first occuring node
                            firstOcc = searchList;
                        }
                    
                    flag = 1;
                }
                
                searchList = searchList->next;
            }
            
            printf("\n%d reults found matching your search.\n", results);
            
            if (flag == 0)
                printf("\nNo post with posted on %d was found.\n", searchDate);
            
            //***********************if function is being used to delete a post***********************
            if (del) {
                //if only one post is found, no need to ask for post #
                if (results == 1) {
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        //go through entire list until we reach the node before desired deleted node
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    printf("Post successfully deleted!\n");
                    break;
                }
                
                else {
                    //if multiple results found
                    do {
                        printf("Which post # would you like to delete?\n");
                        scanf("%d", &delOption);
                        
                        if(delOption < 0 || delOption > results)
                            printf("Invalid input.\n");
                    } while (delOption < 0 || delOption > results);
                    
                    //starting from first occuring post, go through list 'post #' amount of times
                    while (delOption > 1) {
                        firstOcc = firstOcc -> next;
                        delOption--;
                    }
                    
                    //if the node is at the head of the list
                    if (firstOcc == postList) {
                        temp = postList;
                        postList = temp -> next;
                        free(temp);
                    }
                    
                    //if the node is in the middle/end of the list
                    else {
                        searchList = postList;
                        
                        while ((searchList -> next) != firstOcc) {
                            searchList = searchList -> next;
                        }
                        
                        //we want to delete firstOcc
                        prev = searchList;
                        prev -> next = firstOcc -> next;
                        free(firstOcc);
                    }
                    
                }
                
                printf("Post successfully deleted!\n");
            }
            
            //****************************************************************************************
            break;
            
        default:
            break;
    }
    
    return postList;
}

/*
 *Objective: Find number of nodes in linked list
 * Input: Pointer to linked list
 * Output: Number of nodes in linked list
 */
FBPost *addPost(FBPost *postList)
{
    FBPost *aPost = (FBPost *) malloc(sizeof(FBPost));
    
    printf("Please enter the following information:\n");
    
    //Post Owner
    
    do {
        
        printf("Post owner: ");
        scanf("%s", aPost -> postOwner);
        
        if (strcmp(aPost -> postOwner, "") == 0)
            printf("Invalid entry.\n");
    } while(strcmp(aPost -> postOwner, "") == 0);
    
    //Number of likes
    do {
        
        printf("Number of likes: ");
        scanf("%d", &(aPost -> numLikes));
        
        if ((aPost -> numLikes) < 0)
            printf("Invalid entry.\n");
    } while((aPost -> postOwner) < 0); //or null maybe
    
    //Number of comments
    do {
        
        printf("Number of comments: ");
        scanf("%d", &(aPost -> numComments));
        
        if ((aPost -> numComments) < 0)
            printf("Invalid entry.\n");
    } while((aPost -> numComments) < 0);
    
    //Size of post
    do {
        
        printf("Size of post: ");
        scanf("%d", &(aPost -> sizeOfPost));
        
        if ((aPost -> sizeOfPost) < 0)
            printf("Invalid entry.\n");
    } while((aPost -> sizeOfPost) < 0);
    
    //Date of post
    do {
        
        printf("Date of post (YYYYMMDD): ");
        scanf("%d", &(aPost -> dateOfPost));
        
        if ((aPost -> dateOfPost) < 20040101 || (aPost -> dateOfPost) > 2147483647)
            printf("Invalid entry.\n");
        
        printf("%d\n", aPost -> dateOfPost);
        
    } while((aPost -> dateOfPost) < 20040101 || (aPost -> dateOfPost) > 2147483647);
    
    //if list is empty, return new post
    if (postList == NULL)
        return aPost;
    
    FBPost *tempPost = postList;
    
    while(tempPost->next != NULL)
        tempPost = tempPost->next;
    
    tempPost->next = aPost;
    
    return postList;
}

/*
 *Objective: Bubble sort nodes in linked list
 * Input: Pointer to linked list, type of sorting (1-5), size of linked list
 * Output: Sorted linked list
 */
FBPost *sortPosts(FBPost *postList, int select, int sizeOfList)
{
    int choice, compare;
    FBPost *current;
    FBPost *nxt;
    FBPost *prev;
    
    if (postList == NULL) {
        return postList;
    }
    
    if (postList -> next == NULL) {
        if (select != 0) {
            printf("You only have one post saved.\n");
        }
        
        return postList;
    }
    
    if (select == 0) {
        do {
            printf("How would you like to sort the list?\n");
            printf("1. Using name of owner\n");
            printf("2. Using number of likes\n");
            printf("3. Using number of comments\n");
            printf("4. Using size of post\n");
            printf("5. Using date of post\n");
            
            scanf("%d", &choice);
            
            if (choice < 1 || choice > 5)
                printf("Invalid input.\n");
            
        } while (choice < 1 || choice > 5);
    }
    
    //0 - called from main
    //1-5 - called from findPost and no need for user input
    else if (select != 0)
        choice = select;
    
    switch (choice) {
        case 1:
            for(int x = 0; x < sizeOfList; x++)
            {
                //restart from top of list
                current = postList;
                nxt = current -> next;
                prev = NULL;
                
                //go through list once
                while (nxt != NULL) {
                    
                    //compare post owners strings
                    compare = strcmp(current -> postOwner, nxt -> postOwner);
                    
                    if (compare > 0) {
                        
                        //if current = head of list
                        if (current == postList) {
                            //head of list is 2nd node
                            postList = nxt;
                        }
                        
                        else {
                            prev -> next = nxt;
                        }
                        
                        //list: nxt -> current -> node
                        current -> next = nxt -> next;
                        nxt -> next = current;
                        
                        //list: prev -> current -> next
                        prev = nxt;
                        nxt = current -> next;
                    }
                    
                    else {
                        //move up a node
                        prev = current;
                        current = current -> next;
                        nxt = current -> next;
                    }
                    
                }
                
            }
            
            break;
            
        case 2:
            for(int x = 0; x < sizeOfList; x++)
            {
                //restart from top of list
                current = postList;
                nxt = current -> next;
                prev = NULL;
                
                //go through list once
                while (nxt != NULL) {
                    
                    //compare number of likes
                    if (current -> numLikes < nxt -> numLikes) {
                        
                        //if current = head of list
                        if (current == postList) {
                            //head of list is 2nd node
                            postList = nxt;
                        }
                        
                        else {
                            prev -> next = nxt;
                        }
                        
                        //list: nxt -> current -> node
                        current -> next = nxt -> next;
                        nxt -> next = current;
                        
                        //list: prev -> current -> next
                        prev = nxt;
                        nxt = current -> next;
                    }
                    
                    else {
                        //move up a node
                        prev = current;
                        current = current -> next;
                        nxt = current -> next;
                    }
                    
                }
                
            }
            break;
            
        case 3:
            for(int x = 0; x < sizeOfList; x++)
            {
                //restart from top of list
                current = postList;
                nxt = current -> next;
                prev = NULL;
                
                //go through list once
                while (nxt != NULL) {
                    
                    //compare number of likes
                    if (current -> numComments < nxt -> numComments) {
                        
                        //if current = head of list
                        if (current == postList) {
                            //head of list is 2nd node
                            postList = nxt;
                        }
                        
                        else {
                            prev -> next = nxt;
                        }
                        
                        //list: nxt -> current -> node
                        current -> next = nxt -> next;
                        nxt -> next = current;
                        
                        //list: prev -> current -> next
                        prev = nxt;
                        nxt = current -> next;
                    }
                    
                    else {
                        //move up a node
                        prev = current;
                        current = current -> next;
                        nxt = current -> next;
                    }
                    
                }
                
            }
            break;
            
        case 4:
            for(int x = 0; x < sizeOfList; x++)
            {
                //restart from top of list
                current = postList;
                nxt = current -> next;
                prev = NULL;
                
                //go through list once
                while (nxt != NULL) {
                    
                    //compare number of likes
                    if (current -> sizeOfPost < nxt -> sizeOfPost) {
                        
                        //if current = head of list
                        if (current == postList) {
                            //head of list is 2nd node
                            postList = nxt;
                        }
                        
                        else {
                            prev -> next = nxt;
                        }
                        
                        //list: nxt -> current -> node
                        current -> next = nxt -> next;
                        nxt -> next = current;
                        
                        //list: prev -> current -> next
                        prev = nxt;
                        nxt = current -> next;
                    }
                    
                    else {
                        //move up a node
                        prev = current;
                        current = current -> next;
                        nxt = current -> next;
                    }
                    
                }
                
            }
            break;
            
        case 5:
            for(int x = 0; x < sizeOfList; x++)
            {
                //restart from top of list
                current = postList;
                nxt = current -> next;
                prev = NULL;
                
                //go through list once
                while (nxt != NULL) {
                    
                    //compare number of likes
                    if (current -> dateOfPost < nxt -> dateOfPost) {
                        
                        //if current = head of list
                        if (current == postList) {
                            //head of list is 2nd node
                            postList = nxt;
                        }
                        
                        else {
                            prev -> next = nxt;
                        }
                        
                        //list: nxt -> current -> node
                        current -> next = nxt -> next;
                        nxt -> next = current;
                        
                        //list: prev -> current -> next
                        prev = nxt;
                        nxt = current -> next;
                    }
                    
                    else {
                        //move up a node
                        prev = current;
                        current = current -> next;
                        nxt = current -> next;
                    }
                    
                }
                
            }
            break;
            
        default:
            break;
    }
    
    return postList;
}

void delNode(FBPost *postList, FBPost *toDelete){
    FBPost *searchList, *prev;
    searchList = postList;
    
    if (toDelete == postList) {
        //if there's only one node in the list
        if (postList -> next == NULL) {
            free(postList);
            return;
        }
        
        //toDelete = head of list;
        postList = toDelete -> next;
        free(toDelete);
    }
    
    //if the node is in the middle/end of the list
    else {
        searchList = postList;
        
        //go through entire list until we reach the node before desired deleted node
        while ((searchList -> next) != toDelete) {
            searchList = searchList -> next;
        }
        
        //we want to delete toDelete
        prev = searchList;
        prev -> next = toDelete -> next;
        free(toDelete);
        
        //postList = searchList;
    }
    
    return;
    
}

FBPost *deleteAllPosts(FBPost* postList)
{
    if(postList == NULL)
    {
        printf("You do not have any posts saved.\n");
        return postList;
    }
    
    FBPost *curr;
    
    while (postList -> next != NULL) {
        curr = postList;
        postList = postList -> next;
        free(curr);
    }
    
    free(postList);
    
    printf("List successfully deleted!\n");
    
    return NULL;
}

