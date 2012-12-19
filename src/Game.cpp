#include "Game.hpp"

int Game::Start()
{
    Game::Window.create(sf::VideoMode(800,600,32),"Platformer",sf::Style::Close);
    //Game::Window.setFramerateLimit(60);
    Game::exit = false;
    sf::Image icon;
    if (!icon.loadFromFile("resources/textures/icon.bmp"))
        return 1;
    Game::Window.setIcon(32,32,icon.getPixelsPtr());

	Game::player.Load(13.5*32,11.5*32,32,48,1);

	Game::ft = sf::seconds(0);
	Game::at = 0;
	Game::dt =  1 / 240.0;

    Game::GameLoop();
    return 0;

}

bool Game::isExiting()
{
    return Game::exit;
}

void Game::GameLoop()
{
    while(!Game::isExiting())
    {
    	Game::ft = Game::dc.restart();
    	if (Game::ft.asSeconds() > 0.25)
			Game::ft = sf::seconds(0.25); // Avoid spiral of death

		Game::at += Game::ft.asSeconds();

        Game::PollEvent();
        while(Game::at >= Game::dt)
        {
			Game::Update();
        	Game::at -= dt;
        }

        Game::Renderer();
    }
}

sf::RenderWindow& Game::getWindow()
{
    return Game::Window;
}

Level& Game::getLevel()
{
    return Game::level;
}

float Game::getDT()
{
	return Game::dt;
}

Player& Game::getPlayer()
{
	return player;
}

void Game::PollEvent()
{
    sf::Event event;
    while (Game::Window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            Game::exit = true;
    }
}

void Game::Update()
{
	player.Update();
}

void Game::Renderer()
{
    Game::Window.clear(sf::Color(254, 0, 0));

    Game::render.Background();

	for(unsigned int x = 0; x < Game::level.getWidth();x++)
	{
		for(unsigned int y = 0; y < Game::level.getHeight();y++)
		{
			Game::render.Tile(x,y,level.getTile(x,y));
		}
	}

	Game::render.Player();

	Game::render.Hud();
    Game::Window.display();
}

sf::RenderWindow Game::Window;
float Game::dt;
float Game::at;
sf::Time Game::ft;
sf::Clock Game::dc;
bool Game::exit;
Level Game::level;
Render Game::render;
Player Game::player;
