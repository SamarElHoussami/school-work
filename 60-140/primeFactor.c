#include <stdio.h>
#include <stdbool.h>

int readNum();												//reads number
bool IsPrime(int prime);									//checks every prime number one at a time
int PrimeCount(int num, int prime);							//checks if and how many times prime is in num
int num, p_flag, prime, primeFreq;

int main() 
{
	readNum();												//reads num
	printf("%d = 1", num);
	prime = 2;

	do {
		IsPrime(prime);
		
		if (p_flag) 										//if a number is prime
		num = PrimeCount(num, prime);						//check how many it goes into num and updates num
		
		prime++;											//checks next prime number
	} while (num > 1);

	printf("\n");
	
return 0;
}

int readNum()
{
	
	do {
	printf("Enter a valid number (>1): ");					
	scanf("%d", &num);
	
	if (num <= 1)
		printf("Invalid number.\n");
	
	} while (num <= 1);										//Keeps asking for input until a valid input is given
	
	return num;
}

bool IsPrime(int prime)										
{
	p_flag = false;
		
	for (int divisior = 2; divisior*divisior <= prime; divisior++){
		if (prime % divisior == 0)
			return p_flag;									//returns false is number isn't prime
	}
		p_flag = true;
		return p_flag;
	}
		

int PrimeCount(int num, int prime)
{
	primeFreq = 0;
	
	while ((num % prime) == 0) {
		primeFreq++;
		num /= prime;
	}
	
	if (primeFreq != 0)
		printf(" x (%d^%d)", prime, primeFreq);
		
	return num;
}