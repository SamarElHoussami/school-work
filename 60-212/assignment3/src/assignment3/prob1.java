package assignment3;

public class prob1 {

	public static void main(String[] args) {
		String number = "4012 8888 8888 1881";
		
		CreditCard myCard = new CreditCard(number);
		
		System.out.println(myCard.isValid());
		
	}

}
