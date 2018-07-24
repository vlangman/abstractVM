#pragma once
#include <iostream>

class graphicsInterface {

private:
	int window_x;
	int window_y;

public:

	/*
		default constructors and deconstructors for canonical form
	*/
		graphicsInterface(void){return;}
		~graphicsInterface(void);
		graphicsInterface & graphicsInterface(const graphicsInterface & _lib);
		graphicsInterface & graphicsInterface=(const graphicsInterface & _lib);
};