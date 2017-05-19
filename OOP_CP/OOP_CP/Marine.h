#ifndef MARINE_H
#define MARINE_H
#include "Troop.h"

class Marine :
	public Troop
{
public:
	Marine(string name = "Marine", int health_points = 60, int attack_points = 20);
	~Marine();
	void move(Coord C);
};

#endif