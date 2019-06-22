package InterpreteurForme;

import java.awt.Color;

import main.Utilitaire;
import main.InterfaceGraphic;

/**
 * 
 * Classe qui hérite de InterpreterFormeCOR
 * sans constructeur, qui a pour seul but d'interpréter
 * une forme à partir d'une chaine de caracteres.
 * C'est un expert à part entiere.
 *
 */

public class InterpreteurFormeCORCheminEulerien extends InterpreteurFormeCOR {

	/**
	 * Méthode qui interprete directement un chemin eulerien.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpréter
	 * Elle ne retourne rien elle dessiner le chemin eulerien.
	 */
	
	public void dessiner2(String forme, InterfaceGraphic objetAwt){
		//donnesPolygone contient [couleur,point1,point2,point3,......,pointn]
		int cm = Utilitaire.getInstance().getCentimetre();		
		String[] donneesPolygone = forme.split(";");
		String couleurNonInterpretee = donneesPolygone[0];
		Color couleur = Utilitaire.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		int taille = donneesPolygone.length -1;
		int[] x = new int[taille];
		int[] y = new int[taille];
		double xTemp;
		double yTemp;
		for(int i = 1; i< donneesPolygone.length; i++){
			xTemp =Double.parseDouble(donneesPolygone[i].replace("(","").replace(")", "").split(",")[0]);
			yTemp = Double.parseDouble(donneesPolygone[i].replace("(","").replace(")", "").split(",")[1]);
			xTemp = (int)Math.round(xTemp);
			yTemp = (int)Math.round(yTemp);
			x[i-1] = (int) (xTemp * cm + objetAwt.getFrame().getWidth()/2);
			y[i-1] = (int) (yTemp * cm + objetAwt.getFrame().getHeight()/2 - 2* yTemp * cm);
		}
		objetAwt.dessinerPolygone(x,y, taille, couleur);
	}
	/**
     * Méthode pour avoir le type de forme
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici chemin eulerien.
     */
	public String getType(){
		return "CheminEulerien";
	}
}
