/*Lab 02 - Part B
   Author: Samar El-Houssami
   Date: 10/05/2016*/

#include <stdio.h>

int main()
{

    //print unsigned interger 40000 left justified in a 15-digit field with 8 digits
    printf("%-15.8u\n", (unsigned)40000);
    
    //print 1.234 in a 9-digit field with preceding zeros
    
    printf("%09.3f", 1.234f);
    
    //read a time of form hh:mm:ss, store in int variables hour, minute, second
    
    int hour, minute, second;
    
    scanf("%d:%d:%d", &hour, &minute, &second);
    
    return 0; 
}
