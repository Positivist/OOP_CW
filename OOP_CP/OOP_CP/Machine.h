#ifndef MACHINE_H
#define MACHINE_H

#include "Unit.h"
#include "Troop.h"
#include "vector"

class Troop;
class Machine :
	public Unit
{
protected:
	int capacity;
	vector<Troop*> passangers;
public:
	Machine(int capacity = 4);
	virtual ~Machine();
	void Disembark(string soldierName);
	bool Embark(Troop& Tr);
	void showAttributes();
	void setCapacity(int newCapacity);
};

#endif