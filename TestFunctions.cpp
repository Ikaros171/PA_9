#include "TestFunctions.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

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

//test functions
//Function: testCase1
// 
//Description: checks whether or not the game properly stops once the GamePiece
//Cont: int for position is set to a winning position (value > 99), prints to
//Cont: console the results of this test
//
//Argument(s): N/A
// 
//Returns: void
void TestFunctions::testCase1() {
	bool expected = false;

	//this code is copy pasted from GamePlay.cpp as there is no way to
	//automatically iterate through player turns with the way the PlayGame()
	//function is written

	if (expected == true)
	{
		//logic behaves as expected, print success to console
		cout << "Test Case 1 Executed Successfully" << endl;
	}
	else
	{
		//logic did not behave as expected, print error to console
		cout << "Test Case 1 Failed" << endl;
	}
}

//Function: testCase2
// 
//Description: creates a new board object and iterates through printing each
//Cont: cell's X and Y coordinates, as well as the destination cells for 0-100
//Cont: to make sure it read in the proper values from the CSV file
//
//Argument(s): N/A
// 
//Returns: void
void TestFunctions::testCase2()
{
	bool expected = false;

	Board new_board;
	Cell temp;
	for (int i = 0; i < 101; i++)
	{
		temp = new_board.getCell(i);
		cout << "Cell " << i << ":" << endl;
		cout << "X " << temp.getXCord() << endl;
		cout << "Y " << temp.getYCord() << endl;
		cout << "D " << temp.getDestIndex() << endl << endl;

		//pick a random one to make sure the values were read right
		if (i == 21)
		{
			//cell should be 0,560,42
			if (temp.getXCord() == 0 && temp.getYCord() == 560 && temp.getDestIndex() == 42)
			{
				expected = true;
			}
		}
	}

	if (expected == true)
	{
		//logic behaves as expected, print success to console
		cout << "Test Case 2 Executed Successfully" << endl;
	}
	else
	{
		//logic did not behave as expected, print error to console
		cout << "Test Case 2 Failed" << endl;
	}
}

//Function: testCase3
// 
//Description: 
//
//Argument(s): N/A
// 
//Returns: void
void TestFunctions::testCase3()
{
	bool expected = false;
	if (expected == true)
	{
		//logic behaves as expected, print success to console
		cout << "Test Case 3 Executed Successfully" << endl;
	}
	else
	{
		//logic did not behave as expected, print error to console
		cout << "Test Case 3 Failed" << endl;
	}
}

//Function: testCase4
// 
//Description: 
//
//Argument(s): N/A
// 
//Returns: void
void TestFunctions::testCase4()
{
	bool expected = false;
	if (expected == true)
	{
		//logic behaves as expected, print success to console
		cout << "Test Case 4 Executed Successfully" << endl;
	}
	else
	{
		//logic did not behave as expected, print error to console
		cout << "Test Case 4 Failed" << endl;
	}
}

//Function: testCase5
// 
//Description: 
//
//Argument(s): N/A
// 
//Returns: void
void TestFunctions::testCase5()
{
	bool expected = false;
	if (expected == true)
	{
		//logic behaves as expected, print success to console
		cout << "Test Case 5 Executed Successfully" << endl;
	}
	else
	{
		//logic did not behave as expected, print error to console
		cout << "Test Case 5 Failed" << endl;
	}
}