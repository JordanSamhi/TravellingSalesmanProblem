package InterpreteurForme;

import main.InterfaceGraphic;

/**
 * 
 * <b>Classe abstraite repr�sentant la chaine de responsabilit� 
 * pour d�terminer une couleur � partir d'une chaine de caracteres.
 * Elle h�rite de InterpreteurForme</b>
 * Les diff�rents "experts" heriterons de cette classe pour
 * d�terminer une forme � partir d'une chaine de caracteres.
 * 
 * suivant est Le maillon suivant dans la chaine de responsabilit�
 *
 */

public abstract class InterpreteurFormeCOR extends InterpreteurForme{
	private InterpreteurFormeCOR suivant;
	/**
	 * Cette m�thode "accroche" les diff�rents experts entre eux.
	 * 
	 * @param suiv
	 * L'expert de la chaine suivant
	 */
	
    public void setSuivant(InterpreteurFormeCOR suiv) {
        suivant = suiv;
    }
    /**
     * Cette m�thode essai d'interpr�ter indirectement la forme
     * � partir d'une chaine de caracteres en envoyant la chaine
     * � la m�thode suivant Dessiner1
     * @return bool�en
     * 		Retourne vrai si la forme a �t� trouv� et donc dessin�e,
     * 		Sinon faux.
     */
    
    public boolean dessiner(String forme, InterfaceGraphic objetAwt) {
        if(dessiner1(forme, objetAwt)){
        	return true;
        }
        else{
        	if(suivant != null){
        		return suivant.dessiner(forme, objetAwt);
        	}
        	else{
        		return false;
        	}
        }
    }
    /**
     * C'est la m�thode qui se charge d'interpr�ter 
     * (gr�ce � la m�thode dessiner2) les formes � partir d'une 
     * chaine de caracteres. 
     * @param forme
     * 		La chaine de caractere de la forme a interpr�ter
	 * @param objetAwt
	 * 		Notre objet permettant d'int�ragir avec la fen�tre
	 * 		du thread courant
     * @return bool�en
     * 		Retourne vrai si la forme a �t� trouv� et donc dessin�e,
     * 		Sinon faux si l'expert ne sait pas interpr�ter la forme.
     */
    
    public boolean dessiner1(String forme, InterfaceGraphic objetAwt)
    {
    	String typeForme = forme.split("#")[0];
    	if(!typeForme.equals(this.getType()))
    		return false;
    	else{
    		String infosForme = forme.split("#")[1];
    		dessiner2(infosForme, objetAwt);
    		return true;
    	}
    }
    /**
     * M�thode abstraite qui sera impl�ment�e
     * dans les classes qui h�riteront de celle-ci.
     * Elle ne retourne rien mais s'occupe de dessiner la forme
     * @param forme
     * 		La chaine de caractere de la forme � dessiner
     * @param objetAwt
     * 		Notre objet InterfaceGraphic
     */
    public abstract void dessiner2(String forme, InterfaceGraphic objetAwt);
    /**
     * M�thode pour avoir le type de forme
     * que l'expert sait r�soudre.
     * @return type que l'expert sait r�soudre.
     */
    public abstract String getType();
}
