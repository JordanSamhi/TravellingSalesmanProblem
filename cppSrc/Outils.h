/**
* \file Outils.h
* \brief Classe contenant des m�thodes servant au projet.
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
	* \brief  Construction de la requ�te qui ouvre une fen�tre avec la hauteur et la largeur d�di�es.
	* \return string la requ�te construite.
	*/
	static const string constructionRequeteOuvertureFenetre(){
		return "F$Graphe;"+LARGEUR+";"+HAUTEUR;
	}

	/**
	* \brief  Choisir un nombre al�atoire de 0 � X, cette m�thode n�c�ssite l'initialisation du g�n�rateur avant son appel.
	* \return int le nombre choisi.
	*/

	static const int nombreAleatoirede0aX(const int & x){
		return (rand() % (x + 1));
	}

	/**
	* \brief  Test si x est dans t pour trouver un autre nombre aleatoire. C'est utilis� pour m�langer un chemin eulerien.
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
	* \brief  Retourne le i�me sommet demand� dans une liste de sommets.
	* \ param i, listeSommets.
	* \return SOmmet<T>* le sommet demand� � l'indice i.
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
	* \brief  Compl�te un graphe par des ar�tes de longueur infinie (elles seront de toute fa�on �cart�es par l'algorithme du recuit simul�).
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
	* \brief  Fonction d'�volution de la temp�rature t. succ est strictement d�croissante.
	* \ param t.
	* \return double la temp�rature �volu�e.
	*/
	static double succ(const double & t){
		return t-1;
	}
};