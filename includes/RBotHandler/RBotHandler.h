#pragma once

#include "includes/CartisianCoordinates/CartisianCoordinates.h"
#include "includes/RBot/Rbot.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class RBotHandler
{
	// Upper x cordinate
	int xUpperRight;
	// Upper y cordinate
	int yUpperRight;
	RBot theBotObject;
	// The SCENT needs only the coordinates, orientation doesn't matter.
	vector<CartisianCoordinates> scentListOfLostBot;
public:
	RBotHandler(int x, int y)
	{
		xUpperRight = x;
		yUpperRight = y;
	}
	void setTheBotObject(int xO, int yO, char orientationO)
	{
		theBotObject.setRBot(xO, yO, orientationO);
	}
	// returns true if the current coordinates match with any of the ones in 'scentListOfLostBot'.
	bool CheckIfScentFromLostList()
	{
		for (vector<CartisianCoordinates>::iterator it = scentListOfLostBot.begin(); it != scentListOfLostBot.end(); ++it)
		{
			if (theBotObject.matchCoordinates(it->x, it->y))
				return true;
		}
		return false;
	}
	//
	bool forwardCommand()
	{
		theBotObject.moveForward();
		// CheckIfOutOfBound returns true if bot is out of bound
		if (theBotObject.CheckIfOutOfBound(xUpperRight, yUpperRight))
		{
			// move back because either instruction we processed has to be ignored or we've to print the previous position with the word 'LOST'
			theBotObject.moveBackward();
			// if SCENT not found, means it is the first bot who has fallen off-grid
			if (!CheckIfScentFromLostList())
			{
				// save the SCENT of the bot in the list
				scentListOfLostBot.push_back(theBotObject.getCoordinates());
				return false; // stop parsing the input string, print that bot is lost, move to next line (other bot)
			}
			// now it is the point from where another bot also moved out of bounds. So, just ignore this instruction
			return true;
		}
		return true;
	}
	void leftCommand()
	{
		theBotObject.moveLeft();
	}
	void rightCommand()
	{
		theBotObject.moveRight();
	}
	void printPosition()
	{
		theBotObject.printRBot();
	}
};
