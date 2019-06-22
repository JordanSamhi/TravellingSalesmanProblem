/**
* \file Sommet.h
* \brief Sommet<T>.
* \details La classe g�n�rique Sommet<S,T> repr�sente un sommet dans un graphe.. Elle d�rive de GElement et contient deux attributs.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "GElement.h"

using namespace std;


template <typename T>
class Sommet : public GElement{
public:

	int degre;	/*! \a de type int repr�sentant le degr� du sommet. */
	T v;	/*! \a instance de la classe g�n�rique T, repr�sentant l'information associ�e au sommet. */

	/**
	* \ brief Constructeur � partir d'une  d'une instance d'un �l�ment T et d'une cl�. 
	* \param  valeur, clef.
	*/

	Sommet(const T & valeur, const int & clef):GElement(clef),v(valeur),degre(0){}

	/**
	* \ brief Constructeur par copie � partir d'un sommet.
	* \details Recopie champ � champ le sommet pass� en param�tre dans Le Sommet courant.
	* \param s.
	*/
	Sommet(const Sommet<T> & s):GElement(s.clef),v(s.v),degre(s.degre){}

	
	/**
	* \ brief Operateur de conversion Sommet ===> string.
	* \details convertit les champs de Sommet en des chaines de caract�res.
	*/
	operator string() const{
		ostringstream oss;
		oss << "Sommet[" << GElement::operator std::string() << ", Degre : " << degre << ", Valeur : {" << v << "}]";
		return oss.str();
	}
	
	/**
	* \ brief Surcharge du clonage.
	* \return \e Sommet<T> * un pointeur sur le sommet clon�.
	*/
	Sommet<T> * clone() const{
		return new Sommet<T>(*this);
	}

	/**
	* \ brief 	Constrcution de requete de dessin d'un sommet avec une couleur.
	* \param color.
	* \return \e string chaine de caract�re qui contient la requ�te de dessin du sommet.
	*/
	string constructionRequeteDessin(const string & color){
		return "Sommet#"+color+";"+v.constructionRequeteDessin()+";0.1";
	}
};
	
	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param s.
	* \return \e ostream flux.
	*/
	template <typename T>
	inline ostream & operator <<(ostream & f, const Sommet<T> & s){
		return f << (string)s;
	}