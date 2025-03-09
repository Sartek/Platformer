#include "Object.hpp"
#include "Game.hpp"

Object::Object() :
	_isLoaded(false)
{
}

Object::~Object()
{
}

void Object::Load(float x,float y,float width,float height,unsigned int id)
{
	if(!Object::_isLoaded)
	{
		Object::_isLoaded = true;
		Object::spriteID = id;
		Object::setPosition(x,y);
		Object::rect.size = {width, height};
		Object::setVelocity(0,0);
		Object::Initialize();
	}
}

void Object::Initialize()
{

}

void Object::Update()
{

}

void Object::setPosition(float x,float y)
{
	Object::rect.position = {x, y};
}

sf::Vector2f Object::getPosition()
{
	sf::Vector2f Result;
	Result = Object::rect.position;
	return Result;
}

void Object::setVelocity(float x,float y)
{
	Object::velocity.x = x;
	Object::velocity.y = y;
}

sf::Vector2f Object::getVelocity()
{
	return Object::velocity;
}

unsigned int Object::getID()
{
	return Object::spriteID;
}

sf::Rect<float> Object::getRect()
{
	return Object::rect;
}

sf::Rect<float> Object::getNextRect()
{
	sf::Rect<float> nextRect;
	nextRect.position = { Object::rect.position.x + Object::getVelocity().x * Game::getDT()
						, Object::rect.position.y + Object::getVelocity().y * Game::getDT() };
	nextRect.size = Object::rect.size;

	return nextRect;
}
