/**
 * Created by JP Bulman on 10/18/2017.
 */
public class proja {

    static int three = 3;

    public static void main(String[] args){

        System.out.println(three);

        changer();//redefines the variable

        System.out.println(three);


    }

    public static void changer(){
        three = 4;
    }

}
