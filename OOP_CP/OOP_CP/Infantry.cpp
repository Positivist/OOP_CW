#include "Infantry.h"
#include "utils.h"

Infantry::Infantry(string name, int health_points, int attack_points)
	:Troop()
{
	this->movement.air = false;
	this->movement.water = false;
	this->name = name;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Infantry()\n";
#endif
	writeToFile("Infantry()\n");
}
Infantry::~Infantry()
{
#ifdef _DEBUG
	std::cout << "~Infantry()\n";
#endif
	writeToFile("~Infantry()\n");
}

void Infantry::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Infantry::move()\n";
#endif
	if (machineName == "") cout << "Moving on the ground";
	else cout << "Unit named " << name << "is in the unit named " << machineName;
}