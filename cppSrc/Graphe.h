/**
* \file Graphe.h
* \brief La classe générique Graphe<S,T> représente un graphe quelconque. 
* \details T est la nature des informations associées aux sommets et S celle des informations associées aux arêtes. Un graphe est défini par une liste de sommets, par une liste d'arêtes et par un générateur de clefs primaires.
*/


#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "PElement.h"
#include "Sommet.h"
#include "Arete.h"
#include "VisiteurGraphe.h"

using namespace std;


template <typename S, typename T>
class Graphe{
public:
	
	PElement<Sommet<T>> * lSommets;	/*! \a Liste de sommets.*/
	
	PElement<Arete<S,T>> * lAretes;	/*! \a Liste de d'aretes.*/
	
	int prochaineClef;		/*! \a Prochaine clef unique.*/
	
	/**
	* \ brief Constructeur par défaut.
	*/
	Graphe():lSommets(NULL), lAretes(NULL), prochaineClef(0){}

	/**
	* \ brief Constructeur par copie à partir d'un graphe.
	* \details Recopie champ à champ le graphe passé en paramètre dans Le graphe.
	* \param g.
	*/
	Graphe(const Graphe<S,T> & g){
		//copie des sommets
		PElement<Sommet<T>> * lS = g.lSommets;
		for(lSommets = NULL; lS != NULL; lS = lS->s)
			lSommets = new PElement<Sommet<T>>(lS->v->clone(),lSommets);
		//copie des aretes
		PElement<Arete<S,T>> * lA = g.lAretes;
		//on parcours les aretes de g
		for(lAretes = NULL; lA != NULL; lA = lA->s){
			Sommet<T> * deb, *fin;
			deb = fin = NULL;
			S val = lA->v->v;
			int clef = lA->v->clef;
			/*
			on boucle sur lS tant qu'on est pas a la fin
			de la chaine et que deb et fin ne sont pas trouvés
			(on raccroche le lS à notre lSommet courant cette fois-ci)
			*/
			for(lS = lSommets ; lS != NULL && (deb == NULL || fin == NULL); lS = lS->s){
				/*
				si la clé de notre sommet courant dans lS est
				égale à celle du sommet de début de l'arete de 
				lArete de g alors on pointe notre debut vers
				le sommet courant dans lS
				*/
				if(lS->v->clef == lA->v->debut->clef)
					deb = lS->v;
				/*
				si la clé de notre sommet courant dans lS est
				égale à celle du sommet de fin de l'arete de 
				lArete de g alors on pointe notre fin vers
				le sommet courant dans lS
				*/
				if(lS->v->clef == lA->v->fin->clef)
					fin = lS->v;
			}
			//enfin on construit le maillon suivant dans lArete
			lAretes = new PElement<Arete<S,T>>(new Arete<S,T>(deb,fin,val,clef),lAretes);
		}
	}

	/**
	* \ brief Destructeur.
	*/
	~Graphe(){
		PElement<Arete<S,T>>::efface2(this->lAretes);
		PElement<Sommet<T>>::efface2(this->lSommets);
	}

	/**
	* \ brief Création, dans le graphe, un sommet isolé muni de l'information info. Un pointeur sur le sommet créé est retourné.
	* \ return Sommet<T> l'arete crée.
	*/
	
	Sommet<T> * creeSommet(const T & info){
		lSommets = new PElement<Sommet<T>>(new Sommet<T>(info, prochaineClef++),lSommets);
		return lSommets->v;
	}


	
	/**
	* \ brief Création, dans le graphe, une arête reliant les sommets debut et fin.
	* \details  A l'appel, on suppose que debut et fin sont déjà contenus dans le graphe. L'arête créée contient l'information info. La méthode ne fait pas de copie de debut ou de fin. Les degrés de debut et de fin sont mis à jour par la méthode. Un pointeur sur l'arête créée est retourné.
	* \ return Arete<S,T> l'arete crée.
	*/
	Arete<S,T> * creeArete(Sommet<T> * debut, Sommet<T> * fin, const S & info){
		//on test d'abord si les sommets existent
		if(!PElement<Sommet<T>>::estDans(debut,this->lSommets))
			throw Erreur("L'arete de debut n'existe pas dans le graphe");
		if(!PElement<Sommet<T>>::estDans(fin,this->lSommets))
			throw Erreur("L'arete de fin n'existe pas dans le graphe");
		lAretes = new PElement<Arete<S,T>>(new Arete<S,T>(debut,fin,info, prochaineClef++),lAretes);
		return lAretes->v;
	}

