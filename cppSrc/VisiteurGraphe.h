/**
* \file VisiteurGraphe.h
* \brief Classe abstraite pour visiter un graphe quelconque, elle peut servir pour le dessin ou autre.
*/
#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename S, typename T>
class Graphe;

template <typename S, typename T>
class VisiteurGraphe{
public:
	/**
	* \brief  méthode visite pour n'importe quel Graphe.
	*/
	virtual void visite(const Graphe<S,T> *) const = 0;
};
