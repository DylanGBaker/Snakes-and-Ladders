// Student Number: 2093671

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "Player.h"
#include "Board.h"
#include "GameHandler.h"

using namespace std;


int main()
{
	//Declaring and initialising variables
	int NumOfGames = 0;
	string UsrInput;
	string StoreUsrInput;
	vector<int> Board, StoreSnakePos, StoreLadderPos;

	ifstream inFile;
	ofstream outFile;

	inFile.open("input.txt");
	outFile.open("results.txt");

	if (!inFile) { //If the input file is not open then the application will return -1 and end/
		return -1;
	}

	MakeBoard(Board, StoreSnakePos, StoreLadderPos, inFile, outFile, UsrInput, StoreUsrInput,NumOfGames);
	GameHandler(Board, StoreSnakePos, StoreLadderPos, outFile, NumOfGames);

	inFile.close();
	outFile.close();

	return 0;
}















