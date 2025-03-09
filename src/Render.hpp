#ifndef RENDER
#define RENDER
#include <SFML/Graphics.hpp>
#include <vector>

class Render
{
private:
	sf::Texture Tile1;
	sf::Texture Tile2;
	sf::Texture Tile3;
	sf::Texture TileError;
	sf::Texture TileAlpha;
	sf::Texture background;
	sf::Sprite backgroundSprite;
	sf::Texture Sprite1;
	sf::Texture Sprite2;
	sf::Sprite playerSprite;
	sf::RenderTexture hud;
	sf::Sprite hudSprite;
	std::vector<std::vector<sf::Sprite*> > SpriteArea;
public:
    Render();
    virtual ~Render();
	void Background();
    void Tile(unsigned int x,unsigned int y,unsigned int id);
    void Hud();
    void Player();
};

#endif // RENDER
