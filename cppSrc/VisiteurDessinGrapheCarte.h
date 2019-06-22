/**
* \file VisiteurDessinGrapheCarte.h
* \brief Classe héritière de VisiteurGraphe : Visite un Graphe non générique avec des InfoAretesCarte et InfoSommetCarte.
*/

#pragma once
#include <iostream>
#include <string>
#include "VisiteurGraphe.h"
#include "SingletonConnexion.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
using namespace std;

class VisiteurDessinGrapheCarte : public VisiteurGraphe<InfoAreteCarte,InfoSommetCarte>{
public:

	/**
	* \brief  méthode visite pour dessiner un graphe avec des InfoAretesCarte et InfoSommetCarte.
	*/
	void visite(const Graphe<InfoAreteCarte,InfoSommetCarte> *) const;
};

