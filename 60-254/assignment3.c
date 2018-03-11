/*
 Title: assignment3.c
 Author: Samar El-Houssami
 Date last modified: 09/18/2017
 Objective: Create a priority stack data structure
 
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXQUEUE 8

typedef struct QueueElement{
    int data;
    int priority;
}QueueElement;

typedef struct Queue{
    int size;
    int front;
    int rear;
    
    QueueElement elements[MAXQUEUE];
}Queue;

//prototypes
void initiateQueue(Queue*);
void enqueueP(int, int, Queue*);
void enqueue(int, Queue*);
void dequeue(Queue*);
QueueElement peek(Queue*);
int isRegular(Queue*);
int size(Queue*);
int isEmpty(Queue*);
int isFull(Queue*);
void display(Queue);

int main(){
    Queue myQ;
    initiateQueue(&myQ);
    
    enqueueP(1, 1, &myQ);
    enqueue(5, &myQ);
    
    display(myQ); //1, 5
    
    dequeue(&myQ);
    printf("QUEUE:\n");
    display(myQ);//5
    
    enqueueP(3, 2, &myQ);//3,5
    enqueueP(1, 2, &myQ);//3,1,5
    enqueueP(7, 4, &myQ);//3,1,7,5
    printf("QUEUE:\n");
    display(myQ);
    printf("SIZE: %d\n", size(&myQ));//4
    
    
    enqueueP(8, 3, &myQ);//3,1,8,7,5
    printf("QUEUE:\n");
    display(myQ);
    
    enqueueP(2, 5, &myQ);//3,1,8,7,5,2
    enqueueP(1, 1, &myQ);//1,3,1,8,7,5,2
    printf("QUEUE:\n");
    display(myQ);
    return 0;
}

void initiateQueue(Queue *ptrQ){
    ptrQ->front = 0;
    ptrQ->rear = -1;
    ptrQ->size = 0;
}

void enqueueP(int d, int priority, Queue *ptrQ)
{
    if(isFull(ptrQ)){
        printf("Queue is full\n");
        return;
    }
    
    QueueElement e;
    e.data = d;
    e.priority = priority;
    
    if(priority == 1)
    {
        if(ptrQ->front == 0)
            ptrQ->front = MAXQUEUE - 1;
        else
            ptrQ->front--;
        
        ptrQ->elements[ptrQ->front] = e;
    }
    else {
        
        ptrQ->rear = (ptrQ->rear + 1) % MAXQUEUE;   //move rear up one
   
        int i;
        for(i = ptrQ->rear; priority < (ptrQ->elements[i-1]).priority ; i = (i-1) % MAXQUEUE)
        {
            printf("Element p: %d\tElement+1 p: %d\n", priority, (ptrQ->elements[i-1]).priority);
            ptrQ->elements[i] = ptrQ->elements[(i-1) % MAXQUEUE];
        }
    
        ptrQ->elements[i] = e;
    }
    
    ptrQ->size++;
}

void enqueue(int d, Queue *ptrQ)
{
    if(isFull(ptrQ)){
        printf("Queue is full\n");
        return;
    }
    
    ptrQ->rear = (ptrQ->rear + 1) % MAXQUEUE;
    
    QueueElement e;
    e.data = d;
    e.priority = 5;
    ptrQ->elements[ptrQ->rear] = e;
    ptrQ->size++;
}

void dequeue(Queue *ptrQ)
{
    if(isEmpty(ptrQ)){
        printf("Queue is empty\n");
        return;
    }
    
    ptrQ->front = (ptrQ->front + 1) % MAXQUEUE;
    printf("FRONT: %d\n", ptrQ->front);
    ptrQ->size--;
}

QueueElement peek(Queue *ptrQ)
{
    return ptrQ->elements[ptrQ->front];
}

int isRegular(Queue *ptrQ) {
    int flag = 1;
    for(int i = ptrQ->front; i < ptrQ->rear; i = (i+1) % MAXQUEUE)
    {
        if(ptrQ->elements[i].priority != ptrQ->elements[(i+1) % MAXQUEUE].priority)
            flag = 0;
    }
    
    return flag;
}

void display(Queue ptrQ)
{
    int i = ptrQ.front;
    do{
        printf("Data: %d\tPriority: %d\tIndex: %d\n", (ptrQ.elements[i]).data, (ptrQ.elements[i]).priority, i);
        i = (i+1) % MAXQUEUE;
    } while (i <= ptrQ.rear && i != ptrQ.front);
    printf("\n");
}

int size(Queue *ptrQ)
{
    return ptrQ->size;
}

int isEmpty(Queue *ptrQ)
{
    return ptrQ->size == 0;
}

int isFull(Queue *ptrQ)
{
    return ptrQ->size == MAXQUEUE;
}