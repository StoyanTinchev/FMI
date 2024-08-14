package geometry;

import javafx.scene.layout.Pane;

public class Line extends Point {
    //    private Point sPoint; //start point
    private Point ePoint; //end point

    public Line(Point sPoint, Point ePoint) {
        setePoint(ePoint);
        setsPoint(sPoint);
    }

    public Line() {
        this(new Point(), new Point(new int[]{10, 0}));
    }

    public Line(Line line) {
        this(line.getsPoint(), line.getePoint());
    }

    public Point getsPoint() {
        return getPoint();
    }

    public void setsPoint(Point sPoint) {
//        if (sPoint != null){
//            this.sPoint = new Point(sPoint);
//        }else{
//            this.sPoint = new Point();
//        }
        setPoint(sPoint);
    }

    public Point getePoint() {
        return new Point(ePoint);
    }

    public void setePoint(Point ePoint) {
        if (ePoint != null) {
            this.ePoint = new Point(ePoint);
        } else {
            this.ePoint = new Point();
        }
    }

    public void draw(Pane pane) {
        int[] coordsS = getPoint().getCoords();
        int[] coordsE = ePoint.getCoords();
        javafx.scene.shape.Line lineFX =
                new javafx.scene.shape.Line(
                        coordsS[0], coordsS[1],
                        coordsE[0], coordsE[1]
                );

        pane.getChildren().add(lineFX);
    }

    public double measure() {
        return Math.sqrt(getPoint().getCoords()[0] - ePoint.getCoords()[0] * (getPoint().getCoords()[0] - ePoint.getCoords()[0])) +
                (getPoint().getCoords()[1] - ePoint.getCoords()[1] * (getPoint().getCoords()[1] - ePoint.getCoords()[1]));
    }

    @Override
    public String toString() {
        return String.format("Start point %s, End point %s",
                getPoint()
                , ePoint);
    }
}
