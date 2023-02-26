#pragma once

#include <SFML/Graphics.hpp>
#include <cmath>

class Circle {
	float const PI = std::acos(-1);

	float _radius = 0;
	sf::CircleShape  _circle;

	float _angle = 0;
	float _speed = 0;
public:
	Circle(float radius, float thickness,
		const sf::Color& filColor,
		const sf::Color& OutlineColor);

	void setSpeed(float speed);
	void setPosition(float x, float y);
	void setAngle(float angle);

	const float getRadius() const;
	const sf::Vector2f& getPosition();
	float getSpeed() const;
	float getAngle() const;

	void move(float deltaTime);

	operator sf::CircleShape()const;
};