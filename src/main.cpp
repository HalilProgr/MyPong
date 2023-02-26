#include <SFML/Graphics.hpp>

#include "../inc/Paddle.h"
#include "../inc/circle.h"
#include "../inc/algorithm.h"
#include <iostream>

int main()
{
    sf::Vector2f sizeWindow(800, 600);
    sf::Vector2f paddleSize(25, 100);

    sf::RenderWindow window(sf::VideoMode(sizeWindow.x, sizeWindow.y), "My Pong");
    window.setVerticalSyncEnabled(true);

    Paddle leftPaddle(paddleSize, 3, sf::Color(100, 100, 200), sf::Color::Black);
    leftPaddle.setSpeed(400.f);
    leftPaddle.setPosition(10 + paddleSize.x / 2, sizeWindow.y / 2);

    Paddle rightPaddle(paddleSize, 3, sf::Color(100, 100, 200), sf::Color::Black);
    rightPaddle.setSpeed(400.f);
    rightPaddle.setPosition(sizeWindow.x - 10 - paddleSize.x / 2, sizeWindow.y / 2);

    Circle circle(10, 3, sf::Color::White, sf::Color::Green);
    circle.setPosition(sizeWindow.x / 2, sizeWindow.y / 2);
    circle.setSpeed(-200);

    sf::Clock clock;
    bool isPlaying = false;

    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\lea-k\\Desktop\\Visual code\\PongTest\\res\\sansation.ttf"))
        return EXIT_FAILURE;

    sf::Text pauseMessage;
    pauseMessage.setFont(font);
    pauseMessage.setCharacterSize(40);
    pauseMessage.setPosition(170.f, 150.f);
    pauseMessage.setFillColor(sf::Color::White);
    pauseMessage.setString("Welcome to SFML pong!\nPress space to start the game");

    Algoritm algoritm(window, leftPaddle, rightPaddle, circle);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || event.key.code == sf::Keyboard::Escape)
                window.close();
        }


        float delta = clock.restart().asSeconds();


        // algorithm.update(AItime, delta)

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

        circle.move(delta);




        window.clear();
        window.draw(rightPaddle);
        window.draw(leftPaddle);
        window.draw(circle);
        window.display();
    }

    return 0;
}