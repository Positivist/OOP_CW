#include "Unit.h"

#include "time.h"
#include <typeinfo.h>  
#include <string>
#include <list>
#include <vector>

using namespace std;

Unit::Unit(Group& group)
{
#ifdef _DEBUG
	std::cout << "Unit()\n";
#endif
	group.add(this);
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
	int damage = (rand() % (int)(((att+att*0.2) - (att - att*0.2) + 1) + (att + att - 0.02)));
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

Movement Unit::getMovement() {
	return this->movement;
}

string Unit::getName()
{
	return this->name;
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