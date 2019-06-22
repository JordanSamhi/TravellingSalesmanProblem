/**
* \file VisiteurDessinGrapheCarte.h
* \brief Classe h�riti�re de VisiteurGraphe : Visite un Graphe non g�n�rique avec des InfoAretesCarte et InfoSommetCarte.
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
	* \brief  m�thode visite pour dessiner un graphe avec des InfoAretesCarte et InfoSommetCarte.
	*/
	void visite(const Graphe<InfoAreteCarte,InfoSommetCarte> *) const;
};

