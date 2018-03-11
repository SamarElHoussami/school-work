package dataStructAssignment;

public class ArrayQueue<T> {
	
	private T[] arr;		//data array of type T
	private int[] pri;	//priority array of type int
	private int total, front, rear, MAX_SIZE;
	
	
	
	/**
	 * Constructs two arrays of MAX_SIZE and initializes front, rear, and total
	 */
	@SuppressWarnings("unchecked") 
	public ArrayQueue(int size) {
		arr = (T[])new Object[size];
		pri = new int[size];
		front = 0;
		rear = -1;
		total = 0;
		MAX_SIZE = size;
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
		
		T d = ele;
		
		//if array is empty
		if(isEmpty()) {
			arr[0] = d;
			pri[0] = priority;
			rear = (rear + 1) % MAX_SIZE;
		}
		
		else {
			int i;
		
			rear = (rear + 1) % MAX_SIZE; 
			
			//shift elements of both arrays 1 spot to the right until insertion point is found
			for(i = rear; i != front && priority <= pri[i-1] ; i = (i-1) % MAX_SIZE) {
				pri[i] = pri[(i-1) % MAX_SIZE];
				arr[i] = arr[(i-1) % MAX_SIZE];
			}
		
			//insert data in arr[] and priority in pri[] at same index
			arr[i] = d;
			pri[i] = priority;
		
		}
			
		total++;
	}	
	
	/**
	 * Adds element to end of queue with a default priority 5
	 * @param ele the element to be added
	 */
	public void enqueue(T ele) {
		if(isFull()) {
			System.out.println("Queue is full");
			return;
		}
		
		T d = ele;
		
		if(isEmpty()) {
			arr[0] = d;
			pri[0] = 5;
			rear = (rear + 1) % MAX_SIZE;
		}
		
		rear = (rear + 1) % MAX_SIZE;
		arr[rear] = d;
		pri[rear] = 5;
		
		total++;
	}
	
	/**
	 * Removes element with highest priority from the queue
	 * @return d the element with the highest priority
	 */
	public T dequeue() {
		if(isEmpty()) {
			System.out.println("Queue is empty.");
			return null;
		}
		
		T d = arr[0];
		
		//shift elements of both arrays 1 spot to the left
		for(int i = 0; i < rear; i = (i+1) % MAX_SIZE) {
			arr[i] = arr[(i+1) % MAX_SIZE];
			pri[i] = pri[(i+1) % MAX_SIZE];
		}
		
		rear--;
		total--;
		
		return d;
	}
	
	/**
	 * Determines if every element has the same priority
	 * @return true if every element has the same priority
	 * @return false if every element does not have the same priority
	 */
	public boolean isRegular() {
		return pri[front] == pri[rear];
	}
	
	/**
	 * Returns element with highest priority without removing it
	 * @return d the element with the highest priority
	 */
	public T peek() {
		if(isEmpty()) {
			System.out.println("Queue is empty.");
			return null;
		}
		
		T d = arr[0];
		return d;
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
	 * Returns size of queue
	 * @return total the size of the queue
	 */
	public int size() {
		return total;
	}
	
	/**
	 * Goes through array and displays elements
	 */
	public void display() {
		int i = front;
		do {
			System.out.print(arr[i] + " ");
			i = (i+1) % MAX_SIZE;
		} while(i <= rear && i != front);
		
		System.out.println();
	}
	
}

