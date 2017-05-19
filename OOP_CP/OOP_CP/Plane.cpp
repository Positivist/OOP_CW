#include "Plane.h"
#include "utils.h"

Plane::Plane(string name, int health_points, int attack_points, int capacity)
	:Machine(capacity)
{
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Plane()\n";
#endif
	writeToFile("Plane()\n");
}
Plane::~Plane()
{
#ifdef _DEBUG
	std::cout << "~Plane()\n";
#endif
	writeToFile("~Plane()\n");
}

void Plane::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Plane::move()\n";
#endif
}