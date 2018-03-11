package assignment2;

public class Register {
	
private int amountDue;
private int amountReceived;
private int change;

private int dollars;
private int quarters;
private int dimes;
private int nickels;
private int pennies;
	
	Register(int due, int received)
	{
	amountDue = due;
	amountReceived = received;
	
	change = amountReceived - amountDue;
	
	System.out.print(change + " cents to be returned in ");
	dollars = change / 100;
	change = change - (dollars * 100);
	if (dollars != 0) { System.out.print(dollars + " dollar(s), "); }
	
	quarters = change / 25;
	change = change - (quarters * 25);
	if (quarters != 0) { System.out.print(quarters + " quarter(s), "); }
	
	dimes =  change / 10;
	change =  change - (dimes * 10);
	if (dimes != 0) { System.out.print(dimes + " dime(s), "); }
	
	nickels = change / 5;
	change = change - (nickels * 5);
	if (nickels != 0) { System.out.print(nickels + " nickel(s), "); }
	
	pennies = change;
	if (pennies != 0) { System.out.print(pennies + " pennie(s)"); }
	
	System.out.print("\n");
	}

}
