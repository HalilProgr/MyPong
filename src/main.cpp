#include <SFML/Graphics.hpp>

#include "../inc/Paddle.h"
#include <iostream>

int main()
{
    sf::Vector2f paddleSize(25, 100);

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    window.setVerticalSyncEnabled(true);

    paddle leftPaddle(paddleSize, 3, sf::Color(100, 100, 200), sf::Color::Black);
    leftPaddle.setSpeed(400.f);
    leftPaddle.setPosition(10 + paddleSize.x / 2, 600 / 2);

    sf::Clock clock;


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    std::cout << "the escape key was pressed" << std::endl;
                    std::cout << "control:" << event.key.control << std::endl;
                    std::cout << "alt:" << event.key.alt << std::endl;
                    std::cout << "shift:" << event.key.shift << std::endl;
                    std::cout << "system:" << event.key.system << std::endl;
                    window.close();
                }
            }
        }

        float delta = clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            // left key is pressed: move our character
            leftPaddle.move(-delta);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            // left key is pressed: move our character
            leftPaddle.move(delta);
        }

        window.clear();
        
        window.draw(leftPaddle);
        window.display();
    }

    return 0;
}