#ifndef PLANE_H
#define PLANE_H

#include "Machine.h"

class Plane :
	public Machine
{
public:
	Plane(string name = "Plane", int health_points = 60, int attack_points = 40, int capacity = 4);
	~Plane();
	void move(Coord C);
};

#endif