/*
	Title: assignment2.c
    Author: Samar El-Houssami
	Date last modified: 10/15/2017
	Objective: Read infix expressions from a file, convert them to 
               postfix expressions, then evaluate the postfix expression
	
 */

//Includes
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SIZE 100

//Struct
typedef struct stack {
    char stk[SIZE];     //for stack of chars (infix->postfix)
    int evl[15];        //for stack of ints  (evaluating postfix)
    int top;            //top of stack
} stack;

//Prototypes
void pushChar(char, stack*);            //push char into stack
void pushInt(int, stack*);              //push int into stack

char popChar(stack*);                   //pop char from stack
int popInt(stack*);                     //pop int from stack

int isOperator(char);                   //check if char is operator (yes = 1)
int precedence(char);                   //returns precedence of operator
void infixToPostfix(char[], char[]);    //converts infix expression to postfix expression
int evaluatePostfix(char *);            //evaluates postfix expression

void printStackChar(stack);             //prints char stack
void printStackInt(stack);              //prints int stack

//main function
int main()
{
    char infix[SIZE], postfix[SIZE], line[SIZE];
    
    //creates file pointer
    FILE *fptr;     
    
    //if file does not open
    if((fptr = fopen("Assignment_02_test.txt","r")) == NULL)
        printf("File could not be opened.\n");
    
    else
    {
        //goes through entire file until end is reached
        while(fgets(infix, SIZE, fptr) != NULL)
        {
            //since fgets reads the '\n' character, we replace it with '\0'
            infix[strcspn(infix, "\n")] = '\0';
            
            //convert infix to postfix
            infixToPostfix(infix, postfix);
            
            printf("Final Postfix: %s \n\n", postfix);
            
            //evaluates postfix expression
            printf("Final evaluation of postfix expression: %d\n\n",evaluatePostfix(postfix));
            
            //reset postfix string
            for(int i = 0; i < SIZE; i++)
                postfix[i] = ' ';
            
            fgets(infix, SIZE, fptr);
        }
        
        //close file
        fclose(fptr);
    }
}

/*  Prints items in char stack
 *  Input: stack
 *  Output: nothing
 */
void printStackChar(stack s)
{
    printf("        \t");
    
    //go through entire stack
    for(int i = 0; i <= s.top; i++)
    {
        printf("%c", s.stk[i]);
    }
    printf("\t");
}

/*  Prints items in int stack
 *  Input: stack
 *  Output: nothing
 */
void printStackInt(stack s)
{
    printf("        \t");
    
    //go through entire stack
    for(int i = 0; i <= s.top; i++)
    {
        printf("%d ", s.evl[i]);
    }
    printf("\t");
}

/*  Pushes char item to char stack
 *  Input: char, stack
 *  Output: nothing
 */
void pushChar(char item, stack *s)
{
    //if stack is full
    if(s->top >= SIZE-1)
    {
        printf("\nStack is full.\n");
        exit(1);
    }
    
    else
        s->stk[++(s->top)] = item;
}

/*  Pushes int item to int stack
 *  Input: int, stack
 *  Output: nothing
 */
void pushInt(int item, stack *s)
{
    if(s->top >= SIZE-1)
    {
        printf("\nStack is full.\n");
        exit(1);
    }
    
    else
        s->evl[++(s->top)] = item;
}

/*  Pops char items from char stack
 *  Input: stack
 *  Output: char
 */
char popChar(stack *s)
{
    //if stack is empty
    if(s->top < 0)
    {
        printf("\nInvalid infix expression.\n");
        exit(1);
    }
    
    else
        return s->stk[(s->top)--];
    
}

/*  Pops int items from int stack
 *  Input: stack
 *  Output: int
 */
int popInt(stack *s)
{
    //if stack is empty
    if(s->top < 0)
    {
        printf("\nIvalid postfix expression.\n");
        exit(1);
    }
    
    else
        return s->evl[(s->top)--];
    
}

/*  Determines whether char is an operator or not
 *  Input: char
 *  Output: int (1 = operator)
 */
int isOperator(char symbol)
{
    if(symbol == '^'|| symbol == '*'| symbol == '/'|| symbol == '+'|| symbol == '-' || symbol == '~')
        return 1;
    
    else
        return 0;
}

/*  Gives precedence value of operators
 *  Input: char
 *  Output: int (4 - 0)
 */
int precedence(char symbol)
{
    //exponent: highest precedence
    if(symbol == '^')
        return 4;
    //unary operator
    else if(symbol == '~')
        return 3;
    
    else if(symbol == '*'|| symbol == '/')
        return 2;
    
    else if(symbol == '+' || symbol == '-')
        return 1;
    
    else
        return 0;
}

/*  Converts infix expression to postfix expression
 *  Input: stack
 *  Output: char
 */
