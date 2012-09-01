#ifndef GAME
#define GAME
#include <SFML/Graphics.hpp>
#include "Level.hpp"
#include "Render.hpp"
#include "Player.hpp"

class Game
{
public:
    static int Start();
    static sf::RenderWindow& getWindow();
    static Level& getLevel();
    static float getDT();
    static Player& getPlayer();
private:
    static sf::RenderWindow Window;
    static void PollEvent();
    static void Renderer();
    static void Update();
    static void GameLoop();
    static bool isExiting();
    static float dt;
    static float at;
    static sf::Time ft;
    static sf::Clock dc;
    static bool exit;
    static Level level;
    static Render render;
    static Player player;
};


#endif // GAME
