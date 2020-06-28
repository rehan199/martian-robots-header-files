#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct CartisianCoordinates
{
	int x;
	int y;
	void setCartisianCoordinates(int xO, int yO)
	{
		x = xO;
		y = yO;
	}
	void printCartisianCoordinates()
	{
		cout << x << " " << y;
	}
};
