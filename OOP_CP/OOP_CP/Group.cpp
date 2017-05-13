#include "stdafx.h"
#include "Group.h"
#include <cstdio>
#include <regex>
using namespace std;

Group::Group()
{

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
