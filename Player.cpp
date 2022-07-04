// Student Number: 2093671

#include "Player.h"

using namespace std;

Player::Player() {
	Player::m_Position = 0;
	Player::m_isTurn = true;
}

Player::Player(string name, int Position = 0, bool IsTurn = true) {
	Player::m_PlayerName = name;
	Player::m_Position = Position;
	Player::m_isTurn = IsTurn;
}

void Player::setPosition(int playerPos) {
	Player::m_Position = playerPos;
}

void Player::setisTurn(bool isplayerTurn) {
	m_isTurn = isplayerTurn;
}

int Player::getPosition() const{
	return m_Position;
}

string Player::getName() const{
	return m_PlayerName;
}

bool Player::getisTurn() const {
	return m_isTurn;
}

void Player::Move(vector<int>& board, vector<int>& StoreSnakePos, vector<int>& StoreLadderPos, ofstream& outFile, string playerName, int& playerPos, int RollVal, int& roundNumber, bool& hasWon) {
	if (playerPos >= board.size() - 6 && playerPos != board.size())
	{
		for (int i = 1; i <= 6; i++) //Checks to see if the player is 6 spaces away form the end.
		{
			if (playerPos == board.size() - i && RollVal == i) //Checks to see if the player has rolled the correct value when within 6 spaces from the end.
			{
				playerPos = board.size();
				outFile << "R-" << roundNumber << " " << playerName << " " << "D-" << RollVal << " " << "M-" << playerPos << endl;
				outFile << "w" << playerName << endl;
				hasWon = true;
				break;
			}
		}

		if (!hasWon) //If they have not rolled the correct value then output their roll and their position.
		{
			outFile << "R-" << roundNumber << " " << playerName << " " << "D-" << RollVal << " " << "M-" << playerPos << endl;

		}
	}
	else if (playerPos < board.size() - 6 && playerPos != board.size() && !hasWon) //Checks to see if the player is more than 6 spaces away from the end of the board and that a player has not won so that a player can make their move.
	{
		playerPos = board[RollVal + playerPos - 1]; //Dice roll is passed into the function and then the players position will move accordingly.

		outFile << "R-" << roundNumber << " " << playerName << " " << "D-" << RollVal << " " << "M-" << playerPos << endl;

		for (int j = 0; j < StoreLadderPos.size(); j++) //Checks to see if player has landed on a ladder.
		{
			if (j % 2 == 0) //Ladders starting position is always at a even index in the vector.
			{
				if (playerPos == StoreLadderPos[j])
				{
					outFile << "R-" << roundNumber << " " << playerName << " " << "L-" << playerPos << " "; 
					playerPos = playerPos + StoreLadderPos[j + 1]; //Moves the player to the top of the ladder.
					outFile << "M-" << playerPos << endl;

					if (playerPos == board.size()) { //This checks to see if the player has landed on a ladder that takes them to the end of the board.
						playerPos = board.size();
						outFile << "R-" << roundNumber << " " << playerName << " " << "D-" << RollVal << " " << "M-" << playerPos << endl;
						outFile << "w" << playerName << endl;
						hasWon = true;
						break;
					}
					break;
				}
			}
		}

		for (int k = 0; k < StoreSnakePos.size(); k++) //Check if the player has landed on a snake.
		{
			if (k % 2 == 0) //Snake starting position is always at an even index in the vector.
			{
				if (playerPos == StoreSnakePos[k]) //Since the starting position is the snakes tail I need to check if the player has landed on the snakes tail + length.
				{
					outFile << "R-" << roundNumber << " " << playerName << " " << "S-" << playerPos << " ";
					playerPos -= StoreSnakePos[k + 1]; //Moves the player to the snakes tail.
					outFile << "M-" << playerPos << endl;
					break;
				}
			}
		}
	}
	setPosition(playerPos);
}


