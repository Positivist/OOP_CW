#include "Troop.h"

Troop::Troop()
	:Unit()
{
#ifdef _DEBUG
	std::cout << "Troop()\n";
#endif
}
Troop::~Troop()
{
#ifdef _DEBUG
	std::cout << "~Troop()\n";
#endif
}
//????????????????????????
void Troop::getOn(Machine &Mach)
{
	if (Mach.getMovement() == this->movement)
	{
		if (Mach.Embark(*this))
		{
			std::cout << "Unit with name" << this->name << "got on the machine with name " << Mach.getName() << endl;
			Trans = &Mach;
		}
	}
	else 
	{
#ifdef _DEBUG
		std::cout << "This unit can't get on desired machine\n";
#endif
	}
}

void Troop::getOff(Machine &Mach)
{
	if (this->Trans == NULL) cout << "This unit is already outside\n";
	else {
		string trName = Trans->getName();
		Trans = NULL;
		cout << "This unit successfully get off the machine with name " << trName << endl;
	}
}