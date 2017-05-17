#ifndef TANK_H
#define TANK_H
#include "Machine.h"

class Tank :
	public Machine
{
public:
	Tank(string name = "Tank", int attack_points = 40);
	~Tank();
	void move(Coord C);
};

#endif