#include "play.h"
#include "SFML/Graphics.hpp"

void play:: run()
{

    sf::RenderWindow window(sf::VideoMode(600, 600), "game"); // window screen 

    sf::Vector2i player = sf::Vector2i(13, 13);
    sf::RectangleShape playerRect = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    playerRect.setPosition(player.x * 40.f, player.y * 40.f);
    playerRect.setFillColor(sf::Color(0, 180, 0));
    playerRect.setOutlineThickness(1.f);
    playerRect.setOutlineColor(sf::Color(0, 0, 0));

    sf::Vector2i opponent = sf::Vector2i(1, 1);
    sf::RectangleShape opponentRect = sf::RectangleShape(sf::Vector2f(40.f, 40.f));
    opponentRect.setPosition(opponent.x * 40.f, opponent.y * 40.f);
    opponentRect.setFillColor(sf::Color(190, 0, 0));
    opponentRect.setOutlineThickness(1.f);
    opponentRect.setOutlineColor(sf::Color(0, 0, 0));

    int gameMap[15 * 15]; // game map
    sf::RectangleShape displayrects[15 * 15]; // the map 

    for (size_t i = 0; i < 15; i++)
    {
        for (size_t j = 0; j < 15; j++) // for showing white square
        {
            displayrects[i + j * 15].setPosition(i * 40.f, j * 40.f);
            displayrects[i + j * 15].setSize(sf::Vector2f(40.f, 40.f));
            displayrects[i + j * 15].setOutlineThickness(4.f);
            displayrects[i + j * 15].setOutlineColor(sf::Color(1, 2, 5));

            if (!(i == opponent.x && j == opponent.y) && !(i == player.x && j == player.y))
            {
                if (std::rand() / (float)RAND_MAX < 0.22f || i == 0 || j == 0 || i == 14 || j == 14) // make blake square
                {
                    gameMap[i + j * 15] = 1;
                    displayrects[i + j * 15].setFillColor(sf::Color(0, 0, 0));
                }
            }
        }
    }

    while (window.isOpen()) // this codes are for sfml works
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                case sf::Keyboard::Up:
                    if (gameMap[player.x + (player.y - 1) * 15] != 1) player.y -= 1;
                    break;
                case sf::Keyboard::Down:
                    if (gameMap[player.x + (player.y + 1) * 15] != 1) player.y += 1;
                    break;
                case sf::Keyboard::Right:
                    if (gameMap[(player.x + 1) + player.y * 15] != 1) player.x += 1;
                    break;
                case sf::Keyboard::Left:
                    if (gameMap[(player.x - 1) + player.y * 15] != 1) player.x -= 1;
                    break;     
                }
            }
            playerRect.setPosition(player.x * 40.f, player.y * 40.f);
        }

        window.clear(sf::Color(255, 255, 255));


        for (size_t i = 0; i < 15 * 15; i++) // draw the squares
        {
            window.draw(displayrects[i]);
        }
        window.draw(playerRect);
        window.draw(opponentRect);


        window.display();
    }
}