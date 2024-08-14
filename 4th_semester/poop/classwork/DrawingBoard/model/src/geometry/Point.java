package geometry;

public class Point {
    private int[] coords; //[x; y]

    public Point(int[] coords) {
        setCoords(coords);
    }

    public Point() {
        this(new int[2]);//new int[]{0, 0}
    }

    public Point(Point point) {
        this(point.getCoords());
    }

    public int[] getCoords() {

        int[] copy = new int[coords.length];
        for (int i = 0; i < copy.length; i++) {
            copy[i] = coords[i];
        }
        return copy;
    }

    public void setCoords(int[] coords) {
        if(coords != null && coords.length == 2){
            this.coords = new int[coords.length];
            for (int i = 0; i < coords.length; i++) {
                this.coords[i] = coords[i];
                //validation coords[i]
            }
        }
        else{
            this.coords = new int[2]; //(0, 0)
        }
    }

    public Point getPoint(){
        return new Point(this);
    }

    public void setPoint(Point point){
        if(point != null)
            setCoords(point.coords);
        else setCoords( new int[2]);
    }

    @Override
    public String toString() {
        return String.format("(%d; %d)",
                coords[0], coords[1]);
    }
}
