/**
 * Created by JP Bulman on 10/23/2017.
 */
public class dog {

    //Try and aim for as few PUBLIC fields as possible
    //Try for private

    public String name = "-";

    private int size = 10;
    private int legs = 4;
    private int health = 20;
    private int XPos = 0;
    private int age = 15;
    private boolean alive = true;

    public int getAge(){
        return age;
    }

    public int getSize(){
        return size;
    }

    public void takexlegs(int x){
        legs = legs - x;
    }


    //Next two methods are 'overloading'
    //Same name, but different attributes
    public void takexhealth(int x){
        health = health - x;

        if(health<=0){alive=false;}
    }

    public void takexhealth(double x){
        int intx = (int) x;
        health = health - intx;

        if(health<=0){alive=false;}
    }

    //Constructor
    //Only executed once per object
    //Cannot have void
    //You are allowed to overload constructors for different attributes
    //Default constructor (if nothing is specified) is just the basic:
    //public cons(){}
    public dog(int newlegs,int newHealth,boolean newAlive,int age){
        legs = newlegs;
        health = newHealth;
        alive = newAlive;
        //this refers to the object and not the variable
        //This is saying the objects age is the paramter variable age
        this.age = age;
    }


    public static void basic(){

        dog Joe = new dog(4,10,true,30);

        System.out.println("Joe is old because he is "+Joe.age);

    }

}
