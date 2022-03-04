package tp3;

import java.sql.SQLException;

public class Test {

	public static void main(String[] args) throws SQLException {
		
		int choixTypeReq = -1;
		int choixReq = -1;
		String requete = "";
		
		/* Test nb arguments */
		if(args.length < 1) {
			System.out.println("Usage : java -jar Test [reqInterr OU reqManip OU reqLibre OU reqRandom OU reqAge] [1-5 OU si reqLibre votre requete]");
			System.exit(0);
		}
		
		/* Test arguments type de requete */
		if(!(args[0].equals("reqInterr")) && !(args[0].equals("reqManip")) && !(args[0].equals("reqLibre")) && !(args[0].equals("reqRandom")) && !(args[0].equals("reqAge"))){
			System.out.println(args[0]);
			System.out.println("Usage : java -jar Test [reqInterr OU reqManip OU reqLibre OU reqRandom OU reqAge] [1-5 OU si reqLibre votre requete]");
			System.exit(0);
		}
		
		/* reqInterr */
		if(args[0].equals("reqInterr")) { 
			if(Integer.parseInt(args[1]) < 0 || Integer.parseInt(args[1]) > 5) {
				System.out.println("Usage : java -jar Test [reqInterr OU reqManip OU reqLibre OU reqRandom OU reqAge] [1-5 OU si reqLibre votre requete]");
				System.exit(0);
			}
			else {
				choixReq = Integer.parseInt(args[1]);
				Connect maConnexion = new Connect();
				maConnexion.execReqIntero(choixReq);
			}		
		}
		else if(args[0].equals("reqManip")) { /* reqManip */
			if(Integer.parseInt(args[1]) < 0 || Integer.parseInt(args[1]) > 5) {
				System.out.println("Usage : java -jar Test [reqInterr OU reqManip OU reqLibre OU reqRandom OU reqAge] [1-5 OU si reqLibre votre requete]");
				System.exit(0);
			}
			else {
				choixReq = Integer.parseInt(args[1]);
				Connect maConnexion = new Connect();
				maConnexion.execReqManip(choixReq);
			}		
		}
		else if(args[0].equals("reqManip")){ /* reqLibre */
			if(!(args[1].equals("SELECT")) && !(args[1].equals("UPDATE")) && !(args[1].equals("INSERT")) && !(args[1].equals("DELETE"))) {
				System.out.println("Erreur : Vous ne pouvez utiliser que INSERT / UPDATE / DELETE et SELECT");
				System.exit(0);
			}
			else if(args[1].equals("SELECT")){
				choixTypeReq = 1;
			}
			else {
				choixTypeReq = 2;
			}
			
			for(int i = 1; i < args.length-1; i++) {
				requete += args[i] + " ";
			}
			requete += args[args.length-1];
			
			Connect maConnexion = new Connect();
			
			System.out.println("On éxécute la requête : [" + requete + "]");
			
			switch(choixTypeReq){
				case 1: /* SELECT */
					maConnexion.reqSQL(requete, 's');
					break;
				case 2: /* INSERT / UPDATE / DELETE */
					maConnexion.reqSQL(requete, 'm');
				break;
			}
			maConnexion.close();
		}
		else if(args[0].equals("reqRandom")){ /* reqRandom */
			Connect maConnexion = new Connect();
			System.out.println("On créer 10 000 utilisateurs de façon random, ça prend quelques secondes...");
			maConnexion.inscriptionRandom();
			maConnexion.close();
		}
		else { /* reqAge */
			int idUtil = 0;
			if(args.length != 2) {
				System.out.println("Usage : java -jar Test [reqInterr OU reqManip OU reqLibre OU reqRandom OU reqAge] [1-5 OU si reqLibre votre requete]");
				System.exit(0);
			}
			else {
				idUtil = Integer.parseInt(args[1]);
			}
			Connect maConnexion = new Connect();
			System.out.println("Calcule de l'age de l'utilisateur n°" + idUtil + "");
			System.out.println("il a [" + maConnexion.getAge(idUtil) + "] ans");
			maConnexion.close();
		}
	}

}
