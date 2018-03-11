package assignment2;

import java.awt.*;
import javax.swing.*;

public class TrafficLight extends JComponent{

	private int stage;
	
	TrafficLight(int i){
		stage = i;
	}
	
	public void paintComponent (Graphics g)
	{
		Graphics2D g2 = (Graphics2D) g;	
		
		g2.setPaint(Color.yellow);
		g2.fillRect(50, 170, 70, 200);
		g2.setPaint(Color.black);
		g2.drawRect(50, 170, 70, 200);
		
		g2.setPaint(Color.black);
		g2.fillOval(55, 175, 60, 60);
		g2.fillOval(55, 240, 60, 60);
		g2.fillOval(55, 305, 60, 60);
		
		
		if(stage == 1) {
			g2.setPaint(Color.red);
			g2.fillOval(55, 175, 60, 60);
		}
		
		if(stage == 2) {
			g2.setPaint(Color.orange);
			g2.fillOval(55, 240, 60, 60);
		}
		
		if(stage == 3) {
			g2.setPaint(Color.green);
			g2.fillOval(55, 305, 60, 60);
		}
	}
}


