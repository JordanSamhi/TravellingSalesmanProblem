/**
* \file InfoAreteCarte.h
* \brief  contient les informations relatives � une ar�te.
* \details Cette classe permet la d�finition de la classe non g�n�rique Arete<InfoAreteCarte, InfoSommetCarte> qui repr�sente une route d'une carte routi�re.
*/
#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Erreur.h"

using namespace std;

class InfoAreteCarte{
public:
	
	double cout;	/*! \a Cout de l'arete.*/

	/**
	* \ brief Constructeur � partir d'un double cout. 
	* \param c.
	*/
	InfoAreteCarte(const double & c);

	
	/**
	* \ brief Operateur de conversion InfoAreteCarte ===> string.
	* \details convertit le champs Cout de l'info en une chaine de caract�res.
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
	inline ostream & operator<<(ostream & f, const InfoAreteCarte & i){
		return f << (string)i;
	}