#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "includes/CartisianCoordinates/CartisianCoordinates.h"
#include "includes/RBot/Rbot.h"
#include "includes/RBotHandler/RBotHandler.h"

using namespace std;


int main() 
{
	ifstream in;
	int tempX, tempY = 0;
	char tempOrientation = '0';
	in.open("inputBot.txt");
	in >> tempX;
	in >> tempY;
	// store the UpperX and UpperY coordinates to be used for the whole file
	RBotHandler rBotHandlerObject(tempX, tempY);
	while (in.good())
	{
		// get the initial X and Y coordinates and Orientation  of the bot being processed
		in >> tempX; in >> tempY; in >> tempOrientation;
		// store the initial X and Y coordinates and Orientation  of the bot being processed
		rBotHandlerObject.setTheBotObject(tempX, tempY, tempOrientation);
		string strInstructionCommands;
		// get the instructions/commands which define movement of the Robot
		in >> strInstructionCommands;
		bool flagOutOfBound = 0;
		for (int i = 0; i < strInstructionCommands.length() && !flagOutOfBound; i++)
		{
			switch (strInstructionCommands[i])
			{
			case 'F':
				// process forward command and if ZERO is returned then we must break this loop
				// false is returned if bot goes out of bounds
				if (!rBotHandlerObject.forwardCommand())
				{
					flagOutOfBound = 1;
				}
				break;
			case 'L':
				rBotHandlerObject.leftCommand();
				break;
			case 'R':
				rBotHandlerObject.rightCommand();
				break;
			default:
				cout << "The Instruction String can contain only F, L or R" << endl;
				break;
			}
		}
		rBotHandlerObject.printPosition();
		if (flagOutOfBound)
			cout << " LOST" << endl;
		else
			cout << endl;
	}
	return 0;
}