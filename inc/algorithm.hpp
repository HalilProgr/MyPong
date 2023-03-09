#pragma once

#include "circle.hpp"
#include "paddle.hpp"

class Algoritm {
	float const PI = std::acos(-1);

	Paddle &_leftPaddle;
	Paddle &_rightPaddle;
	Circle &_circle;

	sf::RenderWindow &_window;

	sf::Clock AITimer;
	const sf::Time AITime = sf::seconds(0.1f);
	const float paddleSpeed = 400.f;
	float rightPaddleSpeed = 0.f;
	const float ballSpeed = 400.f;

	void restartGame();
	void collisionsWithPaddle();

	void collisionsWithBox();

public:
	Algoritm(sf::RenderWindow& window,
		Paddle& leftPaddle,
		Paddle& rightPaddle,
		Circle& circle);

	void update(float delta, sf::Time Aitime);

};