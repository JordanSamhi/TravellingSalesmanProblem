/**
* \file ChemeinEulerien.h
* \brief Classe générique : Chemein eulérien composé de sommets.
*/
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "PElement.h"
#include "Sommet.h"
#include "Arete.h"
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "VisiteurCheminEulerien.h"
#include "Outils.h"

using namespace std;

template <typename S, typename T>
class CheminEulerien{
public:
	
	PElement<Sommet<T>> * chemin;	/*! \a Liste de sommets.*/
	PElement<Arete<S,T>> * aretesChemin;	/*! \a Liste des aretes.*/
	int prochainecle;	/*! \a Prochaine Clé.*/
	
	/**
	* \ brief Constructeur par défaut.
	*/
	CheminEulerien():chemin(NULL),aretesChemin(NULL),prochainecle(0){}


	/**
	* \ brief Construction d'un chemin a partir d'un graphe. 
	* \param  g.
	*/
	CheminEulerien(Graphe<S,T> * g):chemin(NULL),aretesChemin(NULL),prochainecle(0){
		g = Outils::rendreGrapheComplet(g, InfoAreteCarte(COUT_MAXIMAL));
		// d : distance entre deux points
		PElement<Sommet<T>> * ptrSommetTmp = NULL;
		/*on parcours les sommet du graphe g et on construit
		notre liste de sommet a partir de celle-ci
		*/
		for(ptrSommetTmp = g->lSommets ; ptrSommetTmp != NULL ; ptrSommetTmp = ptrSommetTmp->s)
			chemin = new PElement<Sommet<T>>(ptrSommetTmp->v,chemin);
		/*On ajoute en fin de liste le premier element de la liste
		Afin d'avoir un circuit du type : S0 -> S1 -> S2 -> S0
		*/
		chemin = new PElement<Sommet<T>>(g->lSommets->v,chemin);

		//ARETES
		PElement<Arete<S,T>> * ptrAretestmp = NULL;
		for(ptrAretestmp = g->lAretes ; ptrAretestmp != NULL ; ptrAretestmp = ptrAretestmp->s)
			aretesChemin = new PElement<Arete<S,T>>(ptrAretestmp->v,aretesChemin);
		do{
			*this = melangeAleatoireCheminEulerien(*this);
		}while(this->contientAreteCoutMax());
	}

	/**
	* \ brief Operateur de conversion CheminEilerien ===> string.
	* \details convertit le chemin en une chaine de caractères.
	*/
	operator string() const{
		ostringstream oss;
		PElement<Sommet<T>> * ptrSommetTmp = NULL;
		oss << "Chemin Eulerien [";
		for(ptrSommetTmp = chemin ; ptrSommetTmp != NULL ; ptrSommetTmp = ptrSommetTmp->s){
			oss << ptrSommetTmp->v->v.nom;
			if(ptrSommetTmp->s != NULL)
				oss << " ==> ";
		}
		oss << "]" << endl;
		oss << "Sommets : "<< endl << PElement<Sommet<T>>::toString(chemin,"","\n","") << endl;
		return oss.str();
	}
	/**
	* \brief melange aleatoire d'un chemin
	* \details 
	*	1 - Cette méthode renseigne un vecteur de sommet * avec les sommet d'un chemin
	*	sauf le premier et le dernier qui n'ont pas besoin de varier
	*	par exemple pour le chemin : S0 -> S1 -> S2 -> S3 -> S0, on fera seulement
	*	varier S1, S2, S3 de position. (car le chemin reste le même)
	*	2 - On créé un Chemin en l'accrochant tout de suite au premier (S0 pour l'exemple)
	*	On tire un nombre aleatoire entre la postion de S1 et de S3, si on retombe sur
	*	le meme nombre on retire. Ensuite on va chercher à la position de l'indice aleatoire
	*	dans le vecteur le sommet qui correspond et on "l'accroche" a notre liste et ainsi de suite
	*	3 - On accroche le dernier element de notre liste qui fait reference au premier (S0)
	*	4 - On renseigne nos aretes du chemin a partir des sommets du nouveau chemin
	*	5 - On retourne le chemin avec les sommets mélangés
	*	\param c
	*	\return ChemeinEulerien<S, T> le chemin construit en mélangeant aléatoirement c.
	*/
	static CheminEulerien<S,T> melangeAleatoireCheminEulerien(const CheminEulerien<S,T> & c){
		CheminEulerien<S,T> cE;
		do{
			cE = CheminEulerien();
			int nombreSommets = PElement<Sommet<T>>::taille(c.chemin);
			int random;
			vector<int> tableauNombresAleatoiresDejaFaits;
			vector<Sommet<InfoSommetCarte> *>tableauSommetsTmp;
			PElement<Sommet<T>> * cheminTmp = c.chemin;
			PElement<Sommet<T>> * ptrCheminTmp = cheminTmp;
			for(cheminTmp = cheminTmp->s ; cheminTmp->s != NULL ; cheminTmp = cheminTmp->s)
				tableauSommetsTmp.push_back(cheminTmp->v);
			cheminTmp = NULL;
			cheminTmp = new PElement<Sommet<T>>(ptrCheminTmp->v,cheminTmp);
			for(int i = 0 ; i < nombreSommets - 2 ; i++){
				do{
					random = Outils::nombreAleatoirede0aX(nombreSommets-3);
				}while(Outils::nombreAleatoireDejaUtilise(random,tableauNombresAleatoiresDejaFaits));
				cheminTmp = new PElement<Sommet<T>>(tableauSommetsTmp[random],cheminTmp);
				tableauNombresAleatoiresDejaFaits.push_back(random);
			}
			cheminTmp = new PElement<Sommet<T>>(ptrCheminTmp->v,cheminTmp);
			cE.chemin = cheminTmp;

			PElement<Arete<S,T>> * ptrAretestmp = NULL;
			for(ptrAretestmp = c.aretesChemin ; ptrAretestmp != NULL ; ptrAretestmp = ptrAretestmp->s)
				cE.aretesChemin = new PElement<Arete<S,T>>(ptrAretestmp->v,cE.aretesChemin);
		}while(cE.contientAreteCoutMax());
		return cE;
	}
	/**
	* \ brief Calcul du cout du chemin.
	* \param c.
	* \return \e double le coût calculé.
	*/
	static double coutChemin(const CheminEulerien<S,T> & c){
		double total = 0;
		PElement<Sommet<T>> * ptrCheminTmp = NULL;
		PElement<Arete<S,T>> * ptrAretesChemin = NULL;
		for(ptrCheminTmp = c.chemin; ptrCheminTmp->s != NULL ; ptrCheminTmp = ptrCheminTmp->s){
			for(ptrAretesChemin = c.aretesChemin ; ptrAretesChemin != NULL ; ptrAretesChemin = ptrAretesChemin->s){
				if(ptrAretesChemin->v->estEgal(ptrCheminTmp->v,ptrCheminTmp->s->v))
					total += ptrAretesChemin->v->cout();
			}
		}
		return total;
	}

