package projetDW2;

import java.util.Objects;

/**
 * Class pour stocker un Acces
 */

public class Acces {
	
	private int UtilID;
	private int MapID;
	private int Droit;
	
	/**
	 * @param UtilID
	 * @param MapID
	 * @param Droit
	 */
	public Acces(int UtilID, int MapID, int Droit) {
        this.UtilID = UtilID;
        this.MapID = MapID;
        this.Droit = Droit;
    }
	
	/**
	 * 
	 */
	public Acces() {
		super();
	}

	/**
	 * @return
	 */
	public int getUtilID() {
		return UtilID;
	}

	/**
	 * @param utilID
	 */
	public void setUtilID(int utilID) {
		UtilID = utilID;
	}

	/**
	 * @return
	 */
	public int getMapID() {
		return MapID;
	}

	/**
	 * @param mapID
	 */
	public void setMapID(int mapID) {
		MapID = mapID;
	}

	/**
	 * @return
	 */
	public int getDroit() {
		return Droit;
	}

	/**
	 * @param droit
	 */
	public void setDroit(int droit) {
		Droit = droit;
	}

	/**
	 *
	 */
	@Override
	public String toString() {
		return "Acces[UtilID=" + UtilID + ", MapID=" + MapID + ", Droit=" + Droit + "]";
	}
	
	/**
	 *
	 */
	@Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Acces that = (Acces) o;
        return Objects.equals(UtilID, that.UtilID) && Objects.equals(MapID, that.MapID) && Objects.equals(Droit, that.Droit);
    }
	
	

    

}
