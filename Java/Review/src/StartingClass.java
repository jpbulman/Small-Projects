/**
 * Created by JP Bulman on 10/13/2017.
 */
import java.util.*;

public class StartingClass {

    static String hi = "Hello";
    static String seeya = "Goodbye";

    public static void main(String arg[]){
        System.out.println(hi.concat(" ").concat(seeya));
        System.out.println(Float.MAX_VALUE);
        System.out.println(Byte.MAX_VALUE);
        System.out.println(Integer.MAX_VALUE);

        int three = 3;

        double dbl = (double) three;

        System.out.println(dbl);
    }
}
