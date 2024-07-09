#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "Menu.h"
#include "play.h"
#include "About.h"

using namespace std;




int main()
{
	sf::RenderWindow window(sf::VideoMode(900,900), "SFML WORK!");

	sf::RectangleShape background;
	background.setSize(sf::Vector2f(900, 900));
	sf::Texture Main;
	Main.loadFromFile("BG.jpg");
	background.setTexture(&Main);
		
	sf::Music music;
	if (!music.openFromFile("maze.ogg"))
		return -1; // error
	play r;
	About a;

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{

			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.MoveUp();
					break;
				case sf::Keyboard::Down:
					menu.MoveDown();
					break;
				case sf::Keyboard::M:
					music.pause();
					break;
				case sf::Keyboard::P:
					music.play();
					break;

				case sf::Keyboard::Return:
					switch (menu.GetPressedItem())
					{
					case 0:
						r.run();
						break;
					case 1:
						
						break;
					case 2:
						music.play();
						break;
					case 3:
						a.about();
						break;
					case 4:
						window.close();
						break;
					}
					break;
				}

				break;
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		window.clear();
		window.draw(background);
		menu.draw(window);

		window.display();
		
	}
}