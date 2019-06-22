#include "InfoAreteCarte.h"

InfoAreteCarte::InfoAreteCarte(const double & c){
	if(c < 0)
		throw Erreur("Le cout ne peut �tre n�gatif");
	cout = c;
}
InfoAreteCarte::operator string() const{
	ostringstream oss;
	oss << cout ;
	return oss.str();
}