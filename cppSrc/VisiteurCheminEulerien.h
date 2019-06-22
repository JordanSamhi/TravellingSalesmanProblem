/**
* \file VisiteurCheminEulerien.h
* \brief Classe abstraite pour visiter un chemin eulerien quelconque, elle peut servir pour le dessin ou autre.
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename S, typename T>
class CheminEulerien;

template <typename S, typename T>
class VisiteurCheminEulerien{
public:

	/**
	* \brief  méthode visite pour n'importe quel chemin.
	*/
	virtual void visite(const CheminEulerien<S,T> &, const string &) const = 0;
};
