#include <iostream>
#include <ctime>
#include <cstdlib>
#include <math.h>

using namespace std;
double tirageAleatoire01(){
	return (double) rand() / (RAND_MAX);
}

//recuit simule vu en TP avec ajout du dessin
template <class S> 
S recuitSimule(
	const double & tInitiale,
	const double & tFinale,
	const int & nombreTentativesMax,
	const int & nombreSuccesMax,
	const S & s0,
	double(* cout1)(const S & s),
	S(*changementAleatoire)(const S & s),
	double(*succ)(const double & t),
	void(*dessiner)(const S & s, const string & c)
)
{
	double t = tInitiale;
	S s = s0;
	S sBest = s0;
	while(t > tFinale){
		int nombreTentatives = 0;
		int nombreSucces = 0;
		while (nombreSuccesMax < nombreTentativesMax && nombreSucces < nombreSuccesMax){
			nombreTentatives++;
			S sPrecedente = s;
			s = changementAleatoire(s);
			/*on dessin et on "efface" tout de suite les solutions 
			pour un effet de défilement temps réel des solutions
			*/
			//dessiner(sPrecedente,"black");
			dessiner(s,"red");
			dessiner(s,"black");
			if (cout1(s) < cout1(sPrecedente)){
				nombreSucces++;
				if(cout1(s) < cout1(sBest))
					sBest = s;
			}
			else{
				double v = tirageAleatoire01();
				double deltaCout = cout1(s) - cout1(sPrecedente);
				if (v < exp(-(deltaCout/t)))
					nombreSucces++;
				else
					s = sPrecedente;
			}
		}
		if (nombreSucces == 0) return sBest;
		t = succ(t);
	}
	//On dessine la meilleur solution et on la laisse en rouge
	dessiner(sBest,"red");
	return sBest;
}