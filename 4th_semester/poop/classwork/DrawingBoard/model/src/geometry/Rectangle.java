package geometry;

import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;

public class Rectangle extends Point { //upper left corner
    private Point lPoint;

    public Rectangle(Point uPoint, Point lPoint) {
        setuPoint(uPoint);
        setlPoint(lPoint);
    }

    public Rectangle() {
        this(new Point(), new Point(new int[]{10, 10}));
    }

    public Rectangle(Rectangle rectangle) {
        this(rectangle.getuPoint(), rectangle.lPoint);
    }

    public Point getuPoint() {
        return getPoint();
    }

    public void setuPoint(Point uPoint) {
        setPoint(uPoint);
    }

    public Point getlPoint() {
        return lPoint;
    }

    public void setlPoint(Point lPoint) {
        if (lPoint != null) {
            this.lPoint = new Point(lPoint);
        } else {
            this.lPoint = new Point();
        }
    }

    public int getWidth() {
        return Math.abs(getPoint().getCoords()[0] - lPoint.getCoords()[0]);
    }

    public int getHeight() {
        return Math.abs(getPoint().getCoords()[1] - lPoint.getCoords()[1]);
    }

    public void draw(Pane pane) {
        int width = getWidth();
        int height = getHeight();
        int[] coords = getPoint().getCoords();

        javafx.scene.shape.Rectangle rectangleFX = new javafx.scene.shape.Rectangle(
                coords[0], coords[1], width, height
        );

        rectangleFX.setStroke(Color.BLACK);
        rectangleFX.setFill(null);

        pane.getChildren().add(rectangleFX);
    }

    public int measure() {
        return 2 * (getWidth() + getHeight()); // perimeter
    }

    @Override
    public String toString() {
        return String.format("Upper left corner %s, " +
                        "width: %d, height: %d", getPoint().toString(),
                getWidth(), getHeight());
    }
}
