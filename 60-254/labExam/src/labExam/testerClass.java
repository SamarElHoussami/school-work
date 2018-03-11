package labExam;
import java.io.*;
import java.io.FileNotFoundException;
import java.util.*;


public class testerClass {

	public static void main(String[] args) {
		Scanner console = new Scanner(System.in);
		System.out.println("Please enter input file name");
		String inputFile = console.next();
		System.out.println("Please enter output file name");
		String outFile = console.next();
		
		try {
			Scanner in = new Scanner(new File(inputFile));
			PrintWriter out = new PrintWriter(new File(outFile));
			
			while(in.hasNextLine()) {
				String line = in.nextLine();
				int i = 0;
				while(!Character.isDigit(line.charAt(i))) { i++; }
				String name = line.substring(0, i).trim();
				String age = line.substring(i);
				out.println(name + " " + age);
				System.out.println(name + " " + age);
			}
			
			in.close();
			out.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		int[] array = {1, 1, 1};
		
		HIndex test = new HIndex(array);
		System.out.println("The h-index is: " + test.findHIndex());
	}

}
