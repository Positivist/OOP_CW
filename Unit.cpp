#include "stdafx.h"
#include "Unit.h"
#include "time.h"
#include <typeinfo.h>  
#include <string>
using namespace std;
//--------------------Unit's group------------------------------------------

void Group::add(Unit* object)
{
	Unit *prvhead = first;
	first = object;
	first->next = prvhead;
}

Unit::Unit(Group& group)
	:airMovement(true), groundMovement(true), waterMovement(true)
{
#ifdef _DEBUG
	std::cout << "Unit()\n";
#endif
	addElement(group);
}


Unit::~Unit()
{
#ifdef _DEBUG
	std::cout << "~Unit()\n";
#endif
}

void Unit::attack(Unit *Un)
{
	srand(time(NULL));
	int att = this->ap;
	int damage = rand() % ((int)(att+att*0.2) - (int)(att - att*0.2) + 1) + (int)(att + att - 0.2);
	Un->setHP(Un->hp - damage);

	if (Un->getHP() <= 0) std::cout << "Unit " << typeid(Un).name() << " is dead\n";
#ifdef _DEBUG
	std::cout << "Unit 2 was damaged in " << damage << " health points\n";
#endif
}

Coord Unit::getCoord()
{
	return Coordinates;
}

int Unit::getHP()
{
	return this->hp;
}

string Unit::getName()
{
	string str = "Name";
	return str;
}

double Unit::getSpeed()
{
	return speed;
}

void Unit::setCoord(Coord C)
{
	this->Coordinates = C;
}

void Unit::setHP(int HP)
{
	this->hp = HP;
}

Machine::Machine(Group& group)
	:Unit(group)
{
#ifdef _DEBUG
	std::cout << "Machine()\n";
#endif
}
Machine::~Machine()
{
#ifdef _DEBUG
	std::cout << "~Machine()\n";
#endif
}

Troop::Troop(Group& group)
	:Unit(group)
{
#ifdef _DEBUG
	std::cout << "Troop()\n";
#endif
}
Troop::~Troop()
{
#ifdef _DEBUG
	std::cout << "~Troop()\n";
#endif
}

void Troop::getOn(Machine *Mach)
{
	//if (this->airMovement == Mach->airMovement)
}

void Troop::getOff(Machine *Mach)
{
}

Tank::Tank(Group& group)
	:Machine(group)
{
	this->airMovement = false;
	this->waterMovement = false;
	//the same
	this->movement.air = false;
	this->movement.water = false;
#ifdef _DEBUG
	std::cout << "Tank()\n";
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

Plane::Plane(Group& group)
	:Machine(group)
{
#ifdef _DEBUG
	std::cout << "Plane()\n";
#endif
}
Plane::~Plane()
{
#ifdef _DEBUG
	std::cout << "~Plane()\n";
#endif
}

void Plane::move(Coord C)
{
#ifdef _DEBUG
	std::cout << "Plane::move()\n";
#endif
}

Ship::Ship(Group& group)
	:Machine(group)
{
	this->airMovement = false;
	this->groundMovement = false;
#ifdef _DEBUG
	std::cout << "Ship()\n";
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

Marine::Marine(Group& group)
	:Troop(group)
{
	this->airMovement = false;
#ifdef _DEBUG
	std::cout << "Marine()\n";
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

Infantry::Infantry(Group& group, int ap, int hp)
	:Troop(group)
{
	this->ap = ap;
	this->hp = hp;
	this->airMovement = false;
#ifdef _DEBUG
	std::cout << "Infantry()\n";
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


Airbourne::Airbourne(Group& group)
	:Troop(group)
{
	waterMovement = false;
#ifdef _DEBUG
	std::cout << "Airbourne()\n";
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



