#include "Plane.h"


Plane::Plane(string name, int attack_points)
	:Machine()
{
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Plane() called " << this->name << "\n";
#endif
}
Plane::~Plane()
{
#ifdef _DEBUG
	std::cout << "~Plane()\n";
#endif
}

void Plane::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Plane::move()\n";
#endif
}