package dataStructAssignment;

public class QueueTester {

	public static void main(String[] args) {
		ListQueue<Integer> LQ = new ListQueue<Integer>(10);
		LQ.enqueue(2,2);
		/*LQ.enqueue(5,5);
		LQ.enqueue(3,3);
		LQ.enqueue(1,1);
		LQ.enqueue(4,4);
		LQ.enqueue(5);
		
		int x = LQ.peek();
		
		LQ.enqueue(1,1);*/
		LQ.enqueue(2,2);
		LQ.enqueue(4, 2);
		LQ.enqueue(3, 2);
		
		//System.out.println("LQ: size = " + LQ.size() + " x = " + x);
		
		LQ.display();
	
		/*LQ.dequeue();
		LQ.dequeue();
		
		
		LQ.display();*/
		
		if(LQ.isRegular()) {
			System.out.println("LQ is regular");
		}
		else {
			System.out.println("LQ is not regular");
		}
		
		
		ArrayQueue<Integer> AQ = new ArrayQueue<Integer>(10);
		AQ.enqueue(4, 4);
		
		AQ.display();
		
		AQ.enqueue(1, 1);
		AQ.enqueue(3, 3);
		AQ.enqueue(3, 3);
		AQ.enqueue(2, 2);
		AQ.enqueue(1, 1);
		AQ.enqueue(5);
		
		AQ.display();
		
		AQ.dequeue();
		AQ.dequeue();
		
		AQ.enqueue(1, 1);
		AQ.enqueue(3, 3);
		AQ.enqueue(3, 3);
		AQ.enqueue(2, 2);
		
		int y = AQ.peek();
		
		
		AQ.display();
		
		System.out.println("size = " + AQ.size() + " x = " + y + " " + AQ.isRegular());
		
		if(AQ.isRegular())
			System.out.println("AQ is regular");
		else
			System.out.println("AQ is not regular");
		
		
	}

}