	/**
	* \ brief Nombre de sommets dans le graphe.
	* \ return int le nombre calculé.
	*/
	int nombreSommets() const{
		return PElement<Sommet<T>>::taille(lSommets);
	}

	/**
	* \ brief Nombre d'aretes dans le graphe.
	* \ return int le nombre calculé.
	*/
	int nombreAretes() const{
		return PElement<Arete<S,T>>::taille(lAretes);
	}

	/**
	* \ brief Operateur de conversion Graphe ===> string.
	* \details convertit les champs de Graphe en une chainee de caractères.
	*/
	operator string() const{
		ostringstream oss;
		oss << "Graphe : " << endl;
		oss << "Sommets : "<< endl << PElement<Sommet<T>>::toString(lSommets,"","\n","") << endl;
		oss << "Aretes : " << endl << PElement<Arete<S,T>>::toString(lAretes,"","\n","");
		return oss.str();
	}

	
	/**
	* \brief Renvoie l'arete décrite par les deux sommets passés en paramètre.
	* \param s1, s2.
	* \return Arete<S,T> l'arete trouvée, et NULL sinon.
	*/
	Arete<S,T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const{
		PElement<Arete<S,T> > * l;
		for (l = this->lAretes; l; l = l->s)
			if (l->v->estEgal(s1,s2))
			   return l->v;
		return NULL;
	}

	/**
	* \brief Recherche la liste des paires (voisin, arête) adjacentes de sommet dans le graphe.
	* \param sommet.
	* \return PElement<pair<Sommet<T> *,Arete<S,T> *>> * la liste construite.
	*/
	PElement<pair<Sommet<T> *,Arete<S,T> *>> *adjacences(const Sommet<T> * sommet)const{
		const PElement< Arete<S,T> > * l;
		PElement< pair< Sommet<T> *, Arete<S,T>* > > * r;
		for(l = lAretes, r = NULL; l; l = l->s){
			if(sommet == l->v->debut)
				r = new PElement<pair<Sommet<T> *,Arete<S,T> *>>(new pair< Sommet<T> *, Arete<S,T>* >(l->v->fin,l->v),r);
			else if(sommet == l->v->fin)
				r = new PElement<pair<Sommet<T> *,Arete<S,T> *>>( new pair< Sommet<T> *,Arete<S,T> *>(l->v->debut,l->v),r);
		}
		return r;
	}

	/**
	* \ brief Acceptaion d'un VisiteurGraphe.
	* \param  * visiteur. 
	*/
	void accepter(const VisiteurGraphe<S,T> * visiteur)const{
		visiteur->visite(this);
	}

	/**
	* \ brief dessine le graphe.
	* \param visiteur.
	*/
	void dessiner(const VisiteurGraphe<S,T> * visiteur)const{
		accepter(visiteur);
	}

	/**
	* \ brief Opérateur d'affectation.
	* \details Affecte les données du Graphe passé aux différents champs du graphe.
	* \param g.
	* \return \e Graphe <S,T> & résultat de l'affectaion.
	*/
	const Graphe <S,T> & operator = (const Graphe <S,T> & g)
	{
		if(this != &g)
		{
			lSommets->efface2(lSommets);
			lAretes->efface2(lAretes);

			PElement<Sommet<T>> *r = null;
			for(int i = 0; i < g.lSommets->taille(g.lSommets); i++)
			{
				r = new PElement<Sommet<T>>(g.lSommets->depiler(g.lSommets), r);
			}

			PElement<Arete<S,T>> *t = null;
			for(int i = 0; i < g.lAretes->taille(g.lAretes); i++)
			{
				t = new PElement<Arete<S,T>>(g.lAretes->depiler(g.lAretes), t);
			}

			lSommets = r;
			lAretes = t;
		}
	return *this;

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
	inline ostream & operator <<(ostream & f, const Graphe<S,T> & g){
		return f << (string)g;
	}