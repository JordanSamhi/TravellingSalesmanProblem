#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Graphe.h"
#include "InfoAreteCarte.h"
#include "InfoSommetCarte.h"
#include "VisiteurDessinGrapheCarte.h"
#include "VisiteurDessinCheminEulerien.h"
#include "Outils.h"
#include "recuitSimule.h"
#include "CheminEulerien.h"

using namespace std;

int main(){ 
	//Initialisation du seed pour du pseudo-aléatoire
	srand((unsigned int)time(NULL));
	//Creation du graphe g1
	Graphe<InfoAreteCarte,InfoSommetCarte> * g1 = new Graphe<InfoAreteCarte,InfoSommetCarte>();
	//Creation des sommets
	Sommet<InfoSommetCarte> * s[9];
	s[0] = g1->creeSommet(InfoSommetCarte("Paris",Vecteur2D(-7,-2)));
	s[1] = g1->creeSommet(InfoSommetCarte("Bruxelles",Vecteur2D(-5,3)));
	s[2] = g1->creeSommet(InfoSommetCarte("Geneve",Vecteur2D(-2,-7)));
	s[3] = g1->creeSommet(InfoSommetCarte("Strasbourg",Vecteur2D(-1,-2)));
	s[4] = g1->creeSommet(InfoSommetCarte("Francfort",Vecteur2D(1,1)));
	s[5] = g1->creeSommet(InfoSommetCarte("Stuttgart",Vecteur2D(2,-2)));
	s[6] = g1->creeSommet(InfoSommetCarte("Munich",Vecteur2D(5,-3)));
	s[8] = g1->creeSommet(InfoSommetCarte("Berlin",Vecteur2D(7,6)));

	//Creation des aretes
	double d;
	Arete<InfoAreteCarte,InfoSommetCarte> * a[16];
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[0],s[1]);
	a[0] = g1->creeArete(s[0],s[1], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[0],s[4]);
	a[1] = g1->creeArete(s[0],s[4], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[0],s[6]);
	a[2] = g1->creeArete(s[0],s[6], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[1],s[2]);
	a[3] = g1->creeArete(s[1],s[2], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[1],s[3]);
	a[4] = g1->creeArete(s[1],s[3], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[3],s[4]);
	a[5] = g1->creeArete(s[3],s[4], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[3],s[5]);
	a[6] = g1->creeArete(s[3],s[5], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[3],s[2]);
	a[7] = g1->creeArete(s[3],s[2], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[5],s[4]);
	a[8] = g1->creeArete(s[5],s[4], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[5],s[2]);
	a[9] = g1->creeArete(s[5],s[2], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[5],s[8]);
	a[10] = g1->creeArete(s[5],s[8], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[5],s[6]);
	a[12] = g1->creeArete(s[5],s[6], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[8],s[4]);
	a[13] = g1->creeArete(s[8],s[4], InfoAreteCarte(d));
	d = Arete<InfoAreteCarte,InfoSommetCarte>::distance(s[8],s[6]);
	a[14] = g1->creeArete(s[8],s[6], InfoAreteCarte(d));

	cout << "=============" << endl;
	cout << "| Graphe g1 |" << endl;
	cout << "=============" << endl;
	cout << *g1 << endl << endl;

	////Affichage du premier chemin eulerien du graphe généré
	cout << "=====================" << endl;
	cout << "| Chemin Eulerien 1 |" << endl;
	cout << "=====================" << endl;
	CheminEulerien<InfoAreteCarte,InfoSommetCarte> c(g1);
	cout << c << endl;
	cout << "Cout : " <<  CheminEulerien<InfoAreteCarte,InfoSommetCarte>::coutChemin(c) << endl << endl;

	////Affichage du deuxieme cheminEulerien apres changement aleatoire
	c = CheminEulerien<InfoAreteCarte,InfoSommetCarte>::melangeAleatoireCheminEulerien(c);
	cout << "===============================================" << endl;
	cout << "| Chemin Eulerien 2 (apres melange aleatoire) |" << endl;
	cout << "===============================================" << endl;
	cout << c << endl;
	cout << "Cout : " <<  CheminEulerien<InfoAreteCarte,InfoSommetCarte>::coutChemin(c) << endl << endl;

	cout << "=======================" << endl;
	cout << "| Dessin du graphe g1 |" << endl;
	cout << "=======================" << endl;
	g1->dessiner(new VisiteurDessinGrapheCarte);
	
	//RECUIT SIMULE
	cout << endl;
	cout << "=======================================================" << endl;
	cout << "| POUR LANCER LE RECUIT SIMULE APPUYER SUR UNE TOUCHE |" << endl;
	cout << "=======================================================" << endl;
	system("pause > null");
	cout << "Recuit Simule en cours... (Suivre l'evolution sur la fenetre du serveur JAVA)" << endl << endl;
	

	CheminEulerien<InfoAreteCarte,InfoSommetCarte> solution(g1);
	double tInitiale, tFinale; 
	int nombreTentativesMax, nombreSuccesMax;
	tInitiale = 20;
	tFinale = 0;
	nombreTentativesMax = 10;
	nombreSuccesMax = 5;

	//Appel de la fonction recuit simule avec DESSIN des chemins + solution (en temps réel)
	solution = recuitSimule(
	tInitiale,
	tFinale,
	nombreTentativesMax,
	nombreSuccesMax,
	solution,
	CheminEulerien<InfoAreteCarte,InfoSommetCarte>::coutChemin,
	CheminEulerien<InfoAreteCarte,InfoSommetCarte>::melangeAleatoireCheminEulerien,
	Outils::succ,
	CheminEulerien<InfoAreteCarte,InfoSommetCarte>::dessiner
	);
	
	cout << "===================" << endl;
	cout << "| /!\\ TERMINE /!\\ |" << endl;
	cout << "===================" << endl;
	cout << "Solution : " << endl;
	cout << solution << endl;
	cout << "Cout : " <<  CheminEulerien<InfoAreteCarte,InfoSommetCarte>::coutChemin(solution) << endl << endl;

	cout << "==============================================================" << endl;
	cout << "|         Le serveur peut mettre un peu plus de temps        |" << endl;
	cout << "| avant d'afficher la solution finale, veuillez patientez... |" << endl << endl;
	cout << "==============================================================" << endl;

	system("pause");
	return 0;
}