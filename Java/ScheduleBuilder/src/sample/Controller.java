package sample;

import javafx.fxml.FXML;
import javafx.scene.control.ComboBox;
import javafx.scene.control.SplitMenuButton;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.Pane;
import javafx.scene.layout.StackPane;
import javafx.scene.layout.VBox;
import javafx.scene.paint.Color;
import javafx.scene.paint.Paint;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.Text;

import java.util.HashMap;

import static java.lang.Integer.parseInt;

public class Controller {

    @FXML
    Pane mainPane;

    @FXML
    Rectangle bkg;

    @FXML
    TextField start;

    @FXML
    TextField end;

    @FXML
    Text starttime;

    @FXML
    VBox eventvbox;

    @FXML
    ComboBox eventlist;

    @FXML
    TextField durationholder;

    @FXML
    TextField compname;

    @FXML
    ComboBox roundholder;

    //Buglist
        //Cant edit start after its made
        //Colon in start requirement should not be in substring
        //Null situations
        //Might want to do new event as a classs

    //Event and then duration
    static HashMap eventmapper  = new HashMap();

    public void createEvent(){

        //if(eventvbox.getChildren().size()==0){return;}

        if(starttime.getText().length()!=0&&!eventlist.getValue().equals("Event")&&!durationholder.getText().equals("Duration")) {

            int duration = parseInt(durationholder.getText());
            String eventname = (String)eventlist.getValue();
            eventmapper.put(eventname,duration);
            String roundnum = roundholder.getValue().toString();



            StackPane neweevent = new StackPane();
            neweevent.setPrefWidth(460);
            neweevent.setPrefHeight(20);
            eventvbox.getChildren().add(neweevent);

            Rectangle eventrect = new Rectangle();
            eventrect.setWidth(460);
            eventrect.setHeight(duration);
            eventrect.setStroke(Color.BLACK);
            eventrect.setFill(determiner(eventname));
            eventrect.setVisible(true);
            neweevent.getChildren().add(eventrect);



            Text displayname = new Text();
            //displayname.setX(eventrect.getX()+5);
            //displayname.setY(eventrect.getY()/2);
            displayname.setText(eventname+" "+roundparser(roundnum,eventname));
            displayname.setFont(Font.font("300"));
            displayname.setVisible(true);
            neweevent.getChildren().add(displayname);

        }
        else {}
    }

    public Color determiner(String event){

        switch (event) {
            case "2x2":
                return Color.AQUA;
            case "3x3":
                return Color.LIGHTSTEELBLUE;
            case "4x4":
                return Color.CRIMSON;
            case "5x5":
                return Color.PINK;
            case "6x6":
                return Color.LIGHTGREEN;
            case "7x7":
                return Color.KHAKI;
            case "3x3 OH":
                return Color.GOLD;
            case "3x3 BLD":
                return Color.ORANGE;
            case "3x3 FMC":
                return Color.TOMATO;
            case "3x3 Feet":
                return Color.LIGHTSALMON;
            case "Megaminx":
                return Color.SEAGREEN;
            case "Pyraminx":
                return Color.SKYBLUE;
            case "Clock":
                return Color.GRAY;
            case "Skewb":
                return Color.SANDYBROWN;
            case "Square-1":
                return Color.WHITE;
            case "MBLD":
                return Color.CORNSILK;
            case "4x4 BLD":
                return Color.IVORY;
            case "5x5 BLD":
                return Color.LAWNGREEN;
            default:
                return Color.LEMONCHIFFON;
        }

    }

    public String roundparser(String i, String event){

        if (event.equals("Break")||event.equals("Cleanup")||event.equals("Awards")||event.equals("Lunch")){return "";}

        if(i.equals("Final")||i.equals("Combined Final")){return i;}
        else {return "Round "+i;}
    }

    public void initialize(){

        roundholder.getItems().addAll(
                "1",
                "2",
                "3",
                "4",
                "Final",
                "Combined Final"
        );

        eventlist.getItems().addAll(
                "3x3",
                "2x2",
                "4x4",
                "5x5",
                "6x6",
                "7x7",
                "3x3 OH",
                "3x3 BLD",
                "3x3 FMC",
                "3x3 Feet",
                "Megaminx",
                "Pyraminx",
                "Clock",
                "Skewb",
                "Square-1",
                "MBLD",
                "4x4 BLD",
                "5x5 BLD",
                "Lunch",
                "Break",
                "Awards",
                "Cleanup",
                "Custom..."
        );


        //Generates the basic start block
        compname.setOnKeyPressed(e ->{

            int numofstart = eventvbox.getChildren().size();

            if (numofstart!=0){return;}

            if (e.getCode()== KeyCode.ENTER){
                String startinput = start.getText();
                String endinput = end.getText();
                String currentevent = (String)eventlist.getValue();
                if((startinput.substring(1,2).equals(":")||startinput.substring(2,3).equals(":"))&&((startinput.length()==4)||(startinput.length()==5))&&
                        ((endinput.length()==4)||(endinput.length()==5))&&compname.getText().length()!=0) {
                    starttime.setText(startinput);
                    Rectangle starter = new Rectangle(460,20);
                    starter.setFill(Color.web("#f3ff1f"));
                    starter.setVisible(true);
                    starter.setStroke(Color.BLACK);
                    eventvbox.getChildren().add(starter);

                    Text startname = new Text("Start of "+compname.getText());
                    startname.setX(85);
                    startname.setY((starter.getHeight()/2)+5);
                    mainPane.getChildren().add(startname);
                }
                else {starttime.setText(starttime.getText());}
            }
        });//End of start block



    }

}
