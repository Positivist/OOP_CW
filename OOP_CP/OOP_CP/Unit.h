#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>
#include <vector>
#include "Group.h"
//!!!! group lishhnya
using namespace std;

struct Coord {
	double x;
	double y;
	double z;
	Coord(int x = 0, int y = 0, int z = 0)
		:x(x), y(y), z(z)
	{
	}
};
/// <summary>
/// Describes possobility of motion in different environments
/// </summary>
/// <param name="data"></param>
struct Movement {
	bool air;
	bool ground;
	bool water;
	bool operator==(Movement &M) {
		if (this->air == M.air && this->ground == M.ground && this->water == M.water) return true;
		else return false;
	}
	Movement() {
		this->air = true;
		this->ground = true;
		this->water = true;
	}
};
class Group;
class Unit
{
protected:
	int ap; // attack points
	Coord Coordinates;
	int hp; // health points
	string name;
	Movement movement;
	//double size;
	double speed;
public:
	Unit();
	virtual ~Unit();
	void attack(Unit *Un);
	Coord getCoord();
	int getHP();
	Movement getMovement();
	string getName();
	double getSpeed(); //or int
	virtual void move(Coord C) = 0;
	void setCoord(Coord C);
	void setHP(int HP);
};
#endif