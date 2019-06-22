package InterpreteurRequete;

import java.io.PrintStream;

import main.InterfaceGraphic;
import main.Utilitaire;

/**
 * 
 * Classe qui hérite de InterpreterRequeteCOR
 * sans constructeur, qui a pour seul but d'interpréter
 * une requete à partir d'une chaine de caracteres.
 * C'est un expert à part entiere.
 *
 */

public class InterpreteurRequeteCOROuvertureFenetre extends InterpreteurRequeteCOR {

	/**
	 * Méthode qui interprete une requete de type OUVERTURE_FENETRE.
	 * @param fenetre
	 * 		La chaine de caractere de la requete a interpréter
	 * @param objetAwt
	 * 		Notre objet InterfaceGraphic
	 * @param fluxSortant
	 * 		Notre Prinstream pour envoyer une réponse au client
	 * Pas de retour mais elle construit la fenetre.
	 */
	
	public void interpreterRequete2(String fenetre, InterfaceGraphic objetAwt, PrintStream fluxSortant){
		String[] donneesFenetre = fenetre.split(";");
		int cm = Utilitaire.getInstance().getCentimetre();
		int xMax = Integer.parseInt(donneesFenetre[1]);
		int yMax = Integer.parseInt(donneesFenetre[2]);
		xMax = xMax * cm;
		yMax = yMax * cm;
		objetAwt.creerFenetre(donneesFenetre[0], xMax, yMax);
		objetAwt.genererRepere(xMax,yMax);
		fluxSortant.print("1");
	}
	/**
     * Méthode pour avoir le type de requete
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici F pour fenetre.
     */
	public String getType(){
		return "F";
	}
}