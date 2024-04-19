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
		inputStream.open("Cells.csv", std::ios::in);
		int index = 0, j = 0;
		char transportStatus = '\0';
		Cell temp(false, 0, 0, 0);

		if (inputStream.is_open()) // check successful file opening
		{
			while ((inputStream >> j) && (index < 106)) // reads in the x cord, also serves as end of file marker
			{
				temp.setXCord(j); // set x coordinate
				inputStream.ignore(std::numeric_limits<std::streamsize>::max(), ','); // ignore the comma
				inputStream >> j; // read in y coordinate
				temp.setYCord(j); // set y coordinate
				inputStream.ignore(std::numeric_limits<std::streamsize>::max(), ','); // ignore the comma
				inputStream >> transportStatus; // read in whether the cell contains a ladder or a chute
				if (transportStatus == 'F')
				{
					temp.setTransportStatus(false);
				}
				else
				{
					temp.setTransportStatus(true);
				}
				inputStream.ignore(std::numeric_limits<std::streamsize>::max(), ','); // ignore the comma
				inputStream >> j; // read in the cell number that the chute/ladder transports to; -1 indicates the cell
				// doesn't have a chute nor a ladder
				temp.setDestIndex(j);
				inputStream >> transportStatus; // read in the newline at the end of the line
				this->_cellArray[index] = temp; // insert the cell into the array
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