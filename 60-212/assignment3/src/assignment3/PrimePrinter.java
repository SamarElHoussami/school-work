package assignment3;

import java.util.Scanner;

/**
This class prints prime numbers.
*/
public class PrimePrinter {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in); 
		System.out.print("Enter upper limit: "); 
		int limit = in.nextInt();
		
		int flag;
		for(int i = 2; i < limit; i++) {
			flag = 0;
			for(int y = 2; y < i; y++)
				if( i % y == 0)
					flag = 1;
			
			if (flag == 0)
				System.out.print(i + " ");
		}
	}

}
