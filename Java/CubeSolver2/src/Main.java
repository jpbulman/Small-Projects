import java.util.Scanner;

/**
 * Created by JP Bulman on 10/24/2017.
 */
public class Main {

    //Todo:
        //Detect duplicates
        //Make less blank indents
        //Make the win statement work

    //BugList:
        //Does not like 10 digits, should be able to do that though


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

        String rndstr = String.valueOf(rnddigitnum);

        for(int i = 0; i < rndstr.length(); i++){
            if (containstwice(rndstr,rndstr.substring(i,i+1))){return rnd(length);}
        }

        if(rnddigitnum<Math.pow(10,(length-1))){return rnd(length);}
        else {return rnddigitnum;}
    }

    public static boolean containstwice(String checkingstr,String tocheck){

        int count = 0;

        for(int i = 0; i < checkingstr.length(); i++){
            if(checkingstr.substring(i,i+1).equals(tocheck)){count+=1;}
        }

        return (count>=2);

    }

    public static String Fermis(int answer,int theguess){
        int numoffermis = 0;

        String answerstr = String.valueOf(answer);
        String theguessstr = String.valueOf(theguess);

        for(int i = 0;i<theguessstr.length();i++){
            if (answerstr.substring(i,i+1).equals(theguessstr.substring(i,i+1))){numoffermis++;}
        }

        String finalfermis = "";
        int k = 0;

        while (k!=numoffermis){
            finalfermis=finalfermis+"Fermi ";
            k++;
        }

        return finalfermis;
    }

    public static String Picos(int answer,int theguess){
        int numofpicos = 0;

        String answerstr = String.valueOf(answer);
        String theguessstr = String.valueOf(theguess);

        for(int i = 0;i < theguessstr.length(); i ++){
            if(answerstr.contains(theguessstr.substring(i,i+1))&&!answerstr.substring(i,i+1).equals(theguessstr.substring(i,i+1))){
                numofpicos+=1;
            }
        }

        String finalpicos = "";
        int k = 0;

        while (k!=numofpicos){
            finalpicos=finalpicos+"Pico ";
            k++;
        }

        return finalpicos;
    }

    public static void main(String[] args){

        System.out.println("What amount of digits would you like to play with?");
        int digitnum = input.nextInt();

        int numtoguess = rnd(digitnum);

        //System.out.println(numtoguess);

        System.out.println("What is your guess?");
        int guess = input.nextInt();

        if (Picos(numtoguess,guess).equals("")&&Fermis(numtoguess,guess).equals("")){System.out.println("Bagel");}
        else {System.out.println(Fermis(numtoguess,guess));
              System.out.println(Picos(numtoguess,guess));}



        while (guess!=numtoguess){

            System.out.println("What is your guess?");
            guess = input.nextInt();

            if (guess==numtoguess){break;}

            if (Picos(numtoguess,guess).equals("")&&Fermis(numtoguess,guess).equals("")){System.out.println("Bagel");}
            else {System.out.println(Fermis(numtoguess,guess));
                  System.out.println(Picos(numtoguess,guess));}

        }

        System.out.println("Fermi!");

    }

}
