#include "VisiteurDessinGrapheCarte.h"
#include "Outils.h"

void VisiteurDessinGrapheCarte::visite(const Graphe<InfoAreteCarte,InfoSommetCarte> * g) const{
	try{
		SingletonConnexion::getInstance()->initialiserConnexion();
		SingletonConnexion::getInstance()->envoyerRequete(Outils::constructionRequeteOuvertureFenetre());
		cout << "Requete ouverture de fenetre envoyee" << endl; 
		cout << "Attente de la reponse du serveur..." << endl;
		/*Attendre de la reponse du serveur pour savoir s'il a ouvert la fenetre
		avant d'envoyer les donnees pour dessiner*/
		if(SingletonConnexion::getInstance()->serveurATraiterRequete()){
			cout << "Le serveur a traite la requete : la fenetre a ete ouverte" << endl;
			//gerer les deux listes
			PElement<Sommet<InfoSommetCarte>> * r1;
			PElement<Arete<InfoAreteCarte,InfoSommetCarte>> * r2;
			for(r1 = g->lSommets; r1 != NULL; r1 = r1->s){
				SingletonConnexion::getInstance()->envoyerRequete("D$"+r1->v->constructionRequeteDessin("black"));
				/*Attendre de la reponse du serveur pour savoir s'il a dessiner
				avant de fermer la connexion*/
				if(SingletonConnexion::getInstance()->serveurATraiterRequete())
					cout << "Le serveur a traite la requete : le sommet a ete dessine" << endl;
				else{
					cout << "Le serveur n'a pas dessiner la forme" << endl;
					cout << "Car il ne l'a pas reconnue" << endl;
				}
			}
			for(r2 = g->lAretes; r2 != NULL; r2 = r2->s){
				if(r2->v->cout() != COUT_MAXIMAL)
				{
					SingletonConnexion::getInstance()->envoyerRequete("D$"+r2->v->constructionRequeteDessin("black"));
					/*Attendre de la reponse du serveur pour savoir s'il a dessiner
					avant de fermer la connexion*/
					if(SingletonConnexion::getInstance()->serveurATraiterRequete())
						cout << "Le serveur a traite la requete : l'arete a ete dessinee" << endl;
					else{
						cout << "Le serveur n'a pas dessiner la forme" << endl;
						cout << "Car il ne l'a pas reconnue" << endl;
					}
				}
			}
		}
		else
			cout << "Le serveur n'a pas ouvert la fenetre" << endl;
		/*SingletonConnexion::getInstance()->fermerConnexion();
		SingletonConnexion::getInstance()->killInstance();*/
	}
	catch(Erreur erreur){
		cerr << erreur << endl;
	}
}