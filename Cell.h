#pragma once

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