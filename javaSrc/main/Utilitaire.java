package main;

import java.awt.Toolkit;

import InterpreteurCouleur.InterpreteurCouleur;
import InterpreteurCouleur.InterpreteurCouleurCOR;
import InterpreteurCouleur.InterpreteurCouleurCORBlack;
import InterpreteurCouleur.InterpreteurCouleurCORBlue;
import InterpreteurCouleur.InterpreteurCouleurCORCyan;
import InterpreteurCouleur.InterpreteurCouleurCORGreen;
import InterpreteurCouleur.InterpreteurCouleurCORRed;
import InterpreteurCouleur.InterpreteurCouleurCORYellow;
import InterpreteurForme.InterpreteurForme;
import InterpreteurForme.InterpreteurFormeCOR;
import InterpreteurForme.InterpreteurFormeCORArete;
import InterpreteurForme.InterpreteurFormeCORCheminEulerien;
import InterpreteurForme.InterpreteurFormeCORSommet;
import InterpreteurRequete.InterpreteurRequete;
import InterpreteurRequete.InterpreteurRequeteCOR;
import InterpreteurRequete.InterpreteurRequeteCORDessinerForme;
import InterpreteurRequete.InterpreteurRequeteCOROuvertureFenetre;

/**
 * 
 * Classe utilitaire COR qui nous permet
 * de centraliser les diff�rentes cha�nes de
 * responsabilit� pour �viter de les d�clarer
 * ailleurs dans le code.
 * Elle est d�velopp� en tant que singleton
 *
 */
public class Utilitaire {
	/**
	 * instance unique de la classe COR
	 */
	private static Utilitaire instance = null;
	/**
	 * "Entr�e" de la chaine de responsabilit�
	 * pour interpr�ter une requ�te
	 */
	private InterpreteurRequete interpreteurRequete;
	/**
	 * "Entr�e" de la chaine de responsabilit�
	 * pour interpr�ter une forme
	 */
	private InterpreteurForme interpreteurForme;
	/**
	 * "Entr�e" de la chaine de responsabilit�
	 * pour interpr�ter une couleur
	 */
	private InterpreteurCouleur interpreteCouleur;
	/**
	 * Constructeur de la classe COR
	 * Assemblage et construction des chaines
	 * de responsabilit�
	 */
	private Utilitaire(){
		//construction de la chaine de responsabilit� pour interpreter une requete
		InterpreteurRequeteCOR interpreteurRequeteDessiner, interpreteurRequeteOuvertureFenetre;
		interpreteurRequeteDessiner = new InterpreteurRequeteCORDessinerForme();
		interpreteurRequeteOuvertureFenetre = new InterpreteurRequeteCOROuvertureFenetre();
		//Assemblage des maillons
		interpreteurRequeteDessiner.setSuivant(interpreteurRequeteOuvertureFenetre);
		interpreteurRequete = interpreteurRequeteDessiner;
		
		//construction de la chaine de responsabilit� pour interpreter forme
		InterpreteurFormeCOR dessinateurSommet, dessinateurArete, dessinateurChemineulerien;
		dessinateurSommet = new InterpreteurFormeCORSommet();
		dessinateurArete = new InterpreteurFormeCORArete();
		dessinateurChemineulerien = new InterpreteurFormeCORCheminEulerien();
		//assemblage des maillons
		dessinateurSommet.setSuivant(dessinateurArete);
		dessinateurChemineulerien.setSuivant(dessinateurSommet);
		interpreteurForme = dessinateurChemineulerien;
		
		//construction de la chaine de responsabilit� pour interpreter une couleur
		InterpreteurCouleurCOR black, blue, cyan, green, red, yellow;
		black = new InterpreteurCouleurCORBlack();
		blue = new InterpreteurCouleurCORBlue();
		cyan = new InterpreteurCouleurCORCyan();
		green = new InterpreteurCouleurCORGreen();
		red = new InterpreteurCouleurCORRed();
		yellow = new InterpreteurCouleurCORYellow();
		//assemblage des maillons
		blue.setSuivant(black);
		cyan.setSuivant(blue);
		green.setSuivant(cyan);
		red.setSuivant(green);
		yellow.setSuivant(red);
		interpreteCouleur = yellow;
	}
	/**
	 * M�thode qui r�cup�re l'instance unique
	 * de la classe COR
	 * @return L'instance unique de la classe COR
	 */
	public static Utilitaire getInstance()
	{	
		if(instance == null)
			instance = new Utilitaire();
		return instance;
	}
	/**
	 * M�thode qui r�cup�re "l'entr�e" de la chaine de
	 * responsabilit� pour interpr�ter une couleur
	 * @return "l'interpr�teur de couleur"
	 */
	public InterpreteurCouleur getInterpreteurCouleur(){
		return interpreteCouleur;
	}
	/**
	 * M�thode qui r�cup�re "l'entr�e" de la chaine de
	 * responsabilit� pour interpr�ter une requ�te
	 * @return "l'interpr�teur de requ�te"
	 */
	public InterpreteurRequete getInterpreteurRequete(){
		return interpreteurRequete;
	}
	/**
	 * M�thode qui r�cup�re "l'entr�e" de la chaine de
	 * responsabilit� pour interpr�ter une forme
	 * @return "l'interpr�teur de forme"
	 */
	public InterpreteurForme getInterpreteurForme(){
		return interpreteurForme;
	}
	public int getCentimetre() {
		double screenDpi = Toolkit.getDefaultToolkit().getScreenResolution();
		int cm = (int) Math.round(screenDpi/2.54);
		return cm;
	}
}