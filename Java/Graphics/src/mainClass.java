/**
 * Created by JP Bulman on 9/27/2017.
 */
import javax.swing.JFrame;
import java.awt.Rectangle;

public class mainClass {

    //JFrames are for separate windows

    public static void main(String[] args){
        JFrame window = new JFrame();

        int winwidth = 640;
        int winheight = 480;

        window.setSize(winwidth,winheight);
        window.setTitle("JFrame");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);

        Rectangle rect = new Rectangle(5,10,300,100);//x,y,width,height
        //Add rectangle to jcomponent, then add jcomponent onto JFrame

    }
}
