#include <iostream>

/*
	- SNAKE class in charge of the main game loop 
*/

class Snake {

private:
	const bool verbose = true;

	int window_x;
	int window_y;

public:
	
	Snake(void);
	~Snake(void);
	Snake & operator=(const Snake & _snake);
	Snake & Snake(const Snake & _snake);

	/*
		GETTERS 
	*/
	int getWindowX(void);
	int getWindowY(void);

	/*
		SETTERS
	*/

	/*
		MAIN GAME LOOP
	*/

	int runLoop(void);

};