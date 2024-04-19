#pragma once

#include "GameObject.h"
#include <fstream>

using std::ifstream;

class Cell
{
public:
	// constructor
	Cell(bool transport = false, float x = 0.0, float y = 0.0, int destIndex = 0);

	// destructor
	~Cell();

	// getters
	bool getTransportStatus() const;
	float getXCord() const;
	float getYCord() const;
	int getDestIndex() const;

	// setters
	void setTransportStatus(bool status);
	void setXCord(float newX);
	void setYCord(float newY);
	void setDestIndex(int newIndex);

private:
	bool _transport;
	float _xCord;
	float _yCord;
	int _destIndex;
};

class Board : public GameObject
{
public:
	// constructor
	Board(float x = 0.0, float y = 0.0, const string& fileName = "") : GameObject(x, y, fileName)
	{
		ifstream inputStream;
		inputStream.open("Cells.csv", std::ios::in);
		int index = 0, j = 0;
		char transportStatus = '\0';
		Cell temp(false, 0, 0, 0);

		if (inputStream.is_open()) // check successful file opening
		{
			while ((inputStream >> j) && (index < 101)) // reads in the x cord, also serves as end of file marker
			{
				temp.setXCord(j); // set x coordinate
				inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the comma
				inputStream >> j; // read in y coordinate
				temp.setYCord(j); // set y coordinate
				inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the comma
				inputStream >> transportStatus; // read in whether the cell contains a ladder or a chute
				if (transportStatus == 'F')
				{
					temp.setTransportStatus(false);
				}
				else
				{
					temp.setTransportStatus(true);
				}
				inputStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore the comma
				inputStream >> j; // read in the cell number that the chute/ladder transports to; -1 indicates the cell
				// doesn't have a chute nor a ladder
				temp.setDestIndex(j);
				inputStream >> transportStatus; // read in the newline at the end of the line
				this->_cellArray[index] = temp;
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
	Cell getCell(int pos);

private:
	Cell _cellArray[101];
};