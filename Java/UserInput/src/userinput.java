/**
 * Created by JP Bulman on 10/13/2017.
 */
import java.util.*;
public class userinput {

    static int factorial(int n){

        if (n==1){
            return 1;
        }
        else return(n*factorial(n-1));
    }

    static Scanner myscanner = new Scanner(System.in);

    public static void main(String args[]){

        System.out.println("Number!");

        if(myscanner.hasNextInt()){
            int usernum = myscanner.nextInt();

            int fact = factorial(usernum);

            System.out.println("The factorial of "+usernum+" is " + fact);
        }

    }
}
