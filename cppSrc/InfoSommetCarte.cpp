#include "InfoSommetCarte.h"

InfoSommetCarte::InfoSommetCarte(const string & n, const Vecteur2D & p)
	:nom(n),position(p)
{}

InfoSommetCarte::operator string() const{
	ostringstream oss;
	oss  << position.operator std::string() << ";" <<  nom ;
	return oss.str();
}