#include "snake.hpp"

/*
	- CANONICAL FORM START
*/
	Snake::Snake(void){
		if (this->verbose){
			std::cout << "SNAKE default  constructor called" << std::endl;
		}
		return;
	};

	Snake::~Snake(void){
		if (this->verbose){
			std::cout << "SNAKE default  deconstructor called" << std::endl;
		}
		return;
	};

	Snake & Snake::operator=(const Snake & _snake){
		if (this->verbose){
			std::cout << "SNAKE assignment (=) overload called" << std::endl;
		}
		this->window_x = _snake.getWindowX();
		this->window_y = _snake.getWindowY();
		return this;
	};

	Snake & Snake::Snake(const Snake & _snake){
		if (this->verbose){
			std::cout << "SNAKE assignment (=) overload called" << std::endl;
		}
		this->window_x = _snake.getWindowX();
		this->window_y = _snake.getWindowY();
		return this;
	};
/*
	- CANONICAL FORM END
*/


/*
	GETTERS START
*/
	int Snake::getWindowX(void){
		return this->window_x;
	};

	int Snake::getWindowY(void){
		return this->window_y;
	};
/*
	GETTERS END
*/

/*
	SETTERS START
*/


/*
	MAIN GAME LOOP START
*/

	int 	Snake::runLoop(void){
		if (this->verbose){
			std::cout << "---------- [ GAME LOOP INITIALISED ] "----------" << std::endl;
		}
	}
/*
	MAIN GAME LOOP END
*/