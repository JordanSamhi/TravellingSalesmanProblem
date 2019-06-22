/**
* \file Outils.h
* \brief Classe contenant des méthodes servant au projet.
*/

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "CheminEulerien.h"

/* \def LARGEUR */
const string LARGEUR = "20"; 

/* \def HAUTEUR */
const string HAUTEUR = LARGEUR;

/* \def COUT_MAXIMAL */
const double COUT_MAXIMAL = (double)INT_MAX;

using namespace std;

class Outils{
public:

	/**
	* \brief  Construction de la requête qui ouvre une fenêtre avec la hauteur et la largeur dédiées.
	* \return string la requête construite.
	*/
	static const string constructionRequeteOuvertureFenetre(){
		return "F$Graphe;"+LARGEUR+";"+HAUTEUR;
	}

	/**
	* \brief  Choisir un nombre aléatoire de 0 à X, cette méthode nécéssite l'initialisation du générateur avant son appel.
	* \return int le nombre choisi.
	*/

	static const int nombreAleatoirede0aX(const int & x){
		return (rand() % (x + 1));
	}

	/**
	* \brief  Test si x est dans t pour trouver un autre nombre aleatoire. C'est utilisé pour mélanger un chemin eulerien.
	* \ param x, t.
	* \return bool true si oui, false sinon.
	*/
	static bool nombreAleatoireDejaUtilise(const int & x, const vector<int> t){
		for(size_t i = 0; i < t.size(); i++)
			if(t[i] == x)
				return true;
		return false;
	}

	/**
	* \brief  Retourne le ième sommet demandé dans une liste de sommets.
	* \ param i, listeSommets.
	* \return SOmmet<T>* le sommet demandé à l'indice i.
	*/
	template <typename T>
	static Sommet<T>* iemeSommet(int i, PElement<Sommet<T>>* listeSommets)
	{
		PElement<Sommet<T>> *aux = listeSommets;
		for (int j = 0; j <= i - 1; j++)
		{
			aux = aux->s;
		}
		
		Sommet<T> *sommet = aux->v;
		return sommet;

	}

	/**
	* \brief  Complète un graphe par des arêtes de longueur infinie (elles seront de toute façon écartées par l'algorithme du recuit simulé).
	* \ param g, info.
	* \return Graphe<S,T> le graphe complet construit.
	*/
	template <typename S, typename T>
	static Graphe< S, T> * rendreGrapheComplet( Graphe<S, T>*  g, S & info){
		Graphe<S,T> * gTemp = g;
		int tailleGraphe = gTemp->lSommets->taille(gTemp->lSommets);
		int tailleGrapheComplet = tailleGraphe * (tailleGraphe - 1) / 2;
		if (gTemp->lAretes->taille(gTemp->lAretes) < tailleGrapheComplet){
			for(int i = 0; i < tailleGraphe; i++){
					for (int j = 0; j < tailleGraphe ; j++){
						Sommet<T> * s = iemeSommet(i, gTemp->lSommets);
						Sommet<T> * t = iemeSommet(j, gTemp->lSommets);
						if ( t != s){
							Arete<S, T> * arete = gTemp->getAreteParSommets(s, t);
							if (arete == NULL){
								gTemp->creeArete(s, t, info);
							}
						}
					}
				}
		}
		return gTemp;
	}

	
	/**
	* \brief  Fonction d'évolution de la température t. succ est strictement décroissante.
	* \ param t.
	* \return double la température évoluée.
	*/
	static double succ(const double & t){
		return t-1;
	}
};