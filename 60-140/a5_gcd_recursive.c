#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int gcd(int m, int n);

int main()
{
	srand( time(NULL) );
   int m = rand() % 100 + 2; //between 2 and 100
   int n = rand() % 100 + 2; //between 2 and 100
   
   printf("The GCD of %d and %d is %d.\n", m, n, gcd(m,n));
   return 0;
}

int gcd(int m, int n)
{
    if (n != 0)
       return gcd(n, m%n);
    else 
       return m;
}