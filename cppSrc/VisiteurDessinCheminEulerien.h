/**
* \file VisiteurDessinCheminEulerien.h
* \brief Classe h�riti�re de VisiteurCheminEulerien : Visite un CheminEulerien non g�n�rique avec des InfoAretesCarte et InfoSommetCarte.
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
	* \brief  m�thode visite pour dessiner un chemin eul�rien avec des InfoAretesCarte et InfoSommetCarte.
	*/
	void visite(const CheminEulerien<InfoAreteCarte,InfoSommetCarte> &, const string &) const;
};