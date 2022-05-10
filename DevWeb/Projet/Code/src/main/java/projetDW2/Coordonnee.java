package projetDW2;

/**
 * Class pour stocker une Coordonnee
 */

public class Coordonnee {

    private int X;
    private int Y;

    /**
     * @param x
     * @param y
     */
    public Coordonnee(int x, int y) {
        X = x;
        Y = y;
    }

    /**
     * @return
     */
    public int getX() {
        return X;
    }

    /**
     * @param x
     */
    public void setX(int x) {
        X = x;
    }

    /**
     * @return
     */
    public int getY() {
        return Y;
    }

    /**
     * @param y
     */
    public void setY(int y) {
        Y = y;
    }

    /**
     * @param o
     * @return Test si une coordonnee est la meme qu'une autre
     */
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Coordonnee that = (Coordonnee) o;
        return X == that.X && Y == that.Y;
    }

    /**
     * @return Info de la classe Coordonnee
     */
    @Override
    public String toString() {
        return "Coordonnee{" +
                "X=" + X +
                ", Y=" + Y +
                '}';
    }
}
