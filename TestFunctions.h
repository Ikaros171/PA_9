#pragma once

#include "GamePlay.h"

class TestFunctions
{
public:
	//constructors
	TestFunctions();
	TestFunctions(const TestFunctions& copy);

	//destructor
	~TestFunctions();

	//overloaded = operator
	TestFunctions& operator=(const TestFunctions& lhs) 
	{
		TestFunctions* copy = new TestFunctions(lhs);
		_play = copy->_play;
		return *this;
	}

	//test functions
	void testCase1();
	void testCase2();
	void testCase3();
	void testCase4();
	void testCase5();

private:
	GamePlay* _play;
};

