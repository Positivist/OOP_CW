#include "Group.h"
#include <cstdio>
#include <string>
#include <regex>
using namespace std;

vector<string> Group::groupsNames;
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
	this->name = to_string(groupsNames.size()).append("group");
	groupsNames.push_back(this->name);
	cout << "Group()\n";
};

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

void Group::show() {
	for_each(gr.begin(), gr.end(), [&](Unit* u) {
		cout << u->getName() << "\n";
	});
}

Group::~Group()
{
	for_each(gr.begin(), gr.end(), [](Unit* u) {
		delete u;
	});
}
