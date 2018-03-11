package assignment1;
import java.net.URL;
import javax.swing.JOptionPane;
import javax.swing.ImageIcon;

public class prob4 {

	public static void main(String[] args) throws Exception 
	{
	URL imageLocation = new URL("https://pbs.twimg.com/profile_images/855289776420700160/6TuGxbIw_400x400.jpg"); 
	JOptionPane.showMessageDialog(null, "What up I'm Jared, I'm 19", "Title", JOptionPane.PLAIN_MESSAGE, new ImageIcon(imageLocation));
	}

}
