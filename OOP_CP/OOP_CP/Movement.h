#ifndef MOVEMENT_H
#define MOVEMENT_H

struct Movement {
	bool air;
	bool ground;
	bool water;
	bool operator==(Movement &M) {
		if (this->air == M.air && this->water == M.water) return true;
		else return false;
	}
	Movement() {
		this->air = true;
		this->ground = true;
		this->water = true;
	}
};

#endif