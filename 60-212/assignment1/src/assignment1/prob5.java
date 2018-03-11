package assignment1;

public class prob5 {

	public static void main(String[] args) {
	
		double so = 5;
		double vo = 7;
		double g = 9.8;
		double t = 3;
		
		double a = 4;
		double p = 8;
		double m1 = 2;
		double m2 = 5;
		
		double s = so + vo + (1/2)*(g * Math.pow(t, 2));
		double G = (4*Math.pow(3.14, 2)) * (Math.pow(a, 3)/(Math.pow(p, 2)*(m1 + m2)));
		
		System.out.printf("S: %.2f\nG: %.2f", s, G);
		
	}

}
