// Student Number: 2093671

#ifndef GAMEHANDLER_H
#define GAMEHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Player.h"

using namespace std;

int RollDice()
{
	int RollVal = 0;
	int d6 = 6;

	RollVal = 1 + (rand() % d6);

	return RollVal;
}

void GameHandler(vector<int>& Board, vector<int>& StoreSnakePos, vector<int>& StoreLadderPos, ofstream& outFile, int numofgames)
{
	//Initializing and declaring variables
	const int NumPlayers = 2;
	int RollVal = 0;
	int RoundNumber = 0;
	int NumGamesPlayed = 0;

	Player PlayerVec[NumPlayers];
	PlayerVec[0] = Player("P-1", 0, true);
	PlayerVec[1] = Player("P-2", 0, false);

	bool hasWon = false;

	outFile << "R-" << RoundNumber << " " << "P-1" << " " << "D-0" << " " << "M-" << PlayerVec[0].getPosition() << endl;
	outFile << "R-" << RoundNumber << " " << "P-2" << " " << "D-0" << " " << "M-" << PlayerVec[1].getPosition() << endl;

	RoundNumber++;

	srand(time(NULL));

	while (!hasWon)
	{
		for (int i = 0; i < NumPlayers; i++) { //Cycles through the players in the player array.
			RollVal = RollDice();
			int playerpos = PlayerVec[i].getPosition();
			string playername = PlayerVec[i].getName();
			
			if (PlayerVec[i].getisTurn()) { //If it is the players turn then the player move.
				PlayerVec[i].Move(Board, StoreSnakePos, StoreLadderPos, outFile, playername, playerpos, RollVal, RoundNumber, hasWon);

				if (i != 1 && !hasWon) { //Check to make the next players turn treu and the current one false
					PlayerVec[i].setisTurn(false);
					PlayerVec[i + 1].setisTurn(true);
				}
				else if (!hasWon) //If the last player in the array has finished their turn it will then set the previous players turn to true as there is only two players.
				{
					PlayerVec[i].setisTurn(false);
					PlayerVec[i - 1].setisTurn(true);
				}
			}
		}
		RoundNumber++;

		if (RoundNumber == Board.size() && !hasWon) { //Check to see if the number of rounds has reached the board size so that it can determine who the winner is.
			hasWon = true;

			/// <summary>
			/// The following gets each players position and name to determine who is in the lead.
			/// </summary>
			int PlayerOnePos = PlayerVec[0].getPosition();
			int PlayerTwoPos = PlayerVec[1].getPosition();
			string PlayerOneName = PlayerVec[0].getName();
			string PlayerTwoName = PlayerVec[1].getName();
			
			if (PlayerOnePos > PlayerTwoPos) {
				outFile << "w" << PlayerOneName << endl;
			}
			else {
				outFile << "w" << PlayerTwoName << endl;
			}
		}
	}
}
#endif 

