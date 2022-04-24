package projetDW2;

import java.util.Objects;

public class Acces {
	
	private int UtilID;
	private int MapID;
	private int Droit;
	
	public Acces(int UtilID, int MapID, int Droit) {
        this.UtilID = UtilID;
        this.MapID = MapID;
        this.Droit = Droit;
    }
	
	public Acces() {
		super();
	}

	public int getUtilID() {
		return UtilID;
	}

	public void setUtilID(int utilID) {
		UtilID = utilID;
	}

	public int getMapID() {
		return MapID;
	}

	public void setMapID(int mapID) {
		MapID = mapID;
	}

	public int getDroit() {
		return Droit;
	}

	public void setDroit(int droit) {
		Droit = droit;
	}

	@Override
	public String toString() {
		return "Acces[UtilID=" + UtilID + ", MapID=" + MapID + ", Droit=" + Droit + "]";
	}
	
	@Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Acces that = (Acces) o;
        return Objects.equals(UtilID, that.UtilID) && Objects.equals(MapID, that.MapID) && Objects.equals(Droit, that.Droit);
    }
	
	

    

}
