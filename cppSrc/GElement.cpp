#include "GElement.h"
#include <sstream>

GElement::GElement(const int & clef)
	:clef(clef)
{}

GElement::operator string() const{
	ostringstream oss;
	oss << "Clef : " << clef;
	return oss.str();
}