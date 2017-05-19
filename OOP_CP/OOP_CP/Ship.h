#ifndef SHIP_H
#define SHIP_H
#include "Machine.h"

class Ship :
	public Machine
{
public:
	Ship(string name = "Ship", int health_points = 300, int attack_points = 40, int capacity = 4);
	~Ship();
	void move(Coord C);
};

#endif