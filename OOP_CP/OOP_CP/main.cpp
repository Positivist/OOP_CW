#include "Group.h"
#include "Infantry.h"
#include "Marine.h"
#include "Airborne.h"
#include "Plane.h"
#include "Ship.h"
#include "Tank.h"
#include "Unit.h"
#include "Coord.h"

#include <vector>
#include <string>
#include <cstdio>
#include <regex>
#include <fstream>
#include "conio.h"

using namespace std;
char *commands = "1 - Unit attack another unit\n2 - Soldier get on Machine\n3 - Soldier get off Machine\n4 - Move unit\n5 - Add unit to the collection\n6 - Remove unit from the collection\n7 - Delete colletion\n";


void CreateGroup(Group& group)
{
	// Указатели на объекты
	Unit *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL;
	switch (rand() % 4)
	{
	case 0:
	{
		cout << "=================== Objects' Generation 0 =======================" << endl;
		p1 = new Plane("Saab JAS 39 Gripen");
		group.add(p1);
		p2 = new Tank("M7");
		group.add(p2);
		p3 = new Marine("Lewis Burwell");
		group.add(p3);
		p4 = new Infantry("Jack Warden");
		group.add(p4);
		break;
	}
	case 1:
	{
		cout << "=================== Objects' Generation 1 =======================" << endl;
		p1 = new Infantry("John Basilone");
		group.add(p1);
		p2 = new Plane("Boeing F/A-18");
		group.add(p2);
		p3 = new Tank("T30");
		group.add(p3);
		p4 = new Marine("Carlos Norman Hathcock");
		group.add(p4);
		break;
	}
	case 2:
	{
		cout << "=================== Objects' Generation 2 =======================" << endl;
		p1 = new Marine("Daniel Joseph");
		group.add(p1);
		p2 = new Airborne("Richard D. Winters");
		group.add(p2);
		p3 = new Ship("DDG - 92");
		group.add(p3);
		break;
		p4 = new Tank("M551");
		group.add(p4);
		break;
	}
	case 3:
	{
		cout << "=================== Objects' Generation 3 =======================" << endl;
		p1 = new Plane("Focke-Wulf Fw 190 Wurger");
		group.add(p1);
		p2 = new Airborne("Robert G. Cole");
		group.add(p2);
		p3 = new Infantry("Jimi Hendrix");
		group.add(p3);
		p4 = new Infantry("Jimi Hendrix");
		group.add(p4);
		break;
	}
	}
}

void enteringCoordinates()
{
	
}

void enteringUnitAttributes(Unit *un)
{
	cout << "\nDo you want enter attributes of adding Unit? Yes(y), No(n)\n";
	char answer;
	while (!(cin >> answer) || (cin.peek() != '\n') || !(answer == 110 || answer == 121))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Wrong input! Please, try again\n";
	}
	if (answer == 'y') {
		Troop *soldier;
		Machine *machine;
		string name;
		int hp;
		int ap;
		if (soldier = dynamic_cast<Troop*>(un)) {
			cout << "\nEnter Troop's name:\n";
			cin >> name;
			cout << "\nEnter Troop's health points:\n";
			cin >> hp;
			cout << "\nEnter Troop's attack points:\n";
			cin >> ap;
			soldier->setName(name);
			soldier->setHP(hp);
			soldier->setAP(ap);
		}
		else if (machine = dynamic_cast<Machine*>(un)) {
			int cap;
			cout << "\nEnter Machine's name:\n";
			cin >> name;
			cout << "\nEnter Machine's health points:\n";
			cin >> hp;
			cout << "\nEnter Machine's attack points:\n";
			cin >> ap;
			cout << "Enter Machine's capacity:\n";
			cin >> cap;
			machine->setName(name);
			machine->setHP(hp);
			machine->setAP(ap);
			machine->setCapacity(cap);
		}
	}
}

template<typename t> t enterIntOrChar(string inputType) {
	t number;
	while (!(cin >> number) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Wrong input! Enter only " << inputType << endl;
	}
	return number;
}

char enterYorN() {
	char answer;
	while (!(cin >> answer) || (cin.peek() != '\n') || !(answer == 110 || answer == 121))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Wrong input! Please, try again\n";
	}
	return answer;
}

void addingUnit(Group *gr) {
	char answer;
	int unitsQuant;
	cout << "How many units do you want to add?\n";
	unitsQuant = enterIntOrChar<int>("integer");
	for (int i = 0; i < unitsQuant; i++) {
		if (unitsQuant < 1)
			cout << "\nWhat type of unit do you want to add to the collection? Airborne(a), Infantry(i), Marine(m), Plane(p), Ship(s), Tank(t)\n";
		else
			cout << "\nWhat type of " << i + 1 << " unit do you want to add to the collection? Airborne(a), Infantry(i), Marine(m), Plane(p), Ship(s), Tank(t)\n";
		while (!(cin >> answer) || (cin.peek() != '\n') || !(answer == 97 || answer == 105 || answer == 109 || answer == 112 || answer == 115 || answer == 116))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Wrong input! Please, try again\n";
		}
		Unit *un;
		switch (answer) {
		case 'a': {
			un = new Airborne();
			enteringUnitAttributes(un);
			gr->add(un);
			break;
		}
		case 'i': {
			un = new Infantry();
			enteringUnitAttributes(un);
			gr->add(un);
			break;
		}
		case 'm': {
			un = new Marine();
			enteringUnitAttributes(un);
			gr->add(un);
			break;
		}
		case 'p': {
			un = new Plane();
			enteringUnitAttributes(un);
			gr->add(un);
			break;
		}
		case 's': {
			un = new Ship();
			enteringUnitAttributes(un);
			gr->add(un);
			break;
		}
		case 't': {
			un = new Tank();
			enteringUnitAttributes(un);
			gr->add(un);
			break;
		}
		default: {
			cin.clear();
		}
		}
	}
}

