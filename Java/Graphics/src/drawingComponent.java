import javax.swing.*;
import javax.swing.JComponent;
import java.awt.*;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;

/**
 * Created by JP Bulman on 9/27/2017.
 */
public class drawingComponent extends JComponent{

    //Called whenever frame is changed
    public void paintComponent(Graphics g){
        Graphics2D g2 = (Graphics2D) g; //first part is cast, recognizes g as Graphics2D

        Color red = new Color(255,0,0);//r,g,b (0-255)

        g2.setColor(red);

        Rectangle rect1 = new Rectangle(5,5,100,300);
        g2.draw(rect1); //g2.fill(rect1) fills the shape

        g2.setColor(new Color(0,0,255));

        Ellipse2D.Double ellipse1 = new Ellipse2D.Double(200,200, 30,90); //.Double is an inner class
        g2.fill(ellipse1);

        g2.setColor(Color.CYAN);

        Line2D.Double line1 = new Line2D.Double(150,150,100,50);
        g2.draw(line1);

        Point2D.Double P0 = new Point2D.Double(200,200);
        Point2D.Double P1 = new Point2D.Double(500,200);

        Line2D.Double line2 = new Line2D.Double(P0,P1);
        g2.draw(line2);
    }
}
