package assignment1;
/*
 *Title: assignment1
 *Author: Samar El-Houssami
 *Date last modified: 09/19/2017
 *Objective: This program displays the balance of a bank account with 5% interest being added over 3 years 
 */

public class prob1 {
	
	public static void main(String[] args) {
		int year = 0;					//initialize year count starting at 0
		double balance = 10000.00;		//initial balance
		double interest;
		
		do {
			year++;						//add 1 to year
			interest = balance * 0.05;	//calculate 5% interest
			balance += interest;			//add interest to balance
			System.out.printf("Balance after %d year(s): %.2f\n", year, balance);	//print balance
		}	while(year < 3);				//repeat 3 times for 3 years
	}
}
