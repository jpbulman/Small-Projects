import java.util.Scanner;

/**
 * Created by JP Bulman on 10/23/2017.
 */
public class MoreReview {

    static Scanner input = new Scanner(System.in);

    private static int factorial(int a){
        if (a==1){return 1;}
        else return a*factorial(a-1);
    }

    private static int fib(int a){
        if (a==1){return 1;}
        else if(a==2){return 1;}
        else return fib(a-1)+fib(a-2);
    }

    public static void main(String[] args){
        System.out.println(factorial(5));
        System.out.println(fib(7));

        int rnd = (int)(Math.random()*41);

        System.out.println(rnd);

        System.out.println("What is your guess?");

        int guess = input.nextInt();

        while (rnd!=guess){

            if (guess>40||guess<0){System.out.println("Out of range");}

            System.out.println("Try again");
            guess = input.nextInt();

        }

        System.out.println("Yes");

    }
}
