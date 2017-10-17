//import sun.awt.image.ImageWatched;
import sun.plugin.javascript.navig.Link;

import java.util.ArrayList;

/**
 * Created by JP Bulman on 10/15/2017.
 */
public class problem11 {
    //Supposed to say 1
    //If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
    //Find the sum of all the multiples of 3 or 5 below 1000.

    static int max = 1000;

    static ArrayList ton = new ArrayList(max);

    static ArrayList r = new ArrayList(3);

    static int sumArray1(ArrayList arr, int i){
            if(i==arr.size()){return (int)arr.get(i);}
            else {return ((int)arr.get(i)+sumArray1(arr,i++));}
    }

    static int sumArray(ArrayList arr){
        return sumArray1(arr,0);
    }

    public static void main(String args[]){

        for(int i=0;i<=max;i++){
             ton.add(i);
        }

        for(int i=0;i <= ton.size()-1;i++){
            System.out.println(ton.get(i));
        }

        //System.out.println(sumArray());

    }
}
