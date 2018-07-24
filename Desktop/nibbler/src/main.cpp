
#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char **argv)
{

	if (argc < 3){
		std::cout << "Invalid arguments specified: Height & Width required" << std::endl;
	}
	else {
		int Height = std::atoi(argv[1]);
		int Width = std::atoi(argv[1]);
		std::cout << Height << " :: " << Width << std::endl;

		// //getting the default bpp (bits per pixel) for the desktop
		// sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
		sf::RenderWindow window(
			sf::VideoMode(Height, Width, 32),
			"WHAT THE FUCK IS GOIN ON??"
		);

		sf::CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Yellow);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			window.draw(shape);
			window.display();
		}
	}

	return 0;
}