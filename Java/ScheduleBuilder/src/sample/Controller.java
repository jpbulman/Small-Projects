package sample;

import javafx.fxml.FXML;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyCode;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.shape.Rectangle;
import javafx.scene.text.Text;

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

    public void initialize(){

        start.setOnKeyPressed(e ->{
            if (e.getCode()== KeyCode.ENTER){
                String input = start.getText();
                starttime.setText(input);
            }
        });

    }

}
