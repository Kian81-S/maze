#include "About.h"
#include "SFML/Graphics.hpp"

using namespace sf;

void About::about()
{
	Font font;
	font.loadFromFile("arial.ttf");
	Text text;

	text.setFont(font);
	text.setFillColor(Color::Red);
	text.setString("git link");
	text.setCharacterSize(70);
	text.setStyle(sf::Text::Bold);
	text.setPosition(450, 300);

	Text text2;
	
	text2.setFont(font);
	text2.setFillColor(Color::Blue);
	text2.setString("move keys : Up,Down,Left,Right \n Exit: Escap \n mute music: m \n play music : p");
	text2.setCharacterSize(50);
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(100, 100);


	sf::RenderWindow window(sf::VideoMode(900, 900), "SFML WORK!");


	sf::RectangleShape background;
	background.setSize(sf::Vector2f(900, 900));
	sf::Texture A;
	A.loadFromFile("BGA.jpg");
	background.setTexture(&A);


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
		window.draw(background);
		window.draw(text2);
		window.draw(text);
		

		window.display();

	}
	
}