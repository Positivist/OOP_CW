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
	/// Realizes the possibility of get on the machine. If troop is already in the Machine it will return pointer to that Machine, otherwise it will return nullptr  
	/// </summary>
	/// <param name="data">Pointer to the machine you need to get on</param>
	Machine* getOn(Machine &mach);
	/// <summary>
	/// Realizes the possibility of get off the machine 
	/// </summary>
	/// <param name="data">Pointer to the machine you need to get off</param>
	void getOff(Machine &mach);
	void showAttributes();
};

#endif