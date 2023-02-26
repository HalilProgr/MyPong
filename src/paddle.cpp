#include "../inc/paddle.h"

Paddle::Paddle(sf::Vector2f& size,
	float thickness, const sf::Color& filColor, const sf::Color& OutlineColor) : _speed(0)
{
	_rectangle.setSize(size - sf::Vector2f(thickness, thickness));
	_rectangle.setOutlineThickness(thickness);
	_rectangle.setOutlineColor(OutlineColor);
	_rectangle.setFillColor(filColor);
	_rectangle.setOrigin(size / 2.f);
}

void Paddle::setSpeed(float speed) {
	_speed = speed;
};
void Paddle::setPosition(float x, float y) {
	_rectangle.setPosition(x, y);
}


const sf::Vector2f& Paddle::getSize() const {
	return _rectangle.getSize();
};
const sf::Vector2f& Paddle::getPosition() {
	return _rectangle.getPosition();
};
float Paddle::getSpeed() const {
	return _speed;
}

void Paddle::move(float deltaTime) {
	_rectangle.move(0.f, _speed * deltaTime);
}

Paddle::operator sf::RectangleShape() const
{
	return _rectangle;
}

