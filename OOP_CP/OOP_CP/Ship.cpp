#include "Ship.h"
#include "utils.h"

Ship::Ship(string name, int health_points, int attack_points, int capacity)
	:Machine(capacity)
{
	this->movement.air = false;
	this->movement.ground = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Ship named " << this->name << " has " << this->hp << ", " << this->hp << " attack points and capacity " << this->capacity << "\n";
#endif
	writeToFile("Ship()\n");
}

Ship::~Ship()
{
#ifdef _DEBUG
	std::cout << "~Ship()\n";
#endif
	writeToFile("~Ship()\n");
}

void Ship::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Ship::move()\n";
#endif
}
