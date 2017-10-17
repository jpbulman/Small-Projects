/**
 * Created by JP Bulman on 10/17/2017.
 */
public class pal {

    static int palint = 101;

    //Determines if a String is a Palindrome
    private static boolean palq(String str){

        String firsthalf = str.substring(0,(int)Math.ceil(str.length()/2)+1);
        String secondhalf = str.substring((int)Math.floor(str.length()/2),str.length());

            return  (firsthalf.equals(reverse(secondhalf,secondhalf.length())));
        
    }

    //Reverses a string
    private static String reverse(String s,int pos){

        String currchar = s.substring(pos-1,pos);

        if ((pos-1)==0){return currchar;}
        else {return currchar+reverse(s,(pos-1));}

    }

    public static void main(String[] args){

        System.out.println(palq("1234321"));

    }
}

