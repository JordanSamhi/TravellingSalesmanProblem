package InterpreteurForme;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;

import main.InterfaceGraphic;
import main.Utilitaire;

/**
 * 
 * Classe qui hérite de InterpreterFormeCOR
 * sans constructeur, qui a pour seul but d'interpréter
 * une forme à partir d'une chaine de caracteres.
 * C'est un expert à part entiere.
 *
 */

public class InterpreteurFormeCORSommet extends InterpreteurFormeCOR {

	/**
	 * Méthode qui interprete directement un cercle.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpréter
	 * Elle ne retourne rien elle dessiner le sommet avec ces informations.
	 */
	public void dessiner2(String forme, InterfaceGraphic objetAwt){
		int cm = Utilitaire.getInstance().getCentimetre();
		String couleurNonInterpretee = forme.split(";")[0];
		Color couleur = Utilitaire.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		String[] attributsForme = forme.split(";");
		double rayonDouble = Double.parseDouble(attributsForme[3]);
		int rayon = (int) Math.round(rayonDouble*cm);
		rayon *= 2;
		String centre = attributsForme[1].replace("(","").replace(")", "");
		double xCentreDouble = Double.parseDouble(centre.split(",")[0]);
		double yCentreDouble = Double.parseDouble(centre.split(",")[1]);
		int xCentre = (int) Math.round(xCentreDouble);
		int yCentre = (int) Math.round(yCentreDouble);
		xCentre = (xCentre * cm - rayon/2) + objetAwt.getFrame().getWidth()/2;
		yCentre = (yCentre * cm - rayon/2) + (objetAwt.getFrame().getHeight()/2 - 2*(yCentre * cm));
		objetAwt.dessinerCercle(xCentre, yCentre, rayon, couleur);
		dessinerInfoSommetCarte(objetAwt,attributsForme[2] + " (" + centre + ")", xCentre - 50 , yCentre - 50);
		
	}
	
	/**
	 * Méthode qui dessine les informations d'un sommet
	 * @param info
	 * 		la chaine de caractere des informations et ces coordonnées
	 * @param x
	 * 		Coordonnées x des infos 
	 * @param y
	 * 		Coordonnées y des infos
	 * @param objetAwt
	 * 		L'objet AWT pour dessiner
	 */
	public void dessinerInfoSommetCarte(InterfaceGraphic objetAwt, String info, int x, int y){
		JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout());	 
		JLabel label = new JLabel(info); 
		panel.add(label);
		panel.setSize(new Dimension(100,25));
		panel.setLocation(x, y  );		
		objetAwt.getFrame().setContentPane(panel);
	}
	

	/**
     * Méthode pour avoir le type de forme
     * que l'expert sait résoudre.
     * @return type que l'expert sait résoudre.
     * 		ici sommet.
     */
	public String getType(){
		return "Sommet";
	}
}