void commandprocessing(Group *group, bool *ex) {

	cout << commands;
	int command;
	cin >> command;
	switch (command) {
	case 1:
	{
		int number1, number2;
		cout << "Enter number of attacking unit:\n";
		cin >> number1;
		Unit *un1 = group[0][number1-1];
		if (un1 == nullptr) std::cout << "There is no unit with number " << number1 << " in the group\n";
		else
		{
			cout << "Enter number of defensive unit:\n";
			cin >> number2;
			Unit *un2 = group[0][number1-1];
			if (un2 == nullptr) std::cout << "There is no unit with number " << number2 << " in the group\n";
			else
			{
				un1->attack(un2);
			}
		}
		break;
	}
	case 2:
	{
		int number1, number2;
		cout << "Enter number of embarking unit:\n";
		cin >> number1;
		Unit *un1 = group[0][number1-1];
		if (un1 == nullptr) std::cout << "There is no unit with number " << number1 << " in the group\n";
		else
		{
			Troop *soldier;
			Machine *transport;
			cout << "Enter number of transporting unit:\n";
			cin >> number2;
			Unit *un2 = group[0][number2-1];
			if (un2 == nullptr) std::cout << "There is no unit with number " << number2 << " in the group\n";
			else
			{
				if (soldier = dynamic_cast<Troop*>(un1))
					if (transport = dynamic_cast<Machine*>(un2))
					{

						Machine *mach = soldier->getOn(*transport); //embarking unit is already in the mach and can't get on transporting unit (if not, mach = nullptr) 
						if (mach != nullptr)
						{
							cout << "Embarking unit has already got on the unit with number " << group->findByReference(mach) + 1<< endl;
						}
					}
					else cout << "Selected transporting unit is not Machine\n";
				else cout << "Selected embarking unit is not Troop\n";
			}
		}
		break;
	}
	case 3:
	{
		int number1, number2;
		cout << "Enter disembarking unit:\n";
		cin >> number1;
		Unit *un1 = group[0][number1-1];
		if (un1 == nullptr) std::cout << "There is no unit with number " << number1 << " in the group\n";
		else
		{
			Troop *soldier;
			Machine *transport;
			cout << "Enter transporting unit:\n";
			cin >> number2;
			Unit *un2 = group[0][number2-1];
			if (un2 == nullptr) std::cout << "There is no unit with number " << number2 << " in the group\n";
			else
			{
				if (soldier = dynamic_cast<Troop*>(un1))
					if (transport = dynamic_cast<Machine*>(un2))
						soldier->getOff(*transport);
					else cout << "Selected transporting unit is not Machine\n";
				else cout << "Selected disembarking unit is not Troop\n";
			}
		}
		break;
	}
	case 4:
	{
		int number1;
		cout << "Enter moving unit:\n";
		cin >> number1;
		Unit *unit = group[0][number1-1];
		if (unit == nullptr) std::cout << "There is no unit with number " << number1 << " in the group\n";
		else
		{
			int x, y, z;
			cout << "Enter x coordinate: \n";
			while (!(cin >> x) || (cin.peek() != '\n'))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Error!" << endl;
			}
			cout << "Enter y coordinate: \n";
			cin >> y;
			cout << "Enter z coordinate: \n";
			cin >> z;
			Coord coord{ x,y,z };
			unit->move(coord);
		}
		break;
	}
	case 5: {
		addingUnit(group);
		break;
	}
	case 6: {
		cout << "Enter number of deleting unit\n";
		string answer;
		int number;
		number = enterIntOrChar<int>("integer");
		group->delByIndex(number-1);
		break;
	}
	case 7: {
		delete group;
		cout << "\nGroup has been deleted\n\n";
		*ex = true;
		break;
	}
	default:
	{
		cout << "Invalid input. Enter number of available command.\n";
	}
	}
}


int main()
{
m:
	cout << "Do you want to create Unit's Group? Yes(y), No(n)\n";
	char answer = enterYorN();
	if (answer == 'y') {
	bool ex = false;
	
	Group *gr = new Group();
	cout << "\nDo you want to fill the group by random elements? Yes(y), No(n)\n";
	answer = enterYorN();
	if (answer == 'y') {
		CreateGroup(*gr);
	}
	else {
		addingUnit(gr);
	}
	
		do {
			gr->show();
			commandprocessing(gr, &ex);
			if (ex) goto m;
			cout << "\nPress any key to continue or Esc to exit\n";
		} while ((int)_getch() != 27);
	}
	cout << "\nGoodbye!\n";
	_getch();
	return 0;
}

