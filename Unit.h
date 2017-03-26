#pragma once
#include <iostream>
#include <string>
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
class Unit;
//--------------------Unit's Group------------------------------------------
class Group
{
	Unit *first; // pointer on the group
public:
	Group() { first = 0; }
	Unit* getFirst() { return first; }
	void add(Unit* object);
};

class Unit
{
protected:

	void addElement(Group& group)
	{
		group.add(this);
	}
	bool airMovement;
	int ap; // attack points
	Coord Coordinates;
	bool groundMovement;
	int hp; // health points
	string name;
	Movement movement;
	//double size;
	double speed;
	bool waterMovement;
public:
	Unit *next;
	Unit(Group& group);
	virtual ~Unit();
	void attack(Unit *Un);
	Coord getCoord();
	int getHP();
	string getName();
	double getSpeed(); //or int
	virtual void move(Coord C) = 0;
	void setCoord(Coord C);
	void setHP(int HP);
};

class Machine: public Unit{
protected:
	int capacity;
public:
	Machine(Group& group);
	~Machine();
};

class Troop: public Unit {
protected:
	Machine *Trans;
public:
	Troop(Group& group);
	~Troop();
	void getOn(Machine *Mach);
	void getOff(Machine *Mach);
};

class Tank: public Machine {
public:
	Tank(Group& group);
	~Tank();
	void move(Coord C);
};

class Plane: public Machine {
public:
	Plane(Group& group);
	~Plane();
	void move(Coord C);
};

class Ship: public Machine {
public:
	Ship(Group& group);
	~Ship();
	void move(Coord C);
};

class Marine: public Troop {
public:
	Marine(Group& group);
	~Marine();
	void move(Coord C);
};

class Infantry: public Troop {
public:
	Infantry(Group& group, int ap, int hp);
	~Infantry();
	void move(Coord C);
};

class Airbourne: public Troop {
public:
	Airbourne(Group& group);
	~Airbourne();
	void move(Coord C);
};