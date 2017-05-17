#include "Machine.h"
#include <string>
#include <algorithm> 

using namespace std;
Machine::Machine(int capacity)
	:Unit()
{
	this->capacity = capacity;
#ifdef _DEBUG
	std::cout << "Machine()\n";
#endif
}

Machine::~Machine()
{
#ifdef _DEBUG
	std::cout << "~Machine()\n";
#endif
}

void Machine::Disembark(string soldierName) {
	Troop *tr = nullptr;
	if (!passangers.empty()) {
		int i;
		for (i = 0; i != passangers.size(); i++) {
			if (passangers[i] != nullptr) if (passangers[i]->getName() == soldierName) {
				tr = passangers[i];
				break;
			}
		}
		if (tr) {
			passangers.erase(passangers.begin() + i);
		}
		else throw soldierName + " haven't been disembarked";
	}
}

bool Machine::Embark(Troop& Tr) {
	//if Machine has free seat
	if (capacity > passangers.size()) {
		passangers.push_back(&Tr);
		return true;
	}
	else return false;
}