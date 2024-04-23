CptS 122 - Spring 2024 - WSU - Instructor Andrew O'Fallon
Group Members: Nathanael Zink (Lab Section 05), James Griffith (Lab Section 13), Giri Vignesh (Lab Section 1), Ishaan Joshi (Lab Section 13)
Video Demonstration: 

Resources Used:
Game Board PNG (Stock, Royaltry Free) found at: https://www.dreamstime.com/photos-images/ladders-board.html
You Win PNG (open source) found at: https://stockcake.com/i/victory-celebration-sunrise_836618_849050

Inheritance:
We created a base class GameObject that most of our other classes publically inherited from. This base class included an sf::sprite,
sf::texture, x and y coordinates for the sprite, and the file path to load the texture from. We also created a Button class which 
pubically inherited from sf::RectangleShape to check where the user was clicking regarding menu options. 

Polymorphism:
Our base class GameObject had several virtual functions, although we only ended up overriding the draw() function. The base draw()
function drew the sprite attribute of the GameObject. The Menu and Dice classes that were derived from GameObject added some Buttons
which needed to be drawn as well (3 buttons for Menu, 1 for Dice). By ovveriding the draw() function, we were able to instantiate
a std::vector<GameObject*> in the playGame function, push_back all the things we needed to draw (since they were all derived from 
GameObject and therefore could be inserted into a vector of GameObject pointers), and just call the draw() function for each element
in the vector. The correct version of draw() would be called depending on the memory type of the element (GameObject vs Menu vs Dice).
This is an example of runtime polymorphism.

Note: We could not figure out how to disregard roll input while a piece was moving. We tried to use a bool variable isMoving anded
with the MouseButtonReleased event to only check input once per interation of the while loop in playerTurn, but it still queued at least
one roll into the input stream so the next player didn't have to click roll for their piece to move (or the next roll in case of a bonus
roll). As such, please wait 1 second between clicking the dice for rolls, otherwise you'll queue up multiple rolls in a row. The game logic
still works (it doesn't break the game) but there'd be less interaction than intended.

Rules: There is a menu option for rules, but in addition the game is only for 2 human players (or one human rolling for both players).
Originally, we intended to have the user select up to four players and potentially add computer players, but we ran out of time. 