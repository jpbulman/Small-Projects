import java.util.Scanner;

/**
 * Created by JP Bulman on 10/15/2017.
 */
public class fizbiz {

    static void fizmethod(int towhere,int wherenow){
        if (wherenow==towhere){ if ((wherenow%3==0)&&(wherenow%5==0)){System.out.println("Fizbiz"+wherenow); return;}
        else if(wherenow%5==0){System.out.println("Biz"+wherenow); return;}
        else if(wherenow%3==0){System.out.println("Fiz"+wherenow); return;}
        else {System.out.println(wherenow); return;}}

        if ((wherenow%3==0)&&(wherenow%5==0)){System.out.println("Fizbiz"+wherenow);fizmethod(towhere,1+wherenow);}
        else if(wherenow%5==0){System.out.println("Biz"+wherenow);fizmethod(towhere,1+wherenow);}
        else if(wherenow%3==0){System.out.println("Fiz"+wherenow);fizmethod(towhere,1+wherenow);}
        else {System.out.println(wherenow);fizmethod(towhere,1+wherenow);}
    }

    static void thefiz (int n){fizmethod(n,0);}

    static Scanner myscanner = new Scanner(System.in);

    public static void main(String args[]){
        System.out.println("What number do you want to take the fizbiz until?");
        int fizint = myscanner.nextInt();
        thefiz(fizint);
    }

}
