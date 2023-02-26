#include "../inc/circle.h"

Circle::Circle(float radius, float thickness, const sf::Color& filColor, const sf::Color& OutlineColor):_radius(radius)
{
	_circle.setRadius(_radius - thickness);
	_circle.setOutlineThickness(thickness);
	_circle.setOutlineColor(OutlineColor);
	_circle.setFillColor(filColor);
	_circle.setOrigin(sf::Vector2f(_radius, _radius) / 2.f);

	do
	{
		_angle = (std::rand() % 360) * 2 * PI / 360;
	} while (std::abs(std::cos(_angle)) < 0.7f);
}

void Circle::setSpeed(float speed)
{
	_speed = speed;
}

void Circle::setPosition(float x, float y)
{
	_circle.setPosition(x, y);
}

void Circle::setAngle(float angle)
{
	_angle = angle;
}

const float Circle::getRadius() const
{
	return _radius;
}

const sf::Vector2f& Circle::getPosition()
{
	return _circle.getPosition();
}

float Circle::getSpeed() const
{
	return _speed;
}

float Circle::getAngle() const
{
	return _angle;
}

void Circle::move(float deltaTime)
{
	_circle.move(cos(_angle) * deltaTime * _speed, sin(_angle) * deltaTime * _speed);
}

Circle::operator sf::CircleShape() const
{
	return _circle;
}


