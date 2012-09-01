#ifndef OBJECT
#define OBJECT
#include <SFML/Graphics.hpp>


class Object
{
public:
    Object();
    virtual ~Object();
    virtual void Load(float x,float y,float width,float height,unsigned int id);
    virtual void Initialize();
    virtual void Update();
    virtual sf::Vector2f getPosition();
    virtual void setPosition(float x, float y);
    virtual sf::Vector2f getVelocity();
    virtual void setVelocity(float x, float y);
    virtual unsigned int getID();
    virtual sf::Rect<float> getRect();
    virtual sf::Rect<float> getNextRect();

protected:
	sf::Rect<float> rect;
	sf::Vector2f velocity;
	bool _isLoaded;
	unsigned int spriteID;
};

#endif // OBJECT
