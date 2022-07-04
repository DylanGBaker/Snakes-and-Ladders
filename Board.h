// Student Number: 2093671

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

using namespace std;

void MakeBoard(vector<int>& Board, vector<int>& StoreSnakePos, vector<int>& StoreLadderPos, ifstream& UsrInputFile, ofstream& outfile, string UsrInput, string StoreUsrInput, int& numofgames)
{
	//Declaring and initialising variables
	int lineNum = 0;
	int BoardSize = 0;
	int ObjectFootPos = 0, ObjectHeadPos = 0;
	string BoardSizeString;

	while (getline(UsrInputFile, UsrInput))
	{
		ObjectFootPos = 0;
		ObjectHeadPos = 0;

		if (lineNum == 0) //Checking if it is the first line of the input file with the board size, how many players etc...
		{
			StoreUsrInput = UsrInput; //Storing the boardsize from the input file so that I can convert it to an integer.

			//The board size has a minimum value of 100 and a max value of 400. So the value of the board size will always be from index 0 -> 3. Thats all i need from the first line for the board.
			BoardSizeString = StoreUsrInput.substr(0, 3);
			BoardSize = stoi(BoardSizeString);

			StoreUsrInput.erase(3, 2);
			outfile << StoreUsrInput << endl;

			for (int i = 1; i <= BoardSize; i++)
			{
				Board.push_back(i);
			}

			lineNum++;
		}
		else {
			stringstream ss(UsrInput);

			if (UsrInput[0] == 'L') //Checking if the input is for the ladder position.
			{
				getline(ss, UsrInput, 'L');
				getline(ss, UsrInput, '-');
				ObjectFootPos = stoi(UsrInput);
				getline(ss, UsrInput, '\t');
				ObjectHeadPos = stoi(UsrInput);

				StoreLadderPos.push_back(ObjectFootPos); //Storing the beginning position of the ladder.
				StoreLadderPos.push_back(ObjectHeadPos); //Storing the end position of the ladder.
			}

			if (UsrInput[0] == 'S') //Checking if the input is for the snake position.
			{
				getline(ss, UsrInput, 'S');
				getline(ss, UsrInput, '-');
				ObjectFootPos = stoi(UsrInput);
				getline(ss, UsrInput, '\t');
				ObjectHeadPos = stoi(UsrInput);

				StoreSnakePos.push_back(ObjectFootPos);
				StoreSnakePos.push_back(ObjectHeadPos);
			}
		}
	}
}
#endif
