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
 * de centraliser les différentes chaînes de
 * responsabilité pour éviter de les déclarer
 * ailleurs dans le code.
 * Elle est développé en tant que singleton
 *
 */
public class Utilitaire {
	/**
	 * instance unique de la classe COR
	 */
	private static Utilitaire instance = null;
	/**
	 * "Entrée" de la chaine de responsabilité
	 * pour interpréter une requête
	 */
	private InterpreteurRequete interpreteurRequete;
	/**
	 * "Entrée" de la chaine de responsabilité
	 * pour interpréter une forme
	 */
	private InterpreteurForme interpreteurForme;
	/**
	 * "Entrée" de la chaine de responsabilité
	 * pour interpréter une couleur
	 */
	private InterpreteurCouleur interpreteCouleur;
	/**
	 * Constructeur de la classe COR
	 * Assemblage et construction des chaines
	 * de responsabilité
	 */
	private Utilitaire(){
		//construction de la chaine de responsabilité pour interpreter une requete
		InterpreteurRequeteCOR interpreteurRequeteDessiner, interpreteurRequeteOuvertureFenetre;
		interpreteurRequeteDessiner = new InterpreteurRequeteCORDessinerForme();
		interpreteurRequeteOuvertureFenetre = new InterpreteurRequeteCOROuvertureFenetre();
		//Assemblage des maillons
		interpreteurRequeteDessiner.setSuivant(interpreteurRequeteOuvertureFenetre);
		interpreteurRequete = interpreteurRequeteDessiner;
		
		//construction de la chaine de responsabilité pour interpreter forme
		InterpreteurFormeCOR dessinateurSommet, dessinateurArete, dessinateurChemineulerien;
		dessinateurSommet = new InterpreteurFormeCORSommet();
		dessinateurArete = new InterpreteurFormeCORArete();
		dessinateurChemineulerien = new InterpreteurFormeCORCheminEulerien();
		//assemblage des maillons
		dessinateurSommet.setSuivant(dessinateurArete);
		dessinateurChemineulerien.setSuivant(dessinateurSommet);
		interpreteurForme = dessinateurChemineulerien;
		
		//construction de la chaine de responsabilité pour interpreter une couleur
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
	 * Méthode qui récupère l'instance unique
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
	 * Méthode qui récupère "l'entrée" de la chaine de
	 * responsabilité pour interpréter une couleur
	 * @return "l'interpréteur de couleur"
	 */
	public InterpreteurCouleur getInterpreteurCouleur(){
		return interpreteCouleur;
	}
	/**
	 * Méthode qui récupère "l'entrée" de la chaine de
	 * responsabilité pour interpréter une requête
	 * @return "l'interpréteur de requête"
	 */
	public InterpreteurRequete getInterpreteurRequete(){
		return interpreteurRequete;
	}
	/**
	 * Méthode qui récupère "l'entrée" de la chaine de
	 * responsabilité pour interpréter une forme
	 * @return "l'interpréteur de forme"
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
