#ifndef TANK_H
#define TANK_H
#include "Machine.h"

class Tank :
	public Machine
{
public:
	Tank(string name = "Tank", int health_points = 300, int attack_points = 40, int capacity = 4);
	~Tank();
	void move(Coord C);
};

#endif