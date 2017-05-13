#include "Group.h"
#include "Infantry.h"
#include "Marine.h"
#include "Airbourne.h"
#include "Plane.h"
#include "Ship.h"
#include "Tank.h"
#include "Unit.h"

#include <vector>
#include <string>
#include <cstdio>
#include <regex>
#include "conio.h"
using namespace std;
//char *commands = "Unit attack another unit: Name_of_attacking_unit attack name_of_defending_unit\nSoldier get on Machine: Name_of_soldier get on name_of_machine\nSoldier get off Machine : Name_of_soldier get off name_of_machine\nMove unit : Unit's_name move coordinate_x coordinate_y\n";
char *commands = "1 - Unit attack another unit: Name_of_attacking_unit attack name_of_defending_unit\n2 - Soldier get on Machine: Name_of_soldier get on name_of_machine\n3 - Soldier get off Machine : Name_of_soldier get off name_of_machine\n4 - Move unit : Unit's_name move coordinate_x coordinate_y\n";

void CreateGroup(Group& group)
{
	// Указатели на объекты
	Unit *p1 = NULL, *p2 = NULL, *p3 = NULL, *p4 = NULL;
	switch (rand() % 4)
	{
	case 0:
	{
		cout << "=================== Objects' Generation 0 =======================" << endl;
		Coord point10(rand() / 2 - 100, rand() / 5);
		p1 = new Plane(group, "Plane1");
		// Cоздание окружности и помещение ее в список
		Coord cntr0(rand() / 2, rand() / 2);
		p2 = new Tank(group);
		break;
	}
	case 1:
	{
		cout << "=================== Objects' Generation 1 =======================" << endl;
		Coord point11(rand() / 2 - 200, rand() / 5);
		p1 = new Infantry(group);
		p1 = new Plane(group);
		p1 = new Tank(group);
		break;
	}
	case 2:
	{
		cout << "=================== Objects' Generation 2 =======================" << endl;
		Coord cntr2(rand() / 2, rand() / 2);
		p1 = new Marine(group);
		Coord cntr21(rand() / 2, rand() / 2);
		p2 = new Airbourne(group);
		Coord point22(rand() / 2 + 200, rand() / 2);
		p3 = new Ship(group);
		break;
	}
	case 3:
	{
		cout << "=================== Objects' Generation 3 =======================" << endl;
		// Cоздание окружности и помещение ее в список
		Coord cntr3(rand() / 2, rand() / 2);
		p1 = new Plane(group, "plane2");
		cout << p1->getName();
		// Cоздание окружности и помещение ее в список
		Coord cntr31(rand() / 2, rand() / 2);
		p2 = new Airbourne(group);
		break;
	}
	}
	// Просмотр характеристик объекта 
	group.show();
}

void commandprocessing(Group *group) {
	
	cout << commands;
	int command; // reg exr string
	std::cmatch result;
	//Первая буква не цифра*_пробел_attack|get on|get off|move
	//regular exrpession std::regex regcommand("^a-z[\w+]"" ""attack| get on| get off|move"" ""()");
	cin >> command;
	//command = "airbourne get on plane";
	//regular exrpession if (std::regex_match(command.c_str(), result, regcommand))
	//regular exrpession 	std::cout << "true\n";
	switch (command) {
	case 1: 
	{
		string name1, name2;
		cout << "Enter attacking unit:\n";
		cin >> name1;
		Unit *un1 = group->find(name1);
		if (un1 == nullptr) std::cout << "there is no unit with name " << name1 << " in the group";
		else
		{
			cout << "Enter defensive unit:\n";
			cin >> name2;
			Unit *un2 = group->find(name2);
			if (un2 == nullptr) std::cout << "there is no unit with name " << name2 << " in the group";
			else
			{
				un1->attack(un2);
			}
		}
		break;
	}
	case 2:
	{
		string name1, name2;
		cout << "Enter embarking unit:\n";
		cin >> name1;
		Unit *un1 = group->find(name1);
		if (un1 == nullptr) std::cout << "there is no unit with name " << name1 << " in the group";
		else
		{
			Troop *soldier;
			Machine *transport;
			cout << "Enter transporting unit:\n";
			cin >> name2;
			Unit *un2 = group->find(name2);
			if (un2 == nullptr) std::cout << "there is no unit with name " << name2 << " in the group";
			else
			{
				if (soldier = dynamic_cast<Troop*>(un1))
					if (transport = dynamic_cast<Machine*>(un2))
						soldier->getOn(*transport);
			}
		}
	}
	case 3:
	{
		string name1, name2;
		cout << "Enter disembarking unit:\n";
		cin >> name1;
		Unit *un1 = group->find(name1);
		if (un1 == nullptr) std::cout << "there is no unit with name " << name1 << " in the group";
		else
		{
			Troop *soldier;
			Machine *transport;
			cout << "Enter transporting unit:\n";
			cin >> name2;
			Unit *un2 = group->find(name2);
			if (un2 == nullptr) std::cout << "there is no unit with name " << name2 << " in the group";
			else
			{
				if (soldier = dynamic_cast<Troop*>(un1))
					if (transport = dynamic_cast<Machine*>(un2))
						soldier->getOff(*transport);
			}
		}
	}
	case 4:
	{
		string name1, name2;
		cout << "Enter moving unit:\n";
		cin >> name1;
		Unit *un1 = group->find(name1);
		if (un1 == nullptr) std::cout << "there is no unit with name " << name1 << " in the group";
		else
		{
			Unit *unit;
			Machine *transport;
			cout << "Enter coordinates to move (e.g. 13;21;0):\n";

			}
		}
	}

	/*reg expr string name1, name2;
	cin >> name1;
	Unit *un1 = group->find(name1);
	if (un1 == nullptr) std::cout << "there is no unit with name " << name1 << " in the group";
	else
	{
		cin >> name2;
		Unit *un2 = group->find(name2);
		if (un2 == nullptr) std::cout << "there is no unit with name " << name2 << " in the group";
		else {
			if (command == "attack") cout << "attcacked";
			else if (command == "get_on") cout << "gotten on";
			else cout << "Wrong command";
		}
		delete un2;
	}
	delete un1;*/

}


int main()
{
	char *command;
	FILE *stream;
	// printEverywhere(string message, vector<ostream> oses);
	// printEverywhere("ALERT", {cout, fout});
	//freopen_s(&stream, "log.txt", "w", stdout);
	Group *gr = new Group();
	CreateGroup(*gr);
	do {
		Unit *pu1;
		Unit *pu2;
		
		Coord Cc(3, 3, 5);
		//pu1 = gr->find("Plane1");
		commandprocessing(gr);
		delete gr;
	} while ((int)_getch() != 27);
    return 0;
}

