import javax.swing.*;
import javax.swing.JComponent;
import java.awt.*;

/**
 * Created by JP Bulman on 9/27/2017.
 */
public class drawingComponent extends JComponent{

    //Called whenever frame is changed
    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g; //first part is cast, recognizes g as Graphics2D

        Rectangle rect1 = new Rectangle(5,5,100,300);
    }
}
