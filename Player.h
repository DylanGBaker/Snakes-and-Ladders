// Student Number: 2093671

#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include <vector>
#include<string>
#include <fstream>

using namespace std;

class Player {
public:
	Player();
	Player(string name, int Position, bool IsTurn);

	int getPosition() const;
	string getName() const;
	bool getisTurn() const;

	void setPosition(int playerPos);
	void setisTurn(bool isplayerTurn);

	void Move(vector<int>& board, vector<int>& StoreSnakePos, vector<int>& StoreLadderPos, ofstream& outFile, string playerName, int& playerPos, int RollVal, int& roundNumber, bool& hasWon);

private:
	int m_Position;
	string m_PlayerName;
	bool m_isTurn;
};
#endif  
