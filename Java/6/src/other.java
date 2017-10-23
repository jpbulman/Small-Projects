/**
 * Created by JP Bulman on 10/23/2017.
 */
public class other {

    public static void main(String[] args){

        dog John = new dog(1,1,true,10);

        //Does onot work because field is private
        //System.out.println(John.age);

        John.name = "ruffer";

        System.out.println(John.name);
        //Does work here because there is a public method to get the age
        System.out.println(John.getAge());

    }
}
