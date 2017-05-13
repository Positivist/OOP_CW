#ifndef AIRBOURNE_H
#define AIRBOURNE_H
#include "Troop.h"
class Airbourne :
	public Troop
{
public:
	Airbourne(Group& group, string name = "Airbourne", int attack_points = 20);
	~Airbourne();
	void move(Coord C);
};

#endif