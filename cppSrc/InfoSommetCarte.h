/**
* \file InfoSommetCarte.h
* \brief  contient les informations relatives � une ar�te.
* \details Cette classe permet la d�finition de la classe non g�n�rique Arete<InfoAreteCarte, InfoSommetCarte> qui repr�sente une route d'une carte routi�re.
*/
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "Vecteur2D.h"

using namespace std;

class InfoSommetCarte{
public:
	
	string nom;				/*! \a Info relative au sommet.*/
	Vecteur2D position;		/*! \a position du sommet (en cm).*/

	/**
	* \ brief Constructeur � partir d'un string nom et d'une position. 
	* \param n, p.
	*/
	InfoSommetCarte(const string & n, const Vecteur2D & p);

	/**
	* \ brief Operateur de conversion InfoSommetCarte ===> string.
	* \details convertit les champs nom et position de l'info en une chaine de caract�res.
	*/
	operator string() const;

	/**
	* \ brief 	Constrcution de requete de dessin de l'info.
	* \return \e string chaine de caract�re qui contient la requ�te de dessin de l'info.
	*/
	string constructionRequeteDessin(){
		return (string) *this;
	}
};

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param i.
	* \return \e ostream flux.
	*/
	inline ostream & operator<<(ostream & f, const InfoSommetCarte & i){
	return f <<  "Nom : " << i.nom << ", Position : " << i.position;
}