package assignment2;
import javax.swing.*;

 public class prob1{
	
	public static void main(String[] args) {
	JFrame frame = new JFrame();
	frame.setSize(550, 600);
	
	JPanel pane = new JPanel();
	pane.setLayout(new BoxLayout(pane, BoxLayout.X_AXIS));
		
	frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
	TrafficLight traffic1 = new TrafficLight(1);
	TrafficLight traffic2 = new TrafficLight(2);
	TrafficLight traffic3 = new TrafficLight(3);

	pane.add(traffic1);
	pane.add(traffic2);
	pane.add(traffic3);
		
	frame.add(pane);
	
	frame.setVisible(true);
	}

}

