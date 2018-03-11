package assignment2;

public class prob3 {

	public static void main(String[] args) {
		BankAccount myAccount;
		String str = "ABC";
		int count = Integer.parseInt(str);
		System.out.println(count);
		System.out.println("\\\\\\\"///");
		BankAccount mySavings = new BankAccount(500);
		//Month 1
		mySavings.deposit(200);
		mySavings.deposit(700);
		mySavings.withdraw(100);
		mySavings.deposit(300);
		mySavings.withdraw(400);
		mySavings.deposit(250);
		mySavings.deductMonthlyCharge();
		System.out.println("Month 1: " + mySavings.getBalance());
		//Expected: 500 + 200 + 700 - 100 + 300 - 400 + 250
		// = 1450 - ((6-5) * 1.25)
		//1448.75
		
		//Month 2
		mySavings.deposit(300);
		mySavings.deposit(150);
		mySavings.withdraw(100);
		mySavings.deductMonthlyCharge();
		System.out.println("Month 2: " + mySavings.getBalance());
		//Expected: 1448.75 + 300 + 150 - 100
		// = 1798.75 - ((5-5) * 1.25)
		//1798.75
		
		//Month 3
		mySavings.deposit(800);
		mySavings.withdraw(150);
		mySavings.deposit(200);
		mySavings.withdraw(100);
		mySavings.deposit(350);
		mySavings.deductMonthlyCharge();
		System.out.println("Month 3: " + mySavings.getBalance());
		//Expected: 1798.75 + 800 - 150 + 200 - 100 + 350
		// = 2898.75 - ((5-5) * 1.25)
		//2898.75
	}

}
