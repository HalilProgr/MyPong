#include "../inc/algorithm.h"

void Algoritm::collisionsWithPaddle()
{

    if (_circle.getPosition().x - _circle.getRadius() < _leftPaddle.getPosition().x + _leftPaddle.getSize().x / 2 &&
        _circle.getPosition().x - _circle.getRadius() > _leftPaddle.getPosition().x &&
        _circle.getPosition().y + _circle.getRadius() >= _leftPaddle.getPosition().y - _leftPaddle.getSize().y / 2 &&
        _circle.getPosition().y - _circle.getRadius() <= _leftPaddle.getPosition().y + _leftPaddle.getSize().y / 2)
    {
        if (_circle.getPosition().y > _leftPaddle.getPosition().y)
            _circle.setAngle(PI - _circle.getAngle() + (std::rand() % 20) * PI / 180);
        else
            _circle.setAngle(PI - _circle.getAngle() - (std::rand() % 20) * PI / 180);

        _circle.setPosition(_leftPaddle.getPosition().x + _circle.getRadius() + _leftPaddle.getSize().x / 2 + 0.1f, _circle.getPosition().y);
    }

    // Right Paddle
    if (_circle.getPosition().x + _circle.getRadius() > _rightPaddle.getPosition().x - _rightPaddle.getSize().x / 2 &&
        _circle.getPosition().x + _circle.getRadius() < _rightPaddle.getPosition().x &&
        _circle.getPosition().y + _circle.getRadius() >= _rightPaddle.getPosition().y - _rightPaddle.getSize().y / 2 &&
        _circle.getPosition().y - _circle.getRadius() <= _rightPaddle.getPosition().y + _rightPaddle.getSize().y / 2)
    {
        if (_circle.getPosition().y > _rightPaddle.getPosition().y)
            _circle.setAngle(PI - _circle.getAngle() + (std::rand() % 20) * PI / 180);
        else
            _circle.setAngle(PI - _circle.getAngle() - (std::rand() % 20) * PI / 180);

        _circle.setPosition(_leftPaddle.getPosition().x - _circle.getRadius() - _leftPaddle.getSize().x / 2 - 0.1f, _circle.getPosition().y);
        //ball.setPosition(rightPaddle.getPosition().x - ballRadius - paddleSize.x / 2 - 0.1f, ball.getPosition().y);
    }

}

Algoritm::Algoritm(sf::RenderWindow& window,
					   Paddle& leftPaddle,
					   Paddle& rightPaddle,
					   Circle& circle): _window(window), _circle(circle), _leftPaddle(leftPaddle), _rightPaddle(rightPaddle)
{
	
}

void Algoritm::update(float delta, sf::Time Aitime)
{



}
