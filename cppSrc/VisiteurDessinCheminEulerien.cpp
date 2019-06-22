#include "VisiteurDessinCheminEulerien.h"
#include "Outils.h"

void VisiteurDessinCheminEulerien::visite(const CheminEulerien<InfoAreteCarte,InfoSommetCarte> & cE, const string & c) const{
	try{
		SingletonConnexion::getInstance()->envoyerRequete("D$CheminEulerien#"+c+";"+cE.getPoints());
	}
	catch(Erreur erreur){
		cerr << erreur << endl;
	}
}