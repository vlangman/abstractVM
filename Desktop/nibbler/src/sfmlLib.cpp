#include "sfmlLib."
/*
	default constructors and deconstructors for canonical form
*/
	sfmlLib(){
		if (this->verbos){
			std::cout << "sfmlLib VOID CONSTRUCTOR called."
		}
		return;
	}

	~sfmlLib(){
		if (this->verbos){
			std::cout << "sfmlLib VOID DECONSTRUCTOR called."
		}
		return;
	}

	sfmlLib & sfmlLib(const sfmlLib & _sfml){
		this->height = _sfml.getHeight();
		this->width = _sfml.getWidth();
	}

	sfmlLib & operator=(const sfmlLib & _sfml){

	}

/*
	custom constructors for Height an Width
*/

	sfmlLib(const int _H, const int _W);