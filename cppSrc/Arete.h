/**
* \file Arete.h
* \brief Arete<S,T>.
* \details La classe g�n�rique Arete<S,T>  repr�sente une ar�te dans un graphe. Elle d�rive de GElement et contient trois attributs.
*/

#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "GElement.h"
#include "Sommet.h"

using namespace std;


template <typename S, typename T>
class Arete : public GElement{
public:
	
	Sommet<T> * debut;	/*! \a de type Sommet<T> repr�sentant un pointeur sur l'extr�mit� initiale de l'ar�te.*/
	Sommet<T> * fin;	/*! \a de type Sommet<T> repr�sentant un pointeur sur l'extr�mit� finale de l'ar�te.*/
	S v;				/*! \a de type S, instance de la classe g�n�rique  S, repr�sentant l'information associ�e � l'ar�te. */
	
	/**
	* \ brief Constructeur � partir d'une extr�mit� initiale, d'une extr�mi� finale, d'une information et d'une cl�. 
	* \param *d, *f, v, clef.
	*/
	Arete(Sommet<T> * d, Sommet<T> * f, const S & v, const int & clef):GElement(clef),debut(d),fin(f),v(v){
		//Les degres des sommets sont incr�ment�s
		debut->degre++;
		fin->degre++;
	}

	/**
	* \ brief Destructeur.
	* \ details Les degres des sommets sont d�cr�ment�s.
	*/
	~Arete(){
		debut->degre--;
		fin->degre--;
	}
	

	/**
	* \ brief Operateur de conversion Arete ===> string.
	* \details convertit les champs de Arete en des chaines de caract�res.
	*/
	operator string() const{
		ostringstream oss;
		oss << "Arete[" << GElement::operator std::string() << " Debut : " << debut->clef << ", Fin : " << fin->clef << ", v : " << v << "]";
		return oss.str();
	}

	/**
	* \ brief On test si l'arete courante est �gale � l'arete s1-s2. 
	* \param *s1, *s2.
	* \return \e bool true si �galit� et false sinon.
	*/
	bool estEgal(const Sommet<T> * s1, const Sommet<T> * s2) const{
		return (s1 == debut && s2 == fin) || (s1 == fin && s2 == debut);
	}

	/**
	* \ brief 	Constrcution de requete de dessin d'une arete avec une couleur.
	* \param color.
	* \return \e string chaine de caract�re qui contient la requ�te de dessin de l'arete.
	*/
	string constructionRequeteDessin(const string & color){
		string p1 = (string)debut->v.position;
		string p2 = (string)fin->v.position;
		string vv = (string) v;
		return "Arete#"+color+";"+p1+";"+p2+";"+vv;
	}

	/**
	* \ brief Calcul de la distance entre 2 points.
	* \param *s1, *s2.
	* \return \e double la distance calcul�e.
	*/
	static double distance(const Sommet<T> * s1,  const Sommet<T> * s2){
		return sqrt(pow((s2->v.position.getX()-s1->v.position.getX()),2)+pow((s2->v.position.getY()-s1->v.position.getY()),2));
	}

	/**
	* \ brief Calcul du cout d'une arete.
	* \return \e double le co�t.
	*/
	double cout() const{
		return v.cout;
	}
};

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \details Exploite le r�sultat de l'operateur de conversion en string et le sort dans un flux.
	* \param flux.
	* \param a.
	* \return \e ostream flux.
	*/
	template <typename S, typename T>
	inline ostream & operator <<(ostream & f, const Arete<S,T> & a){
		return f << (string)a;
	}