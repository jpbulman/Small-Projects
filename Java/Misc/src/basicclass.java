import java.util.Scanner;

/**
 * Created by JP Bulman on 10/14/2017.
 */
public class basicclass {

    static Scanner myscanner = new Scanner(System.in);

    public static void main(String args[]){
        int rndnum1 = (int) (Math.random() * 30);

        int rndnum2 = (int) (Math.random() * 30);

        int bigger = (rndnum1>rndnum2) ? rndnum1 : rndnum2;

        System.out.println(rndnum1);
        System.out.println(rndnum2);
        System.out.println(bigger);

        int userint = myscanner.nextInt();

        switch (userint){
            case 9:
            case 10: System.out.println("You entered 9 or 10"); break;
            case 11: System.out.println("You entered 11"); break;
            case 2345324: System.out.println("Wow!"); break;
            default: System.out.println("That was not 10,11, or 2345324"); break;
        }

    }
}
