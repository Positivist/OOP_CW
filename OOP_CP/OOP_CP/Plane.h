#ifndef PLANE_H
#define PLANE_H

#include "Machine.h"

class Plane :
	public Machine
{
public:
	Plane(string name = "Plane", int attack_points = 40);
	~Plane();
	void move(Coord C);
};

#endif