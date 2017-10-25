import java.util.Scanner;

/**
 * Created by JP Bulman on 10/24/2017.
 */
public class Main {

    static Scanner input = new Scanner(System.in);

    public static int totalright(String word1,String word2){

        int counter = 0;

        for (int i = 0; i < word2.length(); i++){
            if(word2.contains(word1.substring(i,i+1))){counter++;}
        }
        return counter;
    }

    public static int rnd(int length){

        int rnddigitnum = (int)(Math.random() * (Math.pow(10,length)));

        //Makes the number 5 digits long
        if (rnddigitnum<Math.pow(10,(length-1))){return rnd(length);}

        return rnddigitnum;}

    public static String pico(int answer,int theguess){
        int numofpicos = 0;


        return "";
    }

    public static void main(String[] args){
        System.out.println("What amount of digits would you like to play with?");
        int digitnum = input.nextInt();

        int numtoguess = rnd(digitnum);

        System.out.println("What is your guess?");
        int guess = input.nextInt();

        while (guess!=numtoguess){

            System.out.println("What is your guess?");
            guess = input.nextInt();

        }

        System.out.println("Fermi!");

    }

}
