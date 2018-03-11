/*	
	Title: Assign1.c
	Author: Samar El-Houssami
	Date last modified: 01/29/2017
	Objective: Finds prime numbers of the factorial of inputed through a text file
	
*/

//Includes
#include <stdio.h>

//Prototypes
int find_prime_count(int, int);	//finds number of times a prime number goes into the factorial of the input
int find_next_prime(int);		//finds next prime number
int is_prime(int);				//checks if a number is prime

int main()
{
	int inp = 0, maxOnLine = 0;
	/*
	FILE *fp;
	fp = fopen("input.txt", "r");	//opens file
	fscanf(fp, "%d", &inp);			//reads first integer
*/

	scanf("%d", &inp);

	for (int i = 0; inp != 0; i++)	//while the input != 0
	{
		int prime = 2, countPrime = 0;
		
		printf("%3d! =  ", inp);
		
		do {
			
		if (is_prime(prime)) 			//if the number is prime
		{
			countPrime = find_prime_count(inp, prime);
			printf("(%d^%d)", prime, countPrime);
			maxOnLine++;
			
			if (prime == inp){			//end of prime numbers in the factorial
				maxOnLine = 0;
			}
			
			else if (maxOnLine == 9) {	//max number of pairs on one line
				printf("\n\t");
				maxOnLine = 0;
			}
			
		}
		
		prime = find_next_prime(prime);	//update prime number
		
		if (prime <= inp)
			printf("*");
		
		} while (prime <= inp);
		
		
		printf("\n\n");
		scanf("%d", &inp);
		//fscanf(fp, "%d", &inp);			//reads next integer in the txt file
	}
	
	//fclose(fp);							//close file

	return 0;
}

/**********************************
Objective: Verify if number chosen is a prime number
Input: prime
Output: p_flag (either true or false)
***********************************/
int is_prime(int prime)
{
	int p_flag = 0;

	for (int divisior = 2; divisior*divisior <= prime; divisior++){
		if (prime % divisior == 0)
			return p_flag;				//returns false if number isn't prime
	}
		p_flag = 1;
		return p_flag;
}

/*************************************************************************
Objective: Count how many times the prime number goes into the factorial
Input: num and prime
Output: countPrime (how many times the prime number goes into the factorial)
*************************************************************************/
int find_prime_count(int num, int prime)
{
	int countPrime = 0, j = prime;
	
	while (prime <= num)
	{
		for (int i = 1; i <= num;i++)
		{
			if (i%prime == 0)
				countPrime++;
		}
		
	prime = prime * j;
	
	}
	
	return countPrime;
}

/*************************************************************************
Objective: Find the prime number that follows the previous one
Input: prime
Output: nextPrime (the new prime number)
*************************************************************************/
int find_next_prime(int prime)
{
	int i, k, nextPrime, flag = 0;

	for (i = prime + 1 ;; i++)
	{
		for (k = 2; k < i; k++)
		{
			if (i%k==0)
			{
				flag = 1;
				break;
			}
		}

		if (flag == 0)
		{
			nextPrime = i;
			break;
		}
		flag = 0;
	}

	return nextPrime;
}