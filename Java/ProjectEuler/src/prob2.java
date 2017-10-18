/**
 * Created by JP Bulman on 10/17/2017.
 */
public class prob2 {

    public static void main(String[] args){

        int s1 = 1;
        int s2 = 2;

        int current = 2;

        int next = s1+s2;

        int currsum=0;

        while (next<=400){

            if(current%2==0){currsum+=current;}
            s1=s2;
            s2=next;
            //!!!

        }

    }
}
