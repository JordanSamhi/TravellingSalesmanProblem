#include "Vecteur2D.h"
#include <cmath>


Vecteur2D::Vecteur2D(const double & x , const double & y ):
	x(x), y(y){}

Vecteur2D::Vecteur2D(const Vecteur2D & v): x(v.x), y(v.y)
{}

const double Vecteur2D::getX()const
{
	return x;
}

void Vecteur2D::setX(const double & nouveauX)
{
	x = nouveauX;
}
const double Vecteur2D::getY()const
{
	return y;
}

void Vecteur2D::setY(const double & nouveauY)
{
	x = nouveauY;
}

const Vecteur2D Vecteur2D::operator + (const Vecteur2D & u) const
{
	return Vecteur2D(x + u.x, y + u.y);
}

const Vecteur2D Vecteur2D::operator * (const double & a) const
{
	return Vecteur2D(x * a, y * a);
}

const Vecteur2D Vecteur2D::operator - () const
{
	return Vecteur2D(-x, -y);
}

bool Vecteur2D:: operator==(const Vecteur2D& v) const
{
	return (x == v.getX() && y == (v.getY()));
}

const Vecteur2D Vecteur2D:: operator = (const Vecteur2D & v)
{
	if (this != &v)
	{
		x = v.getX();
		y = v.getY();
	}
	return *this;
}

Vecteur2D::operator string() const
{
	ostringstream oss;
	oss << "(" << x << "," << y << ")";
	return oss.str();
}

 ostream & operator << (ostream & os, const Vecteur2D & u)
 {
	 os <<"("<< u.getX()<<","<< u.getY()<<")";
	return os;
 }

 const double Vecteur2D::determinant(const Vecteur2D & vect) const
 {
	 return (x * vect.getY()) - (y * vect.getX());
 }

 void Vecteur2D::translation(const Vecteur2D & vectTranslation)
 {
	 // il suffit de faire l'ajout des coordonnées de vectTranslation à ceux de this
	 Vecteur2D vect(*this);
	 vect = vect  + vectTranslation;
	 *this = vect;
 }

 Vecteur2D Vecteur2D::translation1(const Vecteur2D & vectTranslation)const
 {
	 Vecteur2D v(*this);
	 v.translation(vectTranslation);
	 return v;
 }

 void Vecteur2D::homothetie(const Vecteur2D & vectHomotethie, double k)
 {
	 *this = k * (*this) + (1-k) * vectHomotethie;
 }

 Vecteur2D Vecteur2D::homothetie1(const Vecteur2D & vectHomotethie, double k)const
 {
	 Vecteur2D v(*this);
	 v.homothetie(vectHomotethie, k);
	 return v;
 }

 void Vecteur2D::rotation(const Vecteur2D & vectCentre, double angle)
 {
	 double deltaX = x - vectCentre.getX(), deltaY = y - vectCentre.getY(); 
	 x = deltaX * cos(angle) - deltaY * sin(angle) + vectCentre.getX();
	 y = deltaX * sin(angle) + deltaY * cos(angle) + vectCentre.getY();
 }

 Vecteur2D Vecteur2D::rotation1(const Vecteur2D & vectCentre, double angle)const
 {
	 Vecteur2D v(*this);
	 v.rotation(vectCentre, angle);
	 return v;
 }