 #include <stdio.h>
     
	 int main()
     {
     int a = 7 ;			//assigns 7 to a
     int *aPtr ;			//initializes a pointer
     aPtr = &a ;			//lets the pointer aPtr point to a 
     printf( "%p", &a );	//prints the address of a
     printf( "%p", aPtr );	//prints the address of the variable aPtr is pointing to (address of a)
     printf( "%p", &aPtr );	//prints the address of aPtr
     printf( "%d", a );		//prints the value assigned to a (7)
     printf( "%d", *aPtr );	//prints the value of the variable that aPtr is pointing to (value of a)
     printf( "%p", *&aPtr );//prints the value at the address of aPtr (a's address) 
     printf( "%p", &*aPtr );//prints the address of the value pointed to by aPtr (a's address)
     printf( "%d", *&a );	//prints the value at a's address (a)
     printf( "%d", &*a );	//error (can't dereference a non pointer)
     return 0;
     }