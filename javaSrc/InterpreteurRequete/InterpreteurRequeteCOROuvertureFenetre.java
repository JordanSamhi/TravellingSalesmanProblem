package InterpreteurRequete;

import java.io.PrintStream;

import main.InterfaceGraphic;
import main.Utilitaire;

/**
 * 
 * Classe qui h�rite de InterpreterRequeteCOR
 * sans constructeur, qui a pour seul but d'interpr�ter
 * une requete � partir d'une chaine de caracteres.
 * C'est un expert � part entiere.
 *
 */

public class InterpreteurRequeteCOROuvertureFenetre extends InterpreteurRequeteCOR {

	/**
	 * M�thode qui interprete une requete de type OUVERTURE_FENETRE.
	 * @param fenetre
	 * 		La chaine de caractere de la requete a interpr�ter
	 * @param objetAwt
	 * 		Notre objet InterfaceGraphic
	 * @param fluxSortant
	 * 		Notre Prinstream pour envoyer une r�ponse au client
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
     * M�thode pour avoir le type de requete
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici F pour fenetre.
     */
	public String getType(){
		return "F";
	}
}