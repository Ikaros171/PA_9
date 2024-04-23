#include "TestFunctions.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// menu for selection between debug and play game mode
bool TestFunctions::debugOrGame() const
{
	bool runDebug = false;
	int selection = 0, flag = -1;

	do
	{
		system("cls");
		cout << "Your available options are as follows:" << "\n\n";
		cout << "1. Play Game" << endl << "2. Run Test Functions" << "\n\n";
		cout << "Please input a 1 or a 2 for corresponding choice: ";
		if (!(cin >> selection) || selection < 1 || selection > 2)
		{
			flag = -1;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\n\n" << "Invalid input. Please enter a 1 or a 2." << endl;
			system("pause");
		}
		else
		{
			flag = 1;
		}
	} while (flag != 1);

	cout << "\n\n"; // to make it look nicer if we choose to run test functions

	if (selection == 2) // run debug test functions
	{
		runDebug = true;
	}

	return runDebug;
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
	GamePiece test_piece(0.0, 0.0, "Images/Player1.png", "Player 1", 0);
	test_piece.setPos(104);

	//check if the player position is beyond 100
	if (test_piece.getPos() > 99) {
		expected = true;
	}

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

	Board new_board(0.0, 0.0, "Images/Board.png");
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
//Description: Checks if a player positioned on a transport cell is properly
//Cont: moved to the new coordinates
//
//Argument(s): N/A
// 
//Returns: void
void TestFunctions::testCase3()
{
	bool expected = false;

	//default board
	Board test_board(0.0, 0.0, "Images/Board.png");

	//temp cell
	Cell temp;

	//temp game piece set to cell 1 which is a transport cell
	GamePiece test_piece(0.0, 0.0, "Images/Player1.png", "Player 1", 0);
	test_piece.setPos(1);

	//update piece to new coords using code from GamePlay.cpp
	temp = test_board.getCell(test_piece.getPos());
	if (temp.getDestIndex() != 0)
	{
		test_piece.setPos(temp.getDestIndex());
		temp = test_board.getCell(test_piece.getPos());
		test_piece.setPositionX(temp.getXCord());
		test_piece.setPositionY(temp.getYCord());
	}

	//check that both X and Y were set properly
	if (test_piece.getPositionX() == 160 && test_piece.getPositionY() == 480)
	{
		expected = true;
	}

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

// Function: testCase4
// 
// Description: Creates a GameObject, Menu, and Dice to test whether the correct version of the draw() function is called
// based on the type of object memory in the element of the std::vector<GameObject*>. Since this test case involved testing
// the graphics, we weren't sure how to objectively test whether it was successful, so we ask the magnanimous user for help.
// The expected drawing should be the title screen, a green player 1 banner at the bottom of the window, and a dice displaying
// 6 pips on top of the banner. If this is what was drawn, click anywhere within the window for the test to clear successfully.
// If this is not what was drawn, click the X to close the window and the test will fail. 
//
// Argument(s): N/A
// 
// Returns: void
void TestFunctions::testCase4()
{
	bool expected = false;
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 900), "Test Window");
	GameObject object1(0.0, 800.0, "Images/Player1BottomBanner.png");
	object1.load(object1.getFileName());
	Dice object2(100.0, 800.0, "Images/dice_6.png");
	object2.load(object2.getFileName());
	Menu object3(0.0, 0.0, "Images/Title.png");
	object3.load(object3.getFileName());
	object3.getBtn0().setPosition(sf::Vector2f(0.0, 0.0));
	object3.getBtn0().setSize(sf::Vector2f(800.0, 900.0));
	object3.getBtn1().setPosition(sf::Vector2f(0.0, 0.0));
	object3.getBtn1().setSize(sf::Vector2f(0, 0));
	object3.getBtn2().setPosition(sf::Vector2f(0.0, 0.0));
	object3.getBtn2().setSize(sf::Vector2f(0, 0));

	std::vector<GameObject*> drawVector;
	drawVector.push_back(&object3);
	drawVector.push_back(&object1);
	drawVector.push_back(&object2);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				auto mousePosition = sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y);
				if (object3.getBtn0().getGlobalBounds().contains(mousePosition))
				{
					expected = true;
					window.close();
				}
			}
		}

		window.clear();
		for (int index = 0; index < drawVector.size(); ++index)
		{
			(*(drawVector[index])).draw(window);
		}
		window.display();
	}

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

	int dieRoll = 5;
	string temp1 = "Images/dice_", temp2 = std::to_string(dieRoll), temp3 = ".png";
	string fileName = temp1 + temp2 + temp3;

	Dice die(0.0, 0.0, "Images/dice_2.png");
	die.load(die.getFileName()); // initially load in 2 pips texture
	die.load(fileName); // should load in the 5 pip texture

	if (die.getFileName() == "Images/dice_5.png") // check for success
	{
		expected = true;
	}
	
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