#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <SFML/Graphics.hpp>

class Level
{
public:
    Level();
    virtual ~Level();
    int getTile(int x,int y);
	sf::Rect<int> getTileRect(int x,int y);
    bool isTileSolid(int x,int y);
    unsigned int getWidth();
    unsigned int getHeight();
private:
	unsigned int Tiles[25][16];
	bool TileCollisions[25][16];
};

#endif // LEVEL_HPP
