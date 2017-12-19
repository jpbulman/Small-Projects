/**
 * Created by JP Bulman on 10/18/2017.
 */
public class prob2 {

    //prob2 starts with 1,2

    static int fib(int n){

        if(n==2){return 2;}
        else if(n==1){return 1;}
        else {return fib(n-2)+fib(n-1);}
    }

    public static void main(String[] args){

        int tryn = 1;

        while (fib(tryn)<=4000000){
            System.out.println(tryn);
            tryn++;
        }

        tryn = 1;

        //The 32nd digit and below are < 4000000

        int currentsum = 0;

        while (fib(tryn)<=4000000){
            if (fib(tryn)%2==0){currentsum+=fib(tryn);tryn++;}
            else {tryn++;continue;}
            System.out.println(currentsum);
        }



    }
}
