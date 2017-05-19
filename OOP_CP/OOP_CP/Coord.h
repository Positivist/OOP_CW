#ifndef COORD_H
#define COORD_H
struct Coord {
	double x;
	double y;
	double z;
	Coord(int x = 0, int y = 0, int z = 0)
		:x(x), y(y), z(z)
	{
	}
};

#endif