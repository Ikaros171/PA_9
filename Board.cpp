#include "Board.h"

void Board::player_moves(int x, int y, player& p)
{
	board.at(x).at(y);

	if (board.at(x).at(y).ladder)
	{
		p.x_cordinate = board.at(x).at(y).x_destination;
		p.y_cordinate = board.at(x).at(y).y_destination;
	}

	if (board.at(x).at(y).snake)
	{
		p.x_cordinate = board.at(x).at(y).x_destination;
		p.y_cordinate = board.at(x).at(y).y_destination;
	}
}