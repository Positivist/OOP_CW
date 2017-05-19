#include "Machine.h"
#include "utils.h"

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
	writeToFile("~Machine()\n");
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

/// <summary>
/// Embarks Tr on Machine and returns true or returns false if Machine doesn't have free seats
/// </summary>
/// <param name="data"></param>
bool Machine::Embark(Troop& Tr) {
	//if Machine has free seat
	if (capacity > (int)passangers.size()) {
		passangers.push_back(&Tr);
		return true;
	}
	else return false;
}

void Machine::showAttributes() {
	std::cout << typeid(*this).name() << " named " << this->name << " has " << this->hp << " health point, " << this->hp << " attack points and capacity " << this->capacity << "\n";
}

void Machine::setCapacity(int newCapacity) {
	this->capacity = newCapacity;
}