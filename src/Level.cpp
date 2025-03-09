#include "Level.hpp"

Level::Level()
{
	for(unsigned int x = 0;x < Level::getWidth();x++)
	{
		for(unsigned int y = 0;y< Level::getHeight();y++)
		{
			switch(y) {
				case 0:
					Tiles[x][y] = 3;
					TileCollisions[x][y] = true;
					break;
				case 13:
					Tiles[x][y] = 2;
					TileCollisions[x][y] = true;
					break;
				case 14:
				case 15:
					Tiles[x][y] = 1;
					TileCollisions[x][y] = true;
					break;
				default:
					Tiles[x][y] = 0;
					TileCollisions[x][y] = false;
			}
			if(x == 0 && y > 7 && y < 13)
			{
				Tiles[x][y] = 3;
				TileCollisions[x][y] = true;
			}
			if((x == 7 || x == 8) && y > 12 && y < 16)
			{
				Tiles[x][y] = 0;
				TileCollisions[x][y] = false;
			}
		}
	}
}

Level::~Level()
{
	//dtor
}

int Level::getTile(int x,int y)
{
	if(x > 24 or x < 0 or y > 15 or y < 0)
	{
		return 0;
	}
	else
	{
		return Tiles[x][y];
	}
}

sf::Rect<int> Level::getTileRect(int x,int y)
{
	sf::Rect<int> result({x*32,y*32},{32,32});
	return result;
}

bool Level::isTileSolid(int x,int y)
{
	if(x > 24 or x < 0 or y > 15 or y < 0)
	{
		return true;
	}
	else
	{
		return TileCollisions[x][y];
	}
}

unsigned int Level::getWidth()
{
	return 25;
}

unsigned int Level::getHeight()
{
	return 16;
}
