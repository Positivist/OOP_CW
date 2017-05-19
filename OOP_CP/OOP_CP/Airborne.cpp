#include "Airborne.h"
#include "utils.h"


Airborne::Airborne(string name, int health_points, int attack_points)
	:Troop()
{
	this->movement.water = false;
	this->name = name;
	this->hp = health_points;
	this->ap = attack_points;
#ifdef _DEBUG
	std::cout << "Airborne()\n";
#endif
	writeToFile("Airborne()\n");
}
Airborne::~Airborne()
{
#ifdef _DEBUG
	std::cout << "~Airborne()\n";
#endif
	writeToFile("~Airborne()\n");
}

void Airborne::move(Coord C)
{
	//if (machineName == "") cout << "Moving on the ground";
	//else cout << "Unit with name " << this->name << " is in the machine with name " << machineName;
#ifdef _DEBUG
	std::cout << "Airborne::move()\n";
#endif
	if (machineName == "") cout << "Moving on the ground";
	else cout << "Unit named " << name << "is in the unit named " << machineName;
}