package assignment2;

public class BankAccount {

	private double balance;
	private double fee;
	private int transactionCount;
	private int freeTransactions = 5;
	
	/**
	 * Constructs a bank account with a zero balance
	 */
	public BankAccount()
	{
		transactionCount = 0;
		fee = 1.25;
		balance = 0;
	}
	
	/**
	 * Constructs a bank account with an initial balance
	 * @param initialBalance the initial balance
	 */
	public BankAccount(double initialBalance)
	{
		transactionCount = 0;
		fee = 1.25;
		balance = initialBalance;
	}
	
	/**
	 * Deposits money into the bank account
	 * @param amount the amount to deposit
	 */
	public void deposit(double amount)
	{
		transactionCount++;
		balance += amount;
	}
	
	/**
	 * Withdraws money from the bank account
	 * @param amount the amount to withdraw
	 */
	public void withdraw(double amount)
	{
		transactionCount++;
		balance -= amount;
	}
	
	/**
	 * Gets the current balance of the bank account
	 * @return the current balance
	 */
	public double getBalance()
	{
		return balance;
	}
	
	/**
	 * Deducts monthly charge and resets transaction count
	 */
	public void deductMonthlyCharge()
	{
		balance = balance - ((Math.max(transactionCount, freeTransactions) - freeTransactions) * fee);
		transactionCount = 0;
	}
}
