#include "Airborne.h"


Airborne::Airborne(string name, int attack_points)
	:Troop()
{
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Airborne() called " << this->name << "\n";
#endif
}
Airborne::~Airborne()
{
#ifdef _DEBUG
	std::cout << "~Airborne()\n";
#endif
}

void Airborne::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Airborne::move()\n";
#endif
}