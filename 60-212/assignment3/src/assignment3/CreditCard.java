package assignment3;

public class CreditCard {
	private final int SIZE = 16;
	private int[] num;
	private String numStr;
	private int sum;
	
	/**
	Constructs a credit card with a credit card number
	@param number credit card number
	*/
	public CreditCard(String number) {
		num = new int[SIZE];
		int y = 0;
		
		//convert string into int array
		for(int i = 0; i < SIZE && y < number.length(); i++) {
			
			numStr = number;
			
			//skips over non-digit chars in string
			if(!Character.isDigit(numStr.charAt(y))) 
				y++;
			
			num[i] = numStr.charAt(y) - '0';
			y++;
		}
	}
	
	/**
	Determines if the credit card number is valid
	@return true if credit card number is valid
	*/
	public boolean isValid() {
		//Number has incorrect number of digits
		if(numStr.length() != 19)
			return false;
		
		sum = 0;
		
		//go through num array
		for(int i = 0; i < 16; i++) {
			//sum of all digits
			sum += num[i];
			
			//plus every second digit
			if(i % 2 == 0) {
				sum += num[i];
				
				//plus 1 if the second digit > 4 
				if(num[i] > 4)
					sum++;
			}
		}
		
		if(sum % 10 == 0)
			return true;
		else
			return false;
		
	}
}
