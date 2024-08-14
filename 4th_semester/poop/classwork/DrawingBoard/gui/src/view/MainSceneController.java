package view;

import geometry.Line;
import geometry.Point;
import geometry.Rectangle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.layout.Pane;

import java.net.URL;
import java.util.Random;
import java.util.ResourceBundle;

public class MainSceneController {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button btnDrawLine;

    @FXML
    private Button btnDrawrRectangle;

    @FXML
    private Pane pnlDrawingBoard;

    private Random random;

    @FXML
    void btnDrawLineOnAction(ActionEvent event) {
        int x1 = (int) (pnlDrawingBoard.getWidth() * random.nextDouble());
        int y1 = (int) (pnlDrawingBoard.getHeight() * random.nextDouble());

        int x2 = (int) (pnlDrawingBoard.getWidth() * random.nextDouble());
        int y2 = (int) (pnlDrawingBoard.getHeight() * random.nextDouble());

        Line line = new Line(new Point(new int[]{x1, y1}), new Point(new int[]{x2, y2}));
        line.draw(pnlDrawingBoard);
    }

    @FXML
    void btnDrawrRectangleOnAction(ActionEvent event) {
        int x1 = (int) (pnlDrawingBoard.getWidth() * random.nextDouble());
        int y1 = (int) (pnlDrawingBoard.getHeight() * random.nextDouble());

        int maxWidth = (int) pnlDrawingBoard.getWidth() - x1;
        int maxHeight = (int) pnlDrawingBoard.getHeight() - y1;

        int width = random.nextInt(maxWidth + 1);
        int height = random.nextInt(maxHeight + 1);

        int x2 = x1 + width;
        int y2 = y1 + height;

        Rectangle rectangle = new Rectangle(new Point(new int[]{x1, y1}), new Point(new int[]{x2, y2}));
        rectangle.draw(pnlDrawingBoard);
    }


    @FXML
    void initialize() {
        assert btnDrawLine != null : "fx:id=\"btnDrawLine\" was not injected: check your FXML file 'MainScene.fxml'.";
        assert btnDrawrRectangle != null : "fx:id=\"btnDrawrRectangle\" was not injected: check your FXML file 'MainScene.fxml'.";
        assert pnlDrawingBoard != null : "fx:id=\"pnlDrawingBoard\" was not injected: check your FXML file 'MainScene.fxml'.";

        random = new Random();
    }
}
