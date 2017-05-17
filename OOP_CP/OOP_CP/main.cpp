#include "Group.h"
#include "Infantry.h"
#include "Marine.h"
#include "Airborne.h"
#include "Plane.h"
#include "Ship.h"
#include "Tank.h"
#include "Unit.h"

#include <vector>
#include <string>
#include <cstdio>
#include <regex>
#include <fstream>
#include "conio.h"

using namespace std;
//char *commands = "Unit attack another unit: Name_of_attacking_unit attack name_of_defending_unit\nSoldier get on Machine: Name_of_soldier get on name_of_machine\nSoldier get off Machine : Name_of_soldier get off name_of_machine\nMove unit : Unit's_name move coordinate_x coordinate_y\n";
char *commands = "1 - Unit attack another unit: Name_of_attacking_unit attack name_of_defending_unit\n2 - Soldier get on Machine: Name_of_soldier get on name_of_machine\n3 - Soldier get off Machine : Name_of_soldier get off name_of_machine\n4 - Move unit : Unit's_name move coordinate_x coordinate_y\n";

ofstream logFile;

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
		p1 = new Plane("Plane1");
		group.add(p1);
		Coord cntr0(rand() / 2, rand() / 2);
		p2 = new Tank();
		group.add(p2);
		break;
	}
	case 1:
	{
		cout << "=================== Objects' Generation 1 =======================" << endl;
		Coord point11(rand() / 2 - 200, rand() / 5);
		p1 = new Infantry("1");
		group.add(p1);
		p2 = new Plane("2");
		group.add(p2);
		p3 = new Tank("3");
		group.add(p3);
		break;
	}
	case 2:
	{
		cout << "=================== Objects' Generation 2 =======================" << endl;
		Coord cntr2(rand() / 2, rand() / 2);
		p1 = new Marine();
		group.add(p1);
		Coord cntr21(rand() / 2, rand() / 2);
		p2 = new Airborne();
		group.add(p2);
		Coord point22(rand() / 2 + 200, rand() / 2);
		p3 = new Ship();
		group.add(p3);
		break;
	}
	case 3:
	{
		cout << "=================== Objects' Generation 3 =======================" << endl;
		// Cоздание окружности и помещение ее в список
		Coord cntr3(rand() / 2, rand() / 2);
		p1 = new Plane("plane2");
		group.add(p1);
		cout << p1->getName();
		// Cоздание окружности и помещение ее в список
		Coord cntr31(rand() / 2, rand() / 2);
		p2 = new Airborne();
		group.add(p2);
		break;
	}
	}
	// Просмотр характеристик объекта 
	group.show();
}

void enteringCoordinates()
{

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
		if (un1 == nullptr) std::cout << "There is no unit with name " << name1 << " in the group\n";
		else
		{
			cout << "Enter defensive unit:\n";
			cin >> name2;
			Unit *un2 = group->find(name2);
			if (un2 == nullptr) std::cout << "There is no unit with name " << name2 << " in the group\n";
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
		break;
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
		break;
	}
	case 4:
	{
		string name1;
		cout << "Enter moving unit:\n";
		cin >> name1;
		Unit *unit = group->find(name1);
		if (unit == nullptr) std::cout << "there is no unit with name " << name1 << " in the group";
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
	default:
	{
		cout << "Invalid input. Enter number of available command.\n";
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
void printEverywhere(string message, ofstream& fout) {
	cout << message;
	fout << message;
}
int main()
{
	std::ofstream fout;
	logFile.open("D:/log.txt");
	if (fout.is_open()) {
		cout << "Log file doesn't exist";
	}
	fout << "13123" << endl;
	//printEverywhere("Message", {cout, fout});
	fout.close();
	//printEverywhere(string message, vector<ostream> oses);
	//printEverywhere("ALERT", {cout, fout});
	//freopen_s(&stream, "log.txt", "w", stdout);

	Group *gr = new Group();
	char answer;
	cout << "Do you want to fill the group by random elements? Yes(y)\n";
	cin >> answer;
	if (answer == 'y') {
		CreateGroup(*gr);
	}
	else {
		int unitsQuant;
		cout << "How many units do you want to add?\n";
		unitsQuant = enterIntOrChar<int>("integer");
		for (int i = 0; i < unitsQuant; i++) {
			if (unitsQuant < 1)
				cout << "What type of unit do you want to add to the collection? Airborne(a), Infantry(i), Marine(m), Plane(p), Ship(s), Tank(t)\n";
			else 
				cout << "What type of "<< i + 1 <<" unit do you want to add to the collection? Airborne(a), Infantry(i), Marine(m), Plane(p), Ship(s), Tank(t)\n";
			while (!(cin >> answer) || (cin.peek() != '\n') || !(answer == 97 || answer == 105 || answer == 109 || answer == 112 || answer == 115 || answer == 116))
			{
				cin.clear();
				while (cin.get() != '\n');
				cout << "Wrong input! Please, try again" << endl;
			}
			Unit *un;
			switch (answer) {
			case 'a': {
				un = new Airborne();
				gr->add(un);
				break;
			}
			case 'i': {
				un = new Infantry();
				gr->add(un);
				break;
			}
			case 'm': {
				un = new Marine();
				gr->add(un);
				break;
			}
			case 'p': {
				un = new Plane();
				gr->add(un);
				break;
			}
			case 's': {
				un = new Ship();
				gr->add(un);
				break;
			}
			case 't': {
				un = new Tank();
				gr->add(un);
				break;
			}
			default: {
				cin.clear();
			}
		}
		
		}
	}
	
	do {
		Coord Cc(3, 3, 5);
		commandprocessing(gr);
	} while ((int)_getch() != 27);
	delete gr;
	return 0;
}

