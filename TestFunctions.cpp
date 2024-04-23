#include "TestFunctions.h"

//constructor
TestFunctions::TestFunctions()
{
	GamePlay* new_game = new GamePlay();
	_play = new_game;
}

TestFunctions::TestFunctions(const TestFunctions& copy) 
{
	_play = copy._play;
}

//destructor
TestFunctions::~TestFunctions()
{
	delete _play;
}

