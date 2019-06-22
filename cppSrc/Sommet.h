/**
* \file Sommet.h
* \brief Sommet<T>.
* \details La classe générique Sommet<S,T> représente un sommet dans un graphe.. Elle dérive de GElement et contient deux attributs.
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

	int degre;	/*! \a de type int représentant le degré du sommet. */
	T v;	/*! \a instance de la classe générique T, représentant l'information associée au sommet. */

	/**
	* \ brief Constructeur à partir d'une  d'une instance d'un élément T et d'une clé. 
	* \param  valeur, clef.
	*/

	Sommet(const T & valeur, const int & clef):GElement(clef),v(valeur),degre(0){}

	/**
	* \ brief Constructeur par copie à partir d'un sommet.
	* \details Recopie champ à champ le sommet passé en paramètre dans Le Sommet courant.
	* \param s.
	*/
	Sommet(const Sommet<T> & s):GElement(s.clef),v(s.v),degre(s.degre){}

	
	/**
	* \ brief Operateur de conversion Sommet ===> string.
	* \details convertit les champs de Sommet en des chaines de caractères.
	*/
	operator string() const{
		ostringstream oss;
		oss << "Sommet[" << GElement::operator std::string() << ", Degre : " << degre << ", Valeur : {" << v << "}]";
		return oss.str();
	}
	
	/**
	* \ brief Surcharge du clonage.
	* \return \e Sommet<T> * un pointeur sur le sommet cloné.
	*/
	Sommet<T> * clone() const{
		return new Sommet<T>(*this);
	}

	/**
	* \ brief 	Constrcution de requete de dessin d'un sommet avec une couleur.
	* \param color.
	* \return \e string chaine de caractère qui contient la requête de dessin du sommet.
	*/
	string constructionRequeteDessin(const string & color){
		return "Sommet#"+color+";"+v.constructionRequeteDessin()+";0.1";
	}
};
	
	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le résultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param s.
	* \return \e ostream flux.
	*/
	template <typename T>
	inline ostream & operator <<(ostream & f, const Sommet<T> & s){
		return f << (string)s;
	}