#pragma once

#include <SFML/Graphics.hpp>

class Paddle {

	sf::RectangleShape  _rectangle;
	sf::Vector2f		_sizeRectangle;

	float _speed;
public:
	Paddle(sf::Vector2f& size,
		float thickness, const sf::Color& filColor,
		const sf::Color& OutlineColor);

	void setSpeed(float speed);
	void setPosition(float x, float y);

	const sf::Vector2f& getSize() const;
	const sf::Vector2f& getPosition();
	float getSpeed() const;

	void move(float deltaTime);

	operator sf::RectangleShape()const;

};