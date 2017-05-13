#ifndef GROUP_H
#define GROUP_H

#include "Unit.h"
#include <string>
#include <vector>

using namespace std;
/// <summary>
/// Unit's group
/// </summary>
 class Unit;
class Group
{
	vector<Unit*> gr; // Vector of Units
public:
	Group();
	Unit* find(string name); 
	void add(Unit *un); // Add unit to the group
	void show(); // Show all units in the group
	~Group();
};

#endif // !GROUP_H