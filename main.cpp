#include "stdafx.h"
#include "Unit.h"
#include <vector>
#include <string>
using namespace std;

void Show(Group& group)
{
	Unit *current = group.getFirst();
#ifdef _DEBUG	
	string TT = typeid(current).name();
	cout << "====== Show " << TT << "======" << endl;
#endif

	// Show names of all units
	while (current != 0)
	{
		current->getName();
		current = current->next;
	}
}

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
		p1 = new Plane(group);
		// Cоздание окружности и помещение ее в список
		Coord cntr0(rand() / 2, rand() / 2);
		p2 = new Tank(group);
		break;
	}
	case 1:
	{
		cout << "=================== Objects' Generation 1 =======================" << endl;
		Coord point11(rand() / 2 - 200, rand() / 5);
		p1 = new Infantry(group, 20, 100);
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
		p1 = new Plane(group);
		// Cоздание окружности и помещение ее в список
		Coord cntr31(rand() / 2, rand() / 2);
		p2 = new Airbourne(group);
		break;
	}
	}
	/*
	switch (rand() % 4)
	{
	case 0:
	{
		cout << "=================== Генерация объектов 0 =======================" << endl;
		// Cоздание линии (отрезка) и помещение ее в список
		Coord point10(rand() / 2 - 100, rand() / 5);
		p1 = new Plane(group);
		// Cоздание окружности и помещение ее в список
		Coord cntr0(rand() / 2, rand() / 2);
		p2 = new Circle(group, cntr0, rand() / 5, s[rand() % 7], rand() % 5 + 1);
		break;
	}
	case 1:
	{
		cout << "=================== Генерация объектов 1 =======================" << endl;
		// Cоздание линии (отрезка) и помещение ее в список
		Coord point11(rand() / 2 - 200, rand() / 5);
		Coord point21(rand() / 2 + 100, rand() / 2);
		p1 = new Line(group, point11, point21, s[rand() % 7], rand() % 4 + 1);
		break;
	}
	case 2:
	{
		cout << "=================== Генерация объектов 2 =======================" << endl;
		// Cоздание окружности и помещение ее в список
		Coord cntr2(rand() / 2, rand() / 2);
		p1 = new Circle(group, cntr2, rand() / 5, s[rand() % 7], rand() % 3 + 1);
		// Cоздание окружности и помещение ее в список
		Coord cntr21(rand() / 2, rand() / 2);
		p2 = new Circle(group, cntr21, rand() / 5, s[rand() % 7], rand() % 3 + 1);
		// Cоздание линии (отрезка) и помещение ее в список
		Coord point12(rand() / 2 - 300, rand() / 5);
		Coord point22(rand() / 2 + 200, rand() / 2);
		p3 = new Line(group, point12, point22, s[rand() % 7], rand() % 5 + 1);
		break;
	}
	case 3:
	{
		cout << "=================== Генерация объектов 3 =======================" << endl;
		// Cоздание окружности и помещение ее в список
		Coord cntr3(rand() / 2, rand() / 2);
		p1 = new Circle(group, cntr3, rand() / 5, s[rand() % 7], rand() % 5 + 1);
		// Cоздание окружности и помещение ее в список
		Coord cntr31(rand() / 2, rand() / 2);
		p2 = new Circle(group, cntr31, rand() / 5, s[rand() % 7], rand() % 5 + 1);
		// Cоздание линии (отрезка) и помещение ее в список
		Coord point13(rand() / 2 - 400, rand() / 5);
		Coord point23(rand() / 2 + 300, rand() / 2);
		p3 = new Line(group, point13, point23, s[rand() % 7], rand() % 5 + 1);
		// Cоздание окружности и помещение ее в список
		Coord cntr32(rand() / 2, rand() / 2);
		p4 = new Circle(group, cntr32, rand() / 5, s[rand() % 7], rand() % 5 + 1);
		break;
	}
	}
	*/
	// Просмотр характеристик объекта 
	Show(group);
}


int main()
{
	do {
		Unit *pu1;
		Unit *pu2;
		
		Group *gr = new Group();
		CreateGroup(*gr);
		Infantry *I1 = new Infantry(*gr,100, 40);
		//Infantry *I2 = new Infantry(30, 90);
		pu1 = I1;
		//pu1->attack(I2);
		Coord Cc(3, 3, 5);
		pu1->move(Cc);
	} while ((int)_gettch() != 27);
    return 0;
}

