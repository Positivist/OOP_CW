#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include <vector>

#include "Coord.h"
#include "Movement.h"
using namespace std;


/// <summary>
/// Describes possobility of motion in different environments
/// </summary>
/// <param name="data"></param>

class Unit
{
protected:
	int ap; // attack points
	Coord Coordinates;
	int hp; // health points
	string name;
	Movement movement;
public:
	Unit();
	virtual ~Unit();
	void attack(Unit *Un);
	Coord getCoord();
	int getHP();
	Movement getMovement();
	string getName();
	virtual void move(Coord C) = 0;
	void setAP(int AP);
	void setCoord(Coord C);
	void setHP(int HP);
	void setName(string newName);
	virtual void showAttributes() = 0;
};
#endif