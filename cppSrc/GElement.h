/**
* \file GElement.h
* \brief Classe non g�n�rique : GElement (pour Graphe-Element) est la classe de base dont h�ritent les classes Sommet<T> et Arete<S,T>..
* \ details Elle permet de factoriser les notions communes � ces deux classes. Ici, la seule notion commune � Sommet<T> et Arete<S,T> est une clef primaire. 
*/

#pragma once
#include <iostream>
#include <string>

using namespace std;

class GElement{
public:
	int clef;		/*! \a Clef unique du GElement.*/
	
	/**
	* \ brief Constructeur � partir d'une clef. 
	* \param  clef.
	*/
	GElement(const int &);

	/**
	* \ brief Operateur de conversion GElement ===> string.
	* \details convertit la clef de GElement en une chainee de caract�res.
	*/
	operator string() const;
};

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param g.
	* \return \e ostream flux.
	*/
inline ostream & operator <<(ostream & f, const GElement & g){
	return f << (string)g;
}