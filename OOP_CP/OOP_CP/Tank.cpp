#include "Tank.h"


Tank::Tank(Group& group, string name, int attack_points)
	:Machine(group)
{
	this->movement.air = false;
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Tank() called " << this->name << "\n";
#endif
}
Tank::~Tank()
{
#ifdef _DEBUG
	std::cout << "~Tank()\n";
#endif
}

void Tank::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Tank::move()\n";
#endif
}