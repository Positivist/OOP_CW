#include "Ship.h"


Ship::Ship(string name, int attack_points)
	:Machine()
{
	this->movement.air = false;
	this->movement.ground = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Ship() called " << this->name << "\n";
#endif
}

Ship::~Ship()
{
#ifdef _DEBUG
	std::cout << "~Ship()\n";
#endif
}

void Ship::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Ship::move()\n";
#endif
}
