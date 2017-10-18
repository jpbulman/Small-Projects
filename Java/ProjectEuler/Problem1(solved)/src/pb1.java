/**
 * Created by JP Bulman on 10/17/2017.
 */
public class pb1 {

    public static void main(String[] args){

        int i = 0;

        int currsum = 0;

        while (i<=1000){

            if (i==1000){System.out.println(currsum);}
            else if(i%3==0||i%5==0){currsum+=i;i++;}
            else{i++;}
        }

    }
}
