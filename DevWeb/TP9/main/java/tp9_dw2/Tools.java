package tp9_dw2;

import java.util.Random;

public class Tools {

	/**
	 * Créer un objet json contenant uniquement des String. On pourrait aussi
	 * utiliser le JSR 374, plus adapté :
	 * https://javaee.github.io/jsonp/getting-started.html
	 * 
	 * Notons qu'il utilise le patron « Factory », "Json.createObjectBuilder()" (et
	 * ensuite le patron « builder »)
	 * 
	 * @param kvs liste ayant un nombre paires d'éléments, interprétés comme une
	 *            liste de clé, valeur
	 * @return une représentation texte en JSON
	 */
	public static String json(String... kvs) {
		String res = "{";
		for (int i = 0; i < kvs.length; i += 2) {
			if (i > 0)
				res += ",";
			String value = kvs[i + 1] == null ? "" : kvs[i + 1];
			res += "\"" + kvs[i] + "\": \"" + value.replace("\"", "\\\"") + "\"";
		}
		return res + "}";
	}

	/*
	 * Génère un mot au hasard. Il serait mieux de tirer un mot dans un
	 * dictionnaire.
	 */
	public static String getRandomWord() {
		Random r = new Random();
		final String letters = "abcdefghijklmnopqrstuvwxyz";
		String res = "";
		for (int i = 2 + r.nextInt(5); i > 0; i--) {
			res += letters.charAt(r.nextInt(letters.length()));
		}
		return res;
	}

}
