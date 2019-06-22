/**
* \file Erreur.h
* \brief Erreur.
*/

#pragma once
#include<iostream>
#include<string>

using namespace std;

class Erreur{
	string msg;	/*! \a msg de type string, servant au message affich� lors d'une lev�e d'exception.*/
public :
	/**
	* \ brief Constructeur � partir d'une chaine.
	* \param m
	*/
	Erreur(const string&  m):msg(m){}

	/**
	* \ brief getter du champ \a msg.
	* \return \e string le message stock�e dans le champ \a msg.
	*/
	const string & getMessage() const {return this->msg;}
};

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param e.
	* \return \e ostream flux.
	*/
	inline ostream & operator << (ostream & flux, const Erreur & e){
		return flux << e.getMessage();
	}