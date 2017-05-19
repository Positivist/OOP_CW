#include "Marine.h"
#include "utils.h"

Marine::Marine(string name, int health_points, int attack_points)
	:Troop()
{
	this->movement.air = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Marine()\n";
#endif
	writeToFile("Machine()\n");
}
Marine::~Marine()
{
#ifdef _DEBUG
	std::cout << "~Marine()\n";
#endif
	writeToFile("~Machine()\n");
}

void Marine::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Marine::move()\n";
#endif
	if (machineName == "") cout << "Moving on the ground";
	else cout << "Unit named " << name << "is in the unit named " << machineName;
}
