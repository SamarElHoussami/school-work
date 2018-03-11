package dataStructAssignment;

public class ListQueue<T> {
	
	private int MAX_SIZE;
	private int total;
	private Node front = new Node();
	private Node rear = new Node();
	
	//Node class
	public class Node{
		private T ele;
		private int priority;
		private Node next;
		
		/**
		 * Constructs node with element and priority
		 */
		public Node(T e, int p) {
			ele = e;
			priority = p;
		}
		
		public Node() {
			
		}
	}

	/**
	 * Constructs list with max size
	 */
	public ListQueue(int size) {
		MAX_SIZE = size;
	    front = null;
	    rear = null;
	    total = 0;
	}
	
	/**
	 * Adds element to queue based on priority
	 * @param ele the element to be added
	 * @param priority the priority of the element
	 */
	public void enqueue(T ele, int priority){
		
		if(isFull()) {
			System.out.println("Queue is full");
			return;
		}
		
		//create new node with set element and priority
		Node nNode = new Node(ele, priority);
	
		if(isEmpty()) {
			front = nNode;
			rear = nNode;
			nNode.next = null;
		}
		
		else if(priority == 1) {
			nNode.next = front;
			front = nNode;
		}
		
		else {
			Node curr = front;
			while(curr.next != null && priority >= curr.next.priority) {
				curr = curr.next;
			}
			
			if(priority == 5) {
				nNode.next = null;
				rear = nNode;
			}
			
			else 
				nNode.next = curr.next;
			
			curr.next = nNode;
		}
		
		total++;
	}
	
	/**
	 * Adds element to end of queue with a default priority 5
	 * @param ele the element to be added
	 */
	public void enqueue(T ele){
		
		if(isFull()) {
			System.out.println("Queue is full");
			return;
		}
		
		Node nNode = new Node(ele, 5);
		
		if(isEmpty()) {
			front = nNode;
			rear = nNode;
		}

		Node curr = front;
	
		while(curr.next != null) {
			curr = curr.next;
		}
		
		
		
		nNode.next = null;
		rear = nNode;
		
		curr.next = nNode;
		
		total++;
	}
	
	/**
	 * Returns size of queue
	 * @return total the size of the queue
	 */
	public int size() {
		return total;
	}
	
	/**
	 * Returns element with highest priority without removing it
	 * @return ele the element with the highest priority
	 */
	public T peek() {
		if(isEmpty()) {
			System.out.println("Queue is empty.");
			return null;
		}
		
	    T ele = front.ele;
		return ele;
	}
	
	/**
	 * Removes element with highest priority from the queue
	 * @return ele the element with the highest priority
	 */
	public T dequeue() {
		if(isEmpty()) {
			System.out.println("Queue is empty.");
			return null;
		}
	
		T ele = front.ele;
		front = front.next;
		total--;
		
		return ele;
	}
	
	/**
	 * Determines if list is full
	 * @return true if list is full
	 * @return false if list is not full
	 */
	public boolean isFull() {
		return total == MAX_SIZE;
		}
	
	/**
	 * Determines if list is empty
	 * @return true if list is empty
	 * @return false if list is not empty
	 */
	public boolean isEmpty() {
		return total == 0;
	}
	
	/**
	 * Determines if every element has the same priority
	 * @return true if every element has the same priority
	 * @return false if every element does not have the same priority
	 */
	public boolean isRegular() {
		return front.priority == rear.priority;
	}
	
	/**
	 * Goes through list and displays elements
	 */
	public void display() {
		Node curr = new Node();
		curr = front;
		while(curr != null) {
			System.out.print(curr.ele + " ");
			curr = curr.next;
		}
		
		System.out.println();
		return;
	}
}

