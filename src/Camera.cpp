#include "Camera.hpp"

sf::Vector2f Camera::getPosition()
{
	return Camera::position;
}

void Camera::setPosition(float x,float y)
{
	Camera::position.x = x;
	Camera::position.y = y;
}

sf::Vector2f Camera::position;
