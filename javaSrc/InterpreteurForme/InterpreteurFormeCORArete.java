package InterpreteurForme;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;

import javax.swing.JLabel;
import javax.swing.JPanel;

import main.Utilitaire;
import main.InterfaceGraphic;

/**
 * 
 * Classe qui h�rite de InterpreterFormeCOR
 * sans constructeur, qui a pour seul but d'interpr�ter
 * une forme � partir d'une chaine de caracteres.
 * C'est un expert � part entiere.
 *
 */

public class InterpreteurFormeCORArete extends InterpreteurFormeCOR {

	/**
	 * M�thode qui interprete directement une arete.
	 * @param forme
	 * 		La chaine de caractere de la couleur a interpr�ter
	 * Elle ne retourne rien elle dessiner l'arete avec ces infos.
	 */
	public void dessiner2(String forme, InterfaceGraphic objetAwt){
		int cm = Utilitaire.getInstance().getCentimetre();
		String couleurNonInterpretee = forme.split(";")[0];
		Color couleur = Utilitaire.getInstance().getInterpreteurCouleur().interpreterCouleur(couleurNonInterpretee);
		String pointA = forme.split(";")[1].replace("(","").replace(")", "");
		String pointB = forme.split(";")[2].replace("(","").replace(")", "");
		double pointAxDouble = Double.parseDouble(pointA.split(",")[0]);
		double pointAyDouble = Double.parseDouble(pointA.split(",")[1]);
		double pointBxDouble = Double.parseDouble(pointB.split(",")[0]);
		double pointByDouble = Double.parseDouble(pointB.split(",")[1]);
		int pointAx = (int) Math.round(pointAxDouble*cm + objetAwt.getFrame().getWidth()/2);
		int pointAy = (int) Math.round(pointAyDouble*cm + (objetAwt.getFrame().getHeight()/2-pointAyDouble*cm) - pointAyDouble*cm);
		int pointBx = (int) Math.round(pointBxDouble*cm + objetAwt.getFrame().getWidth()/2);
		int pointBy = (int) Math.round(pointByDouble*cm + (objetAwt.getFrame().getHeight()/2-pointByDouble*cm) - pointByDouble*cm);
		objetAwt.dessinerSegment(pointAx,pointAy,pointBx,pointBy,couleur);
		
		dessinerInfoAreteCarte(objetAwt,  forme.split(";")[3] , (pointAx + pointBx)/2-50, (pointAy + pointBy)/2-50);
	}

	/**
	 * M�thode qui dessine les informations d'une arete
	 * @param info
	 * 		la chaine de caractere des informations et ces coordonn�es
	 * @param x
	 * 		Coordonn�es x des infos 
	 * @param y
	 * Coordonn�es y des infos
	 * @param objetAwt
	 * 		L'objet AWT pour dessiner
	 */
	public void dessinerInfoAreteCarte(InterfaceGraphic objetAwt, String info, int x, int y){
		JPanel panel = new JPanel();
		panel.setLayout(new FlowLayout()); 
		JLabel label = new JLabel(info);
		panel.add(label);
		panel.setSize(new Dimension(50,25));
		panel.setLocation(x, y  );		
		objetAwt.getFrame().setContentPane(panel);
	}
	
	/**
     * M�thode pour avoir le type de forme
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     * 		ici Arete.
     */
	public String getType(){
		return "Arete";
	}
}