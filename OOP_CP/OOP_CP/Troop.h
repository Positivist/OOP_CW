#ifndef TROOP_H
#define TROOP_H

#include "Unit.h"
#include "Machine.h"

class Machine;
class Troop :
	public Unit
{
protected:
	string machineName;
	Machine *Trans;
public:
	Troop();
	~Troop();
	/// <summary>
	/// It's friend to the machine and realize the possibility of get on the machine. 
	/// </summary>
	/// <param name="data">Pointer to the machine you need to get on</param>
	void getOn(Machine &Mach);
	/// <summary>
	/// Realize the possibility of get off the machine 
	/// </summary>
	/// <param name="data">Pointer to the machine you need to get off</param>
	void getOff(Machine &Mach);
};

#endif