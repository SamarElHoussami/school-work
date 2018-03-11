package assignment1;

/*
 *Title: assignment1
 *Author: Samar El-Houssami
 *Date last modified: 09/19/2017
 *Objective: This program computes and prints the sum and multiplication of the first five negative integers
 */

public class prob3 {

	public static void main(String[] args) {
		int sum = -1;	//set sum and product to first negative integer
		int prod = -1;
		
		for(int negInt = -2; negInt > -6; negInt--) {	//loop 5 times
			sum += negInt;		//calculate sum and product of first five negative integers
			prod *= negInt;
		}
		
		System.out.printf("Sum: %d\nProduct: %d", sum, prod);		//print results
	}

}
