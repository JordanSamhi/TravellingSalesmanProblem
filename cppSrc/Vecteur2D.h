/**
* \file Vecteur2D.h
* \brief  point du plan = vecteur du plan = couple (x,y) de coordonnées  réelles..
* \details Cette classe servira à représenter un point dans une forme.
*/

#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/** 
 * \brief Définit l'operateur - binaire. 
 * \tparam T u.
 * \tparam T v.
 * \return u - v.
 */
template <class T>
const T operator - (const T & u, const T & v)
{
	return u + -v;
}
class Vecteur2D{
	double x, y;  /*! \a x , \a y coordonnées du vecteur dans le plan.*/
public:
	/**
	* \ brief Constructeur à partir des coordonnées x et y.
	* \details Les coordonnées x et y sont par défaut mis à zéro.
	* \param x.
	* \param y.
	*/
	explicit Vecteur2D(const double & x = 0, const double & y = 0);

	/**
	* \ brief Constructeur par copie à partir d'un vecteur.
	* \details Recopie les coordonnées du vecteur passé en paramètre dans \a x et \a y.
	* \param v.
	*/
	Vecteur2D(const Vecteur2D & v);

	/**
	* \ brief Destructeur.
	*/
	virtual ~Vecteur2D(){}

	/**
	* \ brief getter du champ \a x.
	* \return \e double l'abcisse stockée dans le champ \a x.
	*/
	const double getX() const;

	/**
	* \ brief setter du champ \a x.
	* \details modifie la valeur du champ \a x.
	* \param x.
	*/
	void setX(const double & x);
	
	/**
	* \ brief getter du champ \a y.
	* \return \e double l'ordonnée stockée dans le champ \a y.
	*/
	const double getY() const;

	/**
	* \ brief setter du champ \a y.
	* \details modifie la valeur du champ \a y.
	* \param y.
	*/
	void setY(const double & );

	/**
	* \ brief Opérateur d'addition entre deux vecteurs.
	* \param u.
	*/
	const Vecteur2D operator + (const Vecteur2D & u) const;

	/**
	* \ brief Opérateur de multiplication parune facteur a.
	* \param a.
	*/
	const Vecteur2D operator * (const double & a) const;

	/**
	* \brief - unaire (c'est-à- dire opposé d'un vecteur)
	**/
	const Vecteur2D operator - () const;

	/**
	* \ brief Operateur de conversion Vecteur2D ===> string.
	* \details convertit les coordonnées du vecteur en des chaines de caractères.
	*/
	operator string() const;

	/**
	* \ brief Test d'égalité avec un autre vecteur.
	* \details compare champ à champ les deux vecteurs.
	* \param objet.
	* \return \e bool true si égalité et false sinon.
	*/
	bool operator==(const Vecteur2D& objet) const;

	/**
	* \ brief Test de différence avec un autre vecteur.
	* \details Exploite l'opérateur d'égalité.
	* \param objet.
	* \return \e bool true si inégalité et false sinon.
	*/
	bool operator != (const Vecteur2D&  v) const
	{
		return !(*this == v);
	}

	/**
	* \ brief Opérateur d'affectation.
	* \details Affecte les données du vecteur passé aux différents champs \a x et \a y.
	* \param objet.
	* \return \e Vecteur2D résultat de l'affectaion.
	*/
	const Vecteur2D operator = (const Vecteur2D & objet); 

	/**
	* \ brief Surcharge l'affichage dans un flux.
	* \param flux.
	* \param u.
	* \return \e ostream flux.
	*/
	friend ostream & operator << (ostream & os, const Vecteur2D & u);

	/**
	* \ brief Une homothétie est définie par un point invariant et par un rapport d'homothétie (nombre réel quelconque). 
	*\param vectHomotethie, k.
	* Modifie le vecteur.
	*/
	void homothetie(const Vecteur2D & vectHomotethie, double k); 

	/**
	* \ brief Une homothétie est définie par un point invariant et par un rapport d'homothétie (nombre réel quelconque). 
	*\param vectHomotethie, k.
	* \return \e Vecteur2D  Une nouveau vecteur.
	*/
	Vecteur2D homothetie1(const Vecteur2D & vectHomotethie, double k)const; 

	/**
	* \ brief Une translation est définie par un vecteur de translation.
	*\param vectTranslation.
	* Modifie le vecteur.
	*/
	void translation(const Vecteur2D & vectTranslation);

	/**
	* \ brief Une translation est définie par un vecteur de translation.
	*\param vectTranslation.
	* \return \e Vecteur2D Une nouveau vecteur.
	*/
	Vecteur2D translation1(const Vecteur2D & vectTranslation)const;

	/**
	* \ brief Une rotation est définie définie par un point invariant (le centre de la rotation) et par un angle signé donné en radians.
	*\param vectCentre, angle.
	* Modifie le vecteur.
	*/
	void rotation(const Vecteur2D & vectCentre, double angle);

	/**
	* \ brief Une rotation est définie définie par un point invariant (le centre de la rotation) et par un angle signé donné en radians.
	*\param vectCentre, angle.
	* \return \e Vecteur2D Une nouveau vecteur.
	*/
	Vecteur2D rotation1(const  Vecteur2D & vectCentre, double angle)const;

	/**
	* \ brief Calcul du déterminant(u , v).
	*\param v.
	* \return \e double det(u, v).
	*/
	const double determinant(const Vecteur2D &) const;
};

	/**
	* \ brief Opérateur de multiplication ordinaire d'un vecteur par un favetur réel a.
	* \param a, v.
	*/
inline const Vecteur2D operator* (const double a, const Vecteur2D & v){
	return v * a;
}