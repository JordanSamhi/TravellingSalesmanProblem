/**
* \file Graphe.h
* \brief La classe g�n�rique Graphe<S,T> repr�sente un graphe quelconque. 
* \details T est la nature des informations associ�es aux sommets et S celle des informations associ�es aux ar�tes. Un graphe est d�fini par une liste de sommets, par une liste d'ar�tes et par un g�n�rateur de clefs primaires.
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
	* \ brief Constructeur par d�faut.
	*/
	Graphe():lSommets(NULL), lAretes(NULL), prochaineClef(0){}

	/**
	* \ brief Constructeur par copie � partir d'un graphe.
	* \details Recopie champ � champ le graphe pass� en param�tre dans Le graphe.
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
			de la chaine et que deb et fin ne sont pas trouv�s
			(on raccroche le lS � notre lSommet courant cette fois-ci)
			*/
			for(lS = lSommets ; lS != NULL && (deb == NULL || fin == NULL); lS = lS->s){
				/*
				si la cl� de notre sommet courant dans lS est
				�gale � celle du sommet de d�but de l'arete de 
				lArete de g alors on pointe notre debut vers
				le sommet courant dans lS
				*/
				if(lS->v->clef == lA->v->debut->clef)
					deb = lS->v;
				/*
				si la cl� de notre sommet courant dans lS est
				�gale � celle du sommet de fin de l'arete de 
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
	* \ brief Cr�ation, dans le graphe, un sommet isol� muni de l'information info. Un pointeur sur le sommet cr�� est retourn�.
	* \ return Sommet<T> l'arete cr�e.
	*/
	
	Sommet<T> * creeSommet(const T & info){
		lSommets = new PElement<Sommet<T>>(new Sommet<T>(info, prochaineClef++),lSommets);
		return lSommets->v;
	}


	
	/**
	* \ brief Cr�ation, dans le graphe, une ar�te reliant les sommets debut et fin.
	* \details  A l'appel, on suppose que debut et fin sont d�j� contenus dans le graphe. L'ar�te cr��e contient l'information info. La m�thode ne fait pas de copie de debut ou de fin. Les degr�s de debut et de fin sont mis � jour par la m�thode. Un pointeur sur l'ar�te cr��e est retourn�.
	* \ return Arete<S,T> l'arete cr�e.
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
	* \ return int le nombre calcul�.
	*/
	int nombreSommets() const{
		return PElement<Sommet<T>>::taille(lSommets);
	}

	/**
	* \ brief Nombre d'aretes dans le graphe.
	* \ return int le nombre calcul�.
	*/
	int nombreAretes() const{
		return PElement<Arete<S,T>>::taille(lAretes);
	}

	/**
	* \ brief Operateur de conversion Graphe ===> string.
	* \details convertit les champs de Graphe en une chainee de caract�res.
	*/
	operator string() const{
		ostringstream oss;
		oss << "Graphe : " << endl;
		oss << "Sommets : "<< endl << PElement<Sommet<T>>::toString(lSommets,"","\n","") << endl;
		oss << "Aretes : " << endl << PElement<Arete<S,T>>::toString(lAretes,"","\n","");
		return oss.str();
	}

	
	/**
	* \brief Renvoie l'arete d�crite par les deux sommets pass�s en param�tre.
	* \param s1, s2.
	* \return Arete<S,T> l'arete trouv�e, et NULL sinon.
	*/
	Arete<S,T> * getAreteParSommets(const Sommet<T> * s1, const Sommet<T> * s2) const{
		PElement<Arete<S,T> > * l;
		for (l = this->lAretes; l; l = l->s)
			if (l->v->estEgal(s1,s2))
			   return l->v;
		return NULL;
	}

	/**
	* \brief Recherche la liste des paires (voisin, ar�te) adjacentes de sommet dans le graphe.
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
	* \ brief Op�rateur d'affectation.
	* \details Affecte les donn�es du Graphe pass� aux diff�rents champs du graphe.
	* \param g.
	* \return \e Graphe <S,T> & r�sultat de l'affectaion.
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
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param g.
	* \return \e ostream flux.
	*/
	template <typename S, typename T>
	inline ostream & operator <<(ostream & f, const Graphe<S,T> & g){
		return f << (string)g;
	}