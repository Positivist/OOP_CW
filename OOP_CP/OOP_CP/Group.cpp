#include "Group.h"
#include "utils.h"

#include <cstdio>
#include <string>
#include <iterator> 
using namespace std;

//vector<string> Group::groupsNames;
Group::Group(string name) {
	if (std::find(groupsNames.begin(), groupsNames.end(), name) != groupsNames.end()) {
		this->name = name;
		groupsNames.push_back(name);
	}
	else {
		throw "Group with that name is already exist";
	}
	cout << "Group(string name)\n";
};

Group::Group() {
#ifdef _DEBUG
	std::cout << "Group()\n";
#endif
	this->name = to_string(groupsNames.size()).append("group");
	groupsNames.push_back(this->name);
	writeToFile("Group()\n");
};

Unit* Group::operator[](int index)
{
	if (index < 0 || index >= (int)gr.size())
	{
		return nullptr;
		//throw std::string("Invalid unit's number\n");
	}
	return gr[index];
}

Unit* Group::find(string name) {
	Unit *un = nullptr;
	if (!gr.empty()) {
		for (int i = 0; i != gr.size(); i++) {
			if (gr[i] != nullptr) if (gr[i]->getName() == name) {
				un = gr[i];
				break;
			}
		}
	}
	else cout << "Collection is empty";
	return un;
}

void Group::add(Unit *un) {
	gr.push_back(un);
}

bool Group::delByIndex(int index) {
	if (index < 0 || index >= (int)gr.size()) {
		return false;
	}
	delete *(gr.begin() + index);
	gr.erase(gr.begin() + index);
	return true;
}

int Group::findByReference(Unit *un) {
	return std::distance(gr.begin(), std::find(gr.begin(), gr.end(), un));
}


void Group::show() {
	cout << "\n\n======================= Collection contains =======================\n";
	if (this->gr.empty()) {
		cout << "nothing\n";
	}
	else {
		//cout << ":\n";
		int i = 0;
		for_each(gr.begin(), gr.end(), [&](Unit* u) {
			cout << "Unit number " << ++i << " " << typeid(*u).name() << " named " << u->getName() << "\n";
		});
	}
	cout << "===================================================================\n";
}

Group::~Group()
{
#ifdef _DEBUG
	std::cout << "~Group()\n";
#endif
	for_each(gr.begin(), gr.end(), [](Unit* u) {
		delete u;
	});
	writeToFile("~Group()\n");
}
