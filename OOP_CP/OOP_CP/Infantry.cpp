#include "stdafx.h"
#include "Infantry.h"


Infantry::Infantry(Group& group, string name, int attack_points)
	:Troop(group)
{
	this->movement.air = false;
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Infantry() called " << this->name << "\n";
#endif
}
Infantry::~Infantry()
{
#ifdef _DEBUG
	std::cout << "~Infantry()\n";
#endif
}

void Infantry::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Infantry::move()\n";
#endif
}