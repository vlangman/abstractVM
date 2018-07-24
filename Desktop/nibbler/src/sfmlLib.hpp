
#pragma once

class sfmlLib{
	private:
		int 		height;
		int 		width;
		const bool 	verbose = true;

	public:
	/*
		default constructors and deconstructors for canonical form
	*/
		sfmlLib(void);
		~sfmlLib(void);
		sfmlLib & sfmlLib(const sfmlLib & _sfml);
		sfmlLib & operator=(const sfmlLib & _sfml);

	/*
		custom constructors for Height an Width
	*/

		sfmlLib(const int _H, const int _W);
};