void infixToPostfix(char infix[], char postfix[])
{
    //create stack with top = -1
    stack inf;
    inf.top = -1;
    
    int j = 0;
    char *item, x;
    
    //add '(' to stack
    pushChar('(', &inf);
    printf("\nInfix expression: ");
    puts(infix);
    printf("Scanned\t\tStack\t\tPostfix\n");
    
    //add ')' to end of infix expression
    strcat(infix," )");
    
    //seperate infix expression items using spaces
    item = strtok(infix, " ");
    
    while (item != NULL) {
        printf("  %s", item);
        
        //if item = '('
        //push to stack
        if(strcmp(item, "(") == 0)
        {
            pushChar(*item, &inf);
            printStackChar(inf);
        }
        
        //if item is a number
        //add it and the numbers after it (before the space)
        //to the postfix expression
        else if(isdigit(*item) == 1)
        {
            //in case of multi digit numbers
            for(int i = 0; item[i] != '\0'; i++)
                postfix[j++] = item[i];
            
            postfix[j++] = ' ';
            
            printStackChar(inf);
        }
        
        //if it's a negative number
        //push the unary operator to the stack (~)
        //add the number to the postfix expression
        else if(atoi(item) < 0)
        {
            pushChar('~', &inf);
            for(int i = 1; item[i] != '\0'; i++)
                postfix[j++] = item[i];
            
            postfix[j++] = ' ';
            
            printStackChar(inf);
        }
        
        
        //if item is an operator, pop a char (x) from the stack
        //if x has a higher precedence than the item
        //add x to the postfix expression
        //keep popping until precedence(item)>precedence(x) or x '(' is reached
        else if(isOperator(*item) == 1)
        {
            x = popChar(&inf);
            
            while ((isOperator(x) == 1) && (precedence(x) >= precedence(*item)))
            {
                postfix[j++] = x;
                
                postfix[j++] = ' ';
                x = popChar(&inf);
            }
            
            pushChar(x, &inf);
            pushChar(*item, &inf);
            
            printStackChar(inf);
        }
        
        //if item = ')' pop every operator before '(' is reached
        else if(strcmp(item, ")") == 0)
        {
            x = popChar(&inf);
            
            if(x == '(')
            {
                pushChar(x, &inf);
                printStackChar(inf);
                x = popChar(&inf);
            }
            
            while(x != '(')
            {
                
                postfix[j++] = x;
                
                postfix[j++] = ' ';
                
                x = popChar(&inf);
                
                if(x == '(')
                {
                    pushChar(x, &inf);
                    printStackChar(inf);
                    x = popChar(&inf);
                }
            }
        }
        
        //if item is an unrecognized char
        else
        {
            printf("Invalid infix expression. Unknown character.\n");
            exit(1);
        }
        
        printf("\t");
        
        //print postfix expression after each item is scanned
        for(int n = 0; n <= j; n++)
            printf("%c", postfix[n]);
        
        printf("\n");
        
        //get next item
        item = strtok(NULL, " ");
    }
    
    //if the stack isn't empty at the end of everything
    if(inf.top >= 0)
    {
        printf("Invalid infix expression. Parantheses do not match.\n\n");
        exit(1);
    }
    
    //add terminating null character
    postfix[j] = '\0';
    
}

/*  Evaluates postfix expression
 *  Input: postfix expression (3 + 4(4 -2) + 7)
 *  Output: int (evaluation)
 */
int evaluatePostfix(char *postfix)
{
    printf("Evaluation of postfix expression:\n");
    
    // Create a stack with top = -1
    stack post;
    post.top = -1;
    
    int i;
    char number[10];
    
    printf("Scanned\t\tStack\t\tOperation\n");
    
    // Scan all characters one by one
    for (i = 0; postfix[i] != '\0'; i++)
    {
        printf("  %c", postfix[i]);
        
        //if the scanned character is a number
        //convert it to an int then
        //push it and numbers after it (before the space) to the stack.
        if (isdigit(postfix[i]))
        {
            for(int y = 0; isdigit(postfix[i]); y++)
            {
                number[y] = postfix[i++];
                printf("%c", postfix[i]);
            }
            
            pushInt(atoi(number), &post);
            printStackInt(post);
            
            //Reset number[]
            for (int y = 0; y < 10; y++) {
                number[y] = 0;
            }
        }
        
        //if the scanned character is a unary operator
        //pop one element from the stack, apply operator
        //push element back into stack
        else if(postfix[i] == '~')
        {
            int val1 = popInt(&post);
            pushInt(0 - val1, &post);
            
            printStackInt(post);
            i++;
            
        }
        
        //if the scanned character is an operator, pop two
        //elements from stack and apply the operator
        else
        {
            int val1 = popInt(&post);
            int val2 = popInt(&post);
            
            printStackInt(post);
            
            switch (postfix[i])
            {
                case '+':
                    printf("\t%d + %d = %d", val2, val1, val2 + val1);
                    pushInt(val2 + val1, &post);
                    break;
                case '-':
                    printf("\t%d - %d = %d", val2, val1, val2 - val1);
                    pushInt(val2 - val1, &post);
                    break;
                case '*':
                    printf("\t%d * %d = %d", val2, val1, val2 * val1);
                    pushInt(val2 * val1, &post);
                    break;
                case '/':
                    printf("\t%d / %d = %d", val2, val1, val2 / val1);
                    pushInt(val2/val1, &post);
                    break;
                case '^':
                    printf("\t%d ^ %d = %d", val2, val1, (int)pow((double)val2, (double)val1));
                    pushInt((int)pow((double)val2, (double)val1), &post);
                    break;
            }
            
            i++;
            
        }
        
        printf("\n");
    }
    
    printf("\n");
    
    //return last element in the stack
    return popInt(&post);
}
