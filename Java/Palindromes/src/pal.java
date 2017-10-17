/**
 * Created by JP Bulman on 10/16/2017.
 */
public class pal {

    static int palint = 101;

    private boolean palq(int i){

        String numString = Integer.toString(i);

        int numlength = numString.length();

        if(numlength%2==0){
        }
        else {}

        return true;
    }

    private static String reverse(String s,int pos){

        String currchar = s.substring(s.length()-pos);

        if (pos==s.length()){return currchar;}
        else {return currchar.concat(reverse(s,pos++));}

        //return "";
    }

    public static void main(String args){

        reverse("cabs",0);

        System.out.println("hi");

    }
}
