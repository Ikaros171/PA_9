#pragma once

#include "GameObject.h"
#include "Cell.h"

#include <fstream>

using std::ifstream;

class Board : public GameObject
{
public:
	// constructor - we used an array of class Cells to break the board down into individual squares for player movement purposes.
	// We load the pixel coordinates of these cells from 'Cells.csv'. 
	Board(float x = 0.0, float y = 0.0, const string& fileName = "") : GameObject(x, y, fileName)
	{
		ifstream inputStream;
		inputStream.open("Cells.csv");
		int i = 0, new_x = 0, new_y = 0, new_trans = 0;

		if (inputStream.is_open()) // check successful file opening
		{
			while (inputStream >> new_x >> new_y >> new_trans && (i < 106)) // reads in the coords, and transport destination
			{
				Cell temp(new_x, new_y, new_trans);
				this->_cellArray[i] = temp;
				i++;
			}
			inputStream.close();
		}
	}

	// overloaded assignment operator
	Board& operator= (Board& rhs);

	// copy constructor
	Board(Board& copy);

	// deconstructor
	~Board();

	// getter
	Cell& getCell(int pos);

private:
	Cell _cellArray[106];
};