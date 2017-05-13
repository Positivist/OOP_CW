#ifndef SHIP_H
#define SHIP_H
#include "Machine.h"

class Ship :
	public Machine
{
public:
	Ship(Group& group, string name = "Ship", int attack_points = 40);
	~Ship();
	void move(Coord C);
};

#endif