#ifndef AIRBORNE_H
#define AIRBORNE_H
#include "Troop.h"
class Airborne :
	public Troop
{
public:
	Airborne(string name = "Airborne", int health_points = 60, int attack_points = 20);
	~Airborne();
	void move(Coord C);
};

#endif