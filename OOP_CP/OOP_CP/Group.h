#ifndef GROUP_H
#define GROUP_H

#include "Unit.h"
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Unit;
/// <summary>
/// Unit's group
/// </summary>
class Group
{
	string name;
	vector<Unit*> gr; // Vector of Units
	static vector<string> groupsNames;
public:
	Group();
	Group(string name);
	Unit* find(string name);
	void add(Unit *un); // Add unit to the group
	void show(); // Show all units in the group
	~Group();
};

#endif // !GROUP_H