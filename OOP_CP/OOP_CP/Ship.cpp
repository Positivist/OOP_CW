#include "stdafx.h"
#include "Ship.h"


Ship::Ship(Group& group, string name, int attack_points)
	:Machine(group)
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
