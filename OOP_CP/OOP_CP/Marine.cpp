#include "Marine.h"

Marine::Marine(string name, int attack_points)
	:Troop()
{
	this->movement.air = false;
	this->movement.ground = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Marine() called " << this->name << "\n";
#endif
}
Marine::~Marine()
{
#ifdef _DEBUG
	std::cout << "~Marine()\n";
#endif
}

void Marine::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Marine::move()\n";
#endif
}