	/**
	* \brief Retourne un string contenant les points sous cette forme : (x1,y1);(x2,y2);.....;(xn,yn)
	* \details Cela est utile pour construire les requetes de dessin de chemin
	* \return la chaine de caractères construite.
	*/
	const string getPoints() const{
		PElement<Sommet<T>> * p;
		string points = "";
		for(p = this->chemin; p != NULL; p = p->s){
			points.append(p->v->v.position);
			if(p->s != NULL)
				points.append(";");
		}
		return points;
	}

	/**
	* \brief Vérifie si le chemin eulerien contient au moins une arete de cout maximal.
	* \return true si oui, false sinon.
	*/
	const bool contientAreteCoutMax() const{
		PElement<Sommet<T>> * ptrSommetTmp = NULL;
		Arete<S,T> * areteTmp = NULL;
		for(ptrSommetTmp = this->chemin ; ptrSommetTmp->s != NULL ; ptrSommetTmp = ptrSommetTmp->s){
			areteTmp = this->getAreteParSommets(ptrSommetTmp->v, ptrSommetTmp->s->v);
			if(areteTmp->cout() == COUT_MAXIMAL)
				return true;
		}
		return false;
	}

	/**
	* \brief Renvoie l'arete décrite par les deux sommets passés en paramètre.
	* \param s1, s2.
	* \return Arete<S,T> l'arete trouvée, et NULL sinon.
	*/
	Arete<S,T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const{
		PElement<Arete<S,T> > * l;
		for (l = this->aretesChemin; l != NULL; l = l->s)
			if (l->v->estEgal(s1,s2))
			   return l->v;
		return NULL;
	}


	/**
	* \ brief Acceptaion d'un VisiteurCheminEulerien, c fait reference à la couleur.
	* \param  * visiteur, cE, c 
	*/
	static void accepter(const VisiteurCheminEulerien<S,T> * visiteur, const CheminEulerien<S,T> & cE, const string & c){
		visiteur->visite(cE, c);
	}


	/**
	* \ brief dessine le chemin.
	* \details  c fait reference à la couleur.
	* \param cE, c.
	*/
	static void dessiner(const CheminEulerien<S,T> & cE, const string & c){
		CheminEulerien<S,T>::accepter(new VisiteurDessinCheminEulerien, cE, c);
	}

	
};

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le résultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param g.
	* \return \e ostream flux.
	*/
	template <typename S, typename T>
	inline ostream & operator <<(ostream & f, const CheminEulerien<S,T> & c){
		return f << (string)c;
	}