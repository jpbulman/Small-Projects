package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.Pane;

public class Controller {

    @FXML
    Pane mainPane;

    @FXML
    TextArea input;

    @FXML
    TextArea display;

    @FXML
    TextArea digitsinput;

    @FXML
    Button enterbutton;


    //static Scanner input = new Scanner(System.in);

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
            if (k==numoffermis-1){finalfermis=finalfermis+"Fermi";}
            else finalfermis=finalfermis+"Fermi ";
            k++;
        }

        //if(numoffermis==answerstr.length()){System.out.println(finalfermis+"!"); return "";}
        //else
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

    public static boolean duplicates(String str){

        boolean dupl = true;

        for(int i = 0; i < str.length(); i++){
            if(containstwice(str,str.substring(i,i+1))){dupl=dupl;}
            else if(i==str.length()-1){dupl=false;}
            else {continue;}
        }

        return dupl;
    }

    int numtoguess;
    int turncount = 0;

    public void enterPressed(){

        String digitnumstr = digitsinput.getText();

        int digitnum = Integer.parseInt(digitnumstr);

        if(turncount==0) {
            numtoguess = rnd(digitnum);
            //display.setText("");
        }

        display.setText("What is your guess?");
        String guessstr = input.getText();
        int guess = Integer.parseInt(guessstr);

        display.appendText("\n"+guessstr);

        System.out.println(numtoguess);

        if (guess==numtoguess){display.appendText("\n");display.appendText(Fermis(numtoguess,guess));System.out.println("Turn Count: "+turncount);}


        turncount++;

    }

    public void initialize() {

        display.setText("What is your guess?");

    }

}
