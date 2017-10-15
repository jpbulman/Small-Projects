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

    static boolean Collatz(int n){
        if(n==4){return true;}
        else if(n%2==0){return Collatz(n/2);}
        else return Collatz((3*n)+1);
    }

    static Scanner myscanner = new Scanner(System.in);

    public static void main(String args[]){

        System.out.println("Number!");

        if(myscanner.hasNextInt()){
            int usernum = myscanner.nextInt();

            int fact = factorial(usernum);

            System.out.println("The factorial of "+usernum+" is " + fact);

            System.out.println("Collatz?");

            int usern = myscanner.nextInt();

            System.out.println(Collatz(usern));

            System.out.println("Round up?");

            double n = myscanner.nextDouble();

            int n1 = (int) Math.ceil(n);

            System.out.println(n1);

        }

    }
}
