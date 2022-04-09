package projetDW2;

import java.util.Objects;

public class Coordonnee {

    private int X;
    private int Y;

    public Coordonnee(int x, int y) {
        X = x;
        Y = y;
    }

    public int getX() {
        return X;
    }

    public void setX(int x) {
        X = x;
    }

    public int getY() {
        return Y;
    }

    public void setY(int y) {
        Y = y;
    }

    /**
     * @param o
     * @return Test si une coordonnée est la même qu'une autre
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
