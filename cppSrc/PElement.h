/**
* \file PElement.h
* \brief Liste de Maillon de type g�n�rique.
*/

#pragma once
#include <iostream>
#include <sstream>
#include "Erreur.h"

using namespace std;

template <typename T>

class PElement{
public:
	T * v;				/*! \a v : pointeur vers une instance d'une classe g�n�rique.*/
	PElement<T> * s;	/*! \a s : pointeur vers le maillon suivant.*/

	/**
	* \ brief Constructeur � partir d'une instance d'un �l�ment T et liste � accrocher. 
	* \param  valeur, suivant.
	*/
	PElement<T>(T * valeur, PElement<T> * suivant):v(valeur),s(suivant){}

	/**
	* \ brief 	Calcule la taille de la liste.
	* \param l.
	* \return \e Retourne la taille de la liste.
	*/
	static int taille(PElement<T> * l){
		if(l == NULL)
			return 0;
		else
			return 1 + taille(l->s);
	}


	/**
	* \ brief Operateur de conversion PElement ===> string.
	* \details convertit les champs de la liste p en des chaines de caract�res s�par�s par le s�parateur et d�limit�s par debut et fin.
	* \param *p, debut, separateur, fin.
	* \return string la chaine construite.
	*/
	static const string toString(const PElement<T> * p,const string & debut="(",
	const string & separateur=", ",const string & fin = ")"){
		ostringstream oss;
		for(oss << debut;p != NULL;p = p->s){
			oss << *(p->v);
			if(p->s != NULL)
				oss << separateur;
		}
		oss << fin;
		return oss.str();
	}


	/**
	* \ brief insertionOrdonnee.
	* \details insertion de l'�l�ment a dans la liste l de fa�on ordonnee.
	* \param *a, *l.
	*/
	static void insertionOrdonnee(T * a, PElement<T> * & l, 
	bool (*estPlusPetitOuEgal)(const T * a1, const T * a2)){
		if(l == NULL || estPlusPetitOuEgal(a,l->v))
			l = new PElement<T>(a, l);
		else
			PElement::insertionOrdonnee(a,l->s,estPlusPetitOuEgal);
	}

	/**
	* \ brief D�piler une liste.
	* \details qui retire l'�l�ment situ� en t�te de l et le renvoie. Le premier maillon de l est effac�. l est donc modifi�e par l'appel. En sortie l compte un maillon de moins.
	* \param *l.
	* \return T * le premier maillon de la liste l.
	*/
	static T * depiler(PElement<T> * & l){
		if(l == NULL)
			throw Erreur("Impossible de d�piler, la liste est vide");
		T * temp = l->v;
		PElement<T> * r = l;
		l = l->s;
		delete r;
		return temp;
	}

	
	/**
	* \ brief retire dans une liste.
	* \details 	qui retire la 1�re occurrence de a de l si a est pr�sent dans l, sinon ne fait rien. L'�l�ment trouv� v n'est pas effac� mais le maillon le contenant est effac�, l est �ventuellement modifi�e.
	* \param *a, *l.
	* \return T * true si l'�l�ment a �t� trouv�, false sinon..
	*/
	static bool retire(const T * a, PElement<T> * & l){
		if(l == NULL)
			return false;
		//l contient au moins un maillon
		if(l->v == a){
			PElement<T> * r = l;
			l = l->s;
			delete r;
			return true;
		}
		else
			return PElement::retire(a,l->s);
	}

	
	/**
	* \ brief M�thode pour effacer une liste.
	* \details 	Elle efface tous les maillons de  la liste l mais qui n'efface pas les donn�es *v. En sortie l vaut NULL. Ne fait rien si l vaut NULL � l'appel.
	* \param * & l.
	*/
	static void efface1(PElement<T> * & l){
		if(l != NULL){
			PElement::efface1(l->s);
			delete l;
			l = NULL;
		}
	}

	/**
	* \ brief M�thode pour effacer une liste.
	* \details 	qui efface tous les maillons de  la liste l et toutes les donn�es *v. En sortie l vaut NULL. Ne fait rien si l vaut NULL � l'appel.
	* \param * & l.
	*/	static void efface2(PElement<T> * & l){
		if(l != NULL){
			PElement::efface2(l->s);
			delete l->v;
			delete l;
			l = NULL;
		}
	}

	/**
	* \ brief V�rification de la pr�sence d'un �l�ment dans une liste.
	* \param *v, *l.
	* \return T * true si l'�l�ment a �t� trouv�, false sinon..
	*/
	static bool estDans(const T * v, const PElement<T> * l){
		if(l == NULL)
			return false;
		else if(v == l->v)
			return true;
		return PElement::estDans(v,l->s);
	}
};  

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param p.
	* \return \e ostream flux.
	*/
	template <typename T>
	ostream & operator<<(ostream & os, const PElement<T> * p){
		return os << PElement<T>::toString(p);
	}