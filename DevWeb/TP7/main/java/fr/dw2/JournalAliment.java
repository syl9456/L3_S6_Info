package fr.dw2;
import java.util.ArrayList;

public class JournalAliment {
	
	private String Nom;
	private static ArrayList<Portion> listePortion;
	
	public JournalAliment() {
		this.listePortion = new ArrayList<Portion>();
	}
	
	public JournalAliment(String nom) {
		this.listePortion = new ArrayList<Portion>();
		this.Nom = nom;
	}
	
	public ArrayList<Portion> getListePortion() {
		return listePortion;
	}
	public void setListePortion(ArrayList<Portion> listePortion) {
		this.listePortion = listePortion;
	}
	public String getNom() {
		return Nom;
	}
	public void setNom(String nom) {
		Nom = nom;
	}

}
