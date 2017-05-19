#include "Troop.h"
#include "utils.h"

Troop::Troop()
	:Unit()
{
#ifdef _DEBUG
	std::cout << "Troop()\n";
#endif
	writeToFile("Troop()\n");
}
Troop::~Troop()
{
#ifdef _DEBUG
	std::cout << "~Troop()\n";
#endif
	writeToFile("~Troop()\n");
}
//????????????????????????
Machine* Troop::getOn(Machine &mach)
{
	if (Trans == nullptr)
	{
		if (mach.getMovement() == this->movement)
		{
			if (mach.Embark(*this))
			{
				std::cout << "Unit with name " << this->name << " got on the machine with name " << mach.getName() << endl;
				Trans = &mach;
			}
			else cout << "This machine doesn't have free seats\n";
		}
		else
		{
			std::cout << "This unit can't get on desired machine because of transportation rules\n";
		}
		return nullptr;
	}
	else return Trans;
}

void Troop::getOff(Machine &Mach)
{
	if (this->Trans == nullptr) cout << "This unit is already outside\n";
	else {
		string trName = Trans->getName();
		Trans = nullptr;
		cout << "This unit successfully get off the machine with name " << trName << endl;
	}
}

void Troop::showAttributes() {
	std::cout << typeid(*this).name() << " named " << this->name << " has " << this->hp << " and " << this->hp << " attack points\n";
}