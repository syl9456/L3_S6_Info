package fr.dw2;

import java.util.Date;

public class Portion {

	private String nom;
	private String quantite;
	private String tags;
	private Date date;

	public Portion() {
		this.date = new Date();
	}
	
	public Portion(String nom, String quantite, String tags) {
		this(); // appeler le constructeur vide (ci-dessus)
		this.nom = nom;
		this.quantite = quantite;
		this.tags = tags;
	}

	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getQuantite() {
		return quantite;
	}
	public void setQuantite(String quantite) {
		this.quantite = quantite;
	}
	public String getTags() {
		return tags;
	}
	public void setTags(String tags) {
		this.tags = tags;
	}
	public Date getDate() {
		return date;
	}
	public void setDate(Date date) {
		this.date = date;
	}

	
}
