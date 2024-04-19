#pragma once

class Cell
{
public:
	// constructor
	Cell(float x = 0.0, float y = 0.0, int destIndex = 0);

	// destructor
	~Cell();

	// getters
	float getXCord() const;
	float getYCord() const;
	int getDestIndex() const;

	// setters
	void setXCord(float newX);
	void setYCord(float newY);
	void setDestIndex(int newIndex);

private:
	float _xCord;
	float _yCord;
	int _destIndex;
};