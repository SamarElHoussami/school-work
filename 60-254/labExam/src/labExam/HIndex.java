package labExam;

import java.util.Arrays;

public class HIndex {

	private int[] citations;
	private int index;
	private int temp;
	
	
	public HIndex(int[] array) {
		
		//Bubble sort array in descending order
		for(int i = 0; i < array.length - 1; i++) {
			for(int y = 0; y < array.length - i - 1; y++) {
				if(array[y] < array[y + 1]) {
					temp = array[y];
					array[y] = array[y+1];
					array[y+1] = temp;
					
				}
			}
		}
		
		citations = Arrays.copyOf(array, array.length);
		index = 0;
	}
	
	public int findHIndex() {
		System.out.print("Sorted citations: ");
		for(int i = 0; i < citations.length; i++) {
			System.out.print(citations[i] + " ");
		}
		System.out.println("\n");
		
		
		for(int i = 0; i < citations.length; i++) {
			//System.out.println("Citation: " + citations[i] + "  current index: " + index);
			if(citations[i] > index) {
				index++;
				//System.out.println("now the index is " + index);
			}
		}
		return index;
	}
}//citations[i] > 0 && 
