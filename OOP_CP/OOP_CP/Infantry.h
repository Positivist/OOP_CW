#ifndef INFANTRY_H
#define INFANTRY_H

#include "Troop.h"

class Infantry :
	public Troop
{
public:
	Infantry(string name = "Infantry", int health_points = 60, int attack_points = 20);
	~Infantry();
	void move(Coord C);
};

#endif