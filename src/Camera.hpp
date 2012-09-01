#ifndef CAMERA
#define CAMERA
#include <SFML/Graphics.hpp>

class Camera
{
public:
    static sf::Vector2f getPosition();
    static void setPosition(float x,float y);
private:
	static sf::Vector2f position;
};


#endif // GAME

