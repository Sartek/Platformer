#include "Render.hpp"
#include "Game.hpp"

Render::Render() 
	: Tile1{"resources/textures/tiles/1.png"}
	, Tile2{"resources/textures/tiles/2.png"}
	, Tile3{"resources/textures/tiles/3.png"}
	, TileError{"resources/textures/tiles/error.png"}
	, TileAlpha{"resources/textures/tiles/alpha.png"}
	, background{"resources/textures/background.png"}
	, backgroundSprite{background}
	, Sprite1{"resources/textures/sprites/1.png"}
	, Sprite2{"resources/textures/sprites/2.png"}
	, playerSprite{Sprite1}
	, hud{{800,88}}
	, hudSprite{hud.getTexture()}
{

	Render::backgroundSprite.setTexture(background);
	Render::backgroundSprite.setPosition({0,0});

	Render::hudSprite.setPosition({0,512});

	Render::SpriteArea.resize(Game::getLevel().getWidth());
    for (unsigned int i = 0; i < Game::getLevel().getWidth(); i++)
    {
        Render::SpriteArea.at(i).resize(Game::getLevel().getHeight(), 0);
    }
    for(unsigned int y = 0; y < Game::getLevel().getHeight(); y++)
    {
        for (unsigned int x = 0; x < Game::getLevel().getWidth(); x++)
        {
            Render::SpriteArea[x][y] = new sf::Sprite(TileAlpha);
            Render::SpriteArea[x][y]->setPosition({float(x*32),float(y*32)});
        }
    }
}

Render::~Render()
{

}

void Render::Background()
{
	Game::getWindow().draw(Render::backgroundSprite);
}


void Render::Tile(unsigned int x,unsigned int y,unsigned int id)
{
	switch(id)
	{
		case 0:
			return;
		case 1:
			Render::SpriteArea[x][y]->setTexture(Render::Tile1);
			break;
		case 2:
			Render::SpriteArea[x][y]->setTexture(Render::Tile2);
			break;
		case 3:
			Render::SpriteArea[x][y]->setTexture(Render::Tile3);
			break;
	}
	if (id != 0) {
		Game::getWindow().draw(*SpriteArea[x][y]);
	}
}

void Render::Hud()
{
	Render::hud.clear(sf::Color(0, 0, 0));
	Render::hud.display();
	Render::hudSprite.setTexture(hud.getTexture());
	Game::getWindow().draw(Render::hudSprite);
}

void Render::Player()
{
	switch(Game::getPlayer().getID())
	{
		case 1:
			Render::playerSprite.setTexture(Sprite1);
			break;
		case 2:
			Render::playerSprite.setTexture(Sprite2);
			break;
	}
	Render::playerSprite.setPosition({Game::getPlayer().getPosition().x,Game::getPlayer().getPosition().y});
	Game::getWindow().draw(Render::playerSprite);
}
