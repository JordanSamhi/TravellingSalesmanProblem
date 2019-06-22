/**
* \file InfoAreteCarte.h
* \brief  contient les informations relatives à une arête.
* \details Cette classe permet la définition de la classe non générique Arete<InfoAreteCarte, InfoSommetCarte> qui représente une route d'une carte routière.
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
	* \ brief Constructeur à partir d'un double cout. 
	* \param c.
	*/
	InfoAreteCarte(const double & c);

	
	/**
	* \ brief Operateur de conversion InfoAreteCarte ===> string.
	* \details convertit le champs Cout de l'info en une chaine de caractères.
	*/
	operator string() const;

	/**
	* \ brief 	Constrcution de requete de dessin de l'info.
	* \return \e string chaine de caractère qui contient la requête de dessin de l'info.
	*/
	string constructionRequeteDessin(){
		return (string) *this;
	}
};

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le résultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param i.
	* \return \e ostream flux.
	*/
	inline ostream & operator<<(ostream & f, const InfoAreteCarte & i){
		return f << (string)i;
	}