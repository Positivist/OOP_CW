#include "Tank.h"
#include "utils.h"

Tank::Tank(string name, int health_points, int attack_points, int capacity)
	:Machine(capacity)
{
	this->movement.air = false;
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Tank()\n";
#endif
	writeToFile("Tank()\n");
}
Tank::~Tank()
{
#ifdef _DEBUG
	std::cout << "~Tank()\n";
#endif
	writeToFile("~Tank()\n");
}

void Tank::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Tank::move()\n";
#endif
}