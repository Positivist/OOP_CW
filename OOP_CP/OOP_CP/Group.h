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
	vector<string> groupsNames;
public:
	Group();
	Group(string name);
	Unit* operator[](int index);
	Unit* find(string name);
	int findByReference(Unit *un);
	void add(Unit *un);
	/// <summary>
	/// Deleting unit by index in the colletion. If index is okey it will returns true, otherwise it will returns false
	/// </summary>
	/// <param name="index">Index in the collection (0..size-1)</param>
	bool delByIndex(int index);
	void show(); // Show all units in the group
	~Group();
};

#endif // !GROUP_H