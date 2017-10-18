import java.util.Map;

/**
 * Created by JP Bulman on 10/17/2017.
 */
public class loops {

    static double fact(double n){
        if (n==0){return 1;}
        else {return (n*fact(n-1));}
    }

    public static void main(String[] args){

        int i = 0;

        while (i<=30){

            if(i%3==0){i+=1;continue;}

            if(i==22){break;}

            //Continue skips the rest of the loop and instead goes back to the top with the new information
            //Break stops the loop all together

            System.out.println(i);
            i+=1;
        }


        //Pi!
        double mypi = 4.0;
        double dem = 3.0;

        while (dem <= 20){

            mypi = mypi - (4/dem) + (4/(dem+2));
            dem+=4.0;
            System.out.println(mypi);

        }

        System.out.println(Math.PI);



        System.out.println();
        System.out.println();

        //e!
        double mye = 0.0;
        double deme = 0.0;

        while (deme<=17){

            mye = mye + (1.0/fact(deme));
            deme+=1.0;
            System.out.println(mye);

        }

        System.out.println(Math.exp(1));





        System.out.println();
        System.out.println();

        //Pi but better, it converges faster, ALOT faster
        double mybetterpi = 3.0;
        double mybetterdem = 2.0;

        while (mybetterdem<=99999){

            mybetterpi = mybetterpi + (4/(mybetterdem*(mybetterdem+1)*(mybetterdem+2))) - (4/((mybetterdem+2)*(mybetterdem+3)*(mybetterdem+4)));

            mybetterdem+=4;

            System.out.println(mybetterpi);

        }

        System.out.println(Math.PI);


   }
}
