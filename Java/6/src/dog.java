/**
 * Created by JP Bulman on 10/23/2017.
 */
import java.util.*;
import org.apache.commons.*;

public class dog {

    static char[][] playboard = new char[15][15];

    public static void buildboard(){

        for(char[] row : playboard){

            Arrays.fill(row,'*');

        }

    }

    public static void reconfigboard(){

        int k = 1;
        while (k<=30){
            System.out.print('-');
            k++;
        }

        for(int i = 0; i < playboard.length; i++){

            for (int j = 0; j < playboard[i].length;){

                System.out.print("|"+playboard[i][j]+"|");

            }
            System.out.println();
        }

        int e = 1;
        while (e<=30){
            System.out.print('-');
            e++;
        }

    }

    //Try and aim for as few PUBLIC fields as possible
    //Try for private

    public String name = "Dog";
    public int XPos = 0;
    public int YPos = 0;
    public char repchar = 'D';
    public int numofdogs = 0;

    private int size = 10;
    private int legs = 4;
    private int health = 20;
    private int age = 15;
    private boolean alive = true;
    private int movement = 2;
    private int bitepower = 2;

    public int getAge(){
        return age;
    }

    public int getSize(){
        return size;
    }

    public void takexlegs(int x){
        legs = legs - x;
    }

    public boolean getAlive(){
        return alive;
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
    public dog(int newmovement,int newHealth,int newbitepower,String name){
        movement = newmovement;
        health = newHealth;
        bitepower = newbitepower;
        //this refers to the object and not the variable
        //This is saying the objects name is the paramter variable name
        this.name = name;

        int maxX = playboard.length - 1;
        int maxY = playboard[0].length - 1;

        int randXpos,randYpos;

        do{
            randXpos = (int)(Math.random()*maxX);
            randYpos = (int)(Math.random()*maxY);
        }while (playboard[randXpos][randYpos] != '*');

        this.XPos = randXpos;
        this.YPos = randYpos;

        this.repchar = this.name.charAt(0);

        playboard[this.XPos][this.YPos] = this.repchar;

        numofdogs+=1;

    }


    public static void basic(){

        dog Joe = new dog(4,10,1,"J");

        System.out.println("Joe is old because he is "+Joe.age);

    }

}
