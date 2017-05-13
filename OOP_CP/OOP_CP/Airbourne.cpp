#include "stdafx.h"
#include "Airbourne.h"


Airbourne::Airbourne(Group& group, string name, int attack_points)
	:Troop(group)
{
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Airbourne() called " << this->name << "\n";
#endif
}
Airbourne::~Airbourne()
{
#ifdef _DEBUG
	std::cout << "~Airbourne()\n";
#endif
}

void Airbourne::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Airbourne::move()\n";
#endif
}