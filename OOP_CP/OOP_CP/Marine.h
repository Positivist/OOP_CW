#ifndef MARINE_H
#define MARINE_H
#include "Troop.h"

class Marine :
	public Troop
{
public:
	Marine(Group& group, string name = "Marine", int attack_points = 20);
	~Marine();
	void move(Coord C);
};

#endif