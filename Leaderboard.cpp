#include "Leaderboard.h"
#include "SFML/Graphics.hpp"

using namespace sf;

void Leaderboard::leaderboard()
{
	RenderWindow window(sf::VideoMode(900, 900), "SFML WORK!");



	while (window.isOpen())
	{
		Event event;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();

		//window.draw();

		window.display();

	}
}
