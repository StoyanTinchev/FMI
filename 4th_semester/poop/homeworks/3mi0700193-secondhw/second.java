package org.fmi.problem1calendar;

import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.shape.Line;
import javafx.stage.Stage;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class HelloApplication extends Application {
    final int HEIGHT = 500;
    final int WIDTH = 500;

    enum Direction {
        END_Y,
        START_Y,
        END_X,
        START_X
    }

    @Override
    public void start(Stage stage) {
        Map<Direction, Double> directionMap = new HashMap<>(
                Map.of(
                        Direction.START_X, (double) WIDTH / 2,
                        Direction.END_X, (double) WIDTH / 2,
                        Direction.START_Y, (double) HEIGHT / 2,
                        Direction.END_Y, (double) HEIGHT / 2
                )
        );

        double step = 20;

        // 0 - endY, 1 - startY, 2 - endX, 3 - startX
        int direction = 0;
        Direction currentDirection = Direction.values()[direction];

        Group root = new Group();
        while ((HEIGHT - directionMap.get(Direction.END_Y)) > 20) {
            if (direction == 0 || direction == 2) {
                directionMap.put(currentDirection, directionMap.get(currentDirection) + step);
            } else {
                directionMap.put(currentDirection, directionMap.get(currentDirection) - step);
            }


            Line line = new Line();
            line.setStroke(javafx.scene.paint.Color.RED);

            line.setEndY(directionMap.get(Direction.END_Y));
            line.setStartY(directionMap.get(Direction.START_Y));
            line.setEndX(directionMap.get(Direction.END_X));
            line.setStartX(directionMap.get(Direction.START_X));

            root.getChildren().add(line);


            if (direction == 3)
                direction = 0;
            else
                direction += 1;
            currentDirection = Direction.values()[direction];

            if (direction == 0 || direction == 2) {
                step += 20;
                directionMap.put(currentDirection, directionMap.get(currentDirection) - step);
            } else {
                directionMap.put(currentDirection, directionMap.get(currentDirection) + step);
            }
        }

        //Creating a Scene
        Scene scene = new Scene(root, WIDTH, HEIGHT);

        //Setting title to the scene
        stage.setTitle("Draw square shaped spiral");

        //Adding the scene to the stage
        stage.setScene(scene);

        //Displaying the contents of a scene
        stage.show();
    }

    public static void main(String args[]) {
        launch(args);
    }
}