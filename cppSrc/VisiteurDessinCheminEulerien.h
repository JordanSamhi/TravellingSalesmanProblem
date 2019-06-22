/**
* \file VisiteurDessinCheminEulerien.h
* \brief Classe héritière de VisiteurCheminEulerien : Visite un CheminEulerien non générique avec des InfoAretesCarte et InfoSommetCarte.
*/

#pragma once
#include <iostream>
#include <string>
#include "VisiteurCheminEulerien.h"
#include "SingletonConnexion.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "CheminEulerien.h"
using namespace std;


class VisiteurDessinCheminEulerien : public VisiteurCheminEulerien<InfoAreteCarte,InfoSommetCarte>{
public:

	/**
	* \brief  méthode visite pour dessiner un chemin eulérien avec des InfoAretesCarte et InfoSommetCarte.
	*/
	void visite(const CheminEulerien<InfoAreteCarte,InfoSommetCarte> &, const string &) const;
};