#pragma once


#include "includes/CartisianCoordinates/CartisianCoordinates.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class RBot
{
	CartisianCoordinates gridCoordinates;
	char orientation;
public:
	// The initial position must be gotten from the first three inputs of every line of each bot,
	// The upper right coordinates are gotten from the first line of the file (input)
	void setRBot(int xO, int yO, char orientationO)
	{
		orientation = orientationO;
		gridCoordinates.setCartisianCoordinates(xO, yO);
	}
	// returns true if the passed paremeters match with the current coordinates
	bool matchCoordinates(int xO, int yO)
	{
		if (xO == gridCoordinates.x && yO == gridCoordinates.y)
			return true;
		return
			false;
	}
	CartisianCoordinates getCoordinates()
	{
		return gridCoordinates;
	}
	// Keep the same orientation but move on the grid
	void moveForward()
	{
		switch (orientation)
		{
		case 'N':
			gridCoordinates.y++;
			break;
		case 'S':
			gridCoordinates.y--;
			break;
		case 'E':
			gridCoordinates.x++;
			break;
		case 'W':
			gridCoordinates.x--;
			break;
		default:
			cout << "The orientation could only be N,S,E or W" << endl;
		}
	}
	// Keep the same orientation but move on the grid
	void moveBackward()
	{
		switch (orientation)
		{
		case 'N':
			gridCoordinates.y--;
			break;
		case 'S':
			gridCoordinates.y++;
			break;
		case 'E':
			gridCoordinates.x--;
			break;
		case 'W':
			gridCoordinates.x++;
			break;
		default:
			cout << "The orientation could only be N,S,E or W" << endl;
		}
	}
	// stay on the same position of the grid but just change orientation
	void moveLeft()
	{
		switch (orientation)
		{
		case 'N':
			orientation = 'W';
			break;
		case 'S':
			orientation = 'E';
			break;
		case 'E':
			orientation = 'N';
			break;
		case 'W':
			orientation = 'S';
			break;
		default:
			cout << "The orientation could only be N,S,E or W" << endl;
		}
	}
	// stay on the same position of the grid but just change orientation
	void moveRight()
	{
		switch (orientation)
		{
		case 'N':
			orientation = 'E';
			break;
		case 'S':
			orientation = 'W';
			break;
		case 'E':
			orientation = 'S';
			break;
		case 'W':
			orientation = 'N';
			break;
		default:
			cout << "The orientation could only be N,S,E or W" << endl;
		}
	}
	// returns true if the bot has gone out of bounds
	// x*y will be less than zero if any of x or y is negative. Both can't be negative at the same time and this won't overflow the int size since the max number could be 50* 50 = 2500
	bool CheckIfOutOfBound(int xUpperRight, int yUpperRight)
	{
		if (gridCoordinates.x > xUpperRight || gridCoordinates.y > yUpperRight || (gridCoordinates.x* gridCoordinates.y < 0) )
			return true;
		return false;
	}
	void printRBot()
	{
		gridCoordinates.printCartisianCoordinates();
		cout << " " << orientation;
	}
};
