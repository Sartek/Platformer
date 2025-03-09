#include "Player.hpp"
#include "Game.hpp"
#include "Tile.hpp"

Player::Player() :
	_isLoaded(false)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	Player::gravity = 16;
	Player::onGround = true;
	Player::maxVelocity = 512;
}

bool Player::isOnGround()
{
	Tile bottomleft;
	bottomleft.y = Player::getRect().position.y + Player::getNextRect().size.y;
	bottomleft.x = Player::getRect().position.x;
	bottomleft.y = (bottomleft.y - (bottomleft.y % 32))/32;
	bottomleft.x = (bottomleft.x - (bottomleft.x % 32))/32;
	bottomleft.solid = Game::getLevel().isTileSolid(bottomleft.x,bottomleft.y);

	Tile bottomright;
	bottomright.y = Player::getRect().position.y + Player::getNextRect().size.y;
	bottomright.x = Player::getRect().position.x + Player::getNextRect().size.x;
	bottomright.y = (bottomright.y - (bottomright.y % 32))/32;
	bottomright.x = (bottomright.x - (bottomright.x % 32))/32;
	bottomright.solid = Game::getLevel().isTileSolid(bottomright.x,bottomright.y);

	if(bottomleft.solid or bottomright.solid)
	{
		Player::onGround=true;
	}
	else
	{
		Player::onGround=false;
	}
		return Player::onGround;
}

void Player::MoveUp()
{
	Player::setVelocity(Player::getVelocity().x,-254);
}

void Player::MoveDown()
{
	Player::setVelocity(Player::getVelocity().x,254);
}

void Player::MoveLeft()
{
	Player::spriteID = 2;
	Player::setVelocity(-254,Player::getVelocity().y);
}

void Player::MoveRight()
{
	Player::spriteID = 1;
	Player::setVelocity(254,Player::getVelocity().y);
}

void Player::Update()
{

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
		Player::MoveLeft();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
		Player::MoveRight();
    }
    else
    {
        Player::setVelocity(0,Player::getVelocity().y);
    }

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && Player::isOnGround())
	{
		Player::MoveUp();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && !Player::isOnGround())
	{
		Player::MoveDown();
	}

	{
		Tile topleft;
		topleft.y = Player::getNextRect().position.y;
		topleft.x = Player::getNextRect().position.x;
		topleft.y = (topleft.y - (topleft.y % 32))/32;
		topleft.x = (topleft.x - (topleft.x % 32))/32;
		topleft.solid = Game::getLevel().isTileSolid(topleft.x,topleft.y);
		topleft.top = Game::getLevel().getTileRect(topleft.x,topleft.y).position.y;
		topleft.left = Game::getLevel().getTileRect(topleft.x,topleft.y).position.x;
		topleft.width = Game::getLevel().getTileRect(topleft.x,topleft.y).size.x;
		topleft.height = Game::getLevel().getTileRect(topleft.x,topleft.y).size.y;

		Tile topright;
		topright.y = Player::getNextRect().position.y;
		topright.x = Player::getNextRect().position.x + Player::getNextRect().size.x;
		topright.y = (topright.y - (topright.y % 32))/32;
		topright.x = (topright.x - (topright.x % 32))/32;
		topright.solid = Game::getLevel().isTileSolid(topright.x,topright.y);
		topright.top = Game::getLevel().getTileRect(topright.x,topright.y).position.y;
		topright.left = Game::getLevel().getTileRect(topright.x,topright.y).position.x;
		topright.width = Game::getLevel().getTileRect(topright.x,topright.y).size.x;
		topright.height = Game::getLevel().getTileRect(topright.x,topright.y).size.y;

		Tile midleft;
		midleft.y = Player::getNextRect().position.y + (Player::getNextRect().size.y / 2);
		midleft.x = Player::getNextRect().position.x;
		midleft.y = (midleft.y - (midleft.y % 32))/32;
		midleft.x = (midleft.x - (midleft.x % 32))/32;
		midleft.solid = Game::getLevel().isTileSolid(midleft.x,midleft.y);
		midleft.top = Game::getLevel().getTileRect(midleft.x,midleft.y).position.y;
		midleft.left = Game::getLevel().getTileRect(midleft.x,midleft.y).position.x;
		midleft.width = Game::getLevel().getTileRect(midleft.x,midleft.y).size.x;
		midleft.height = Game::getLevel().getTileRect(midleft.x,midleft.y).size.y;

		Tile midright;
		midright.y = Player::getNextRect().position.y + (Player::getNextRect().size.y / 2);
		midright.x = Player::getNextRect().position.x + Player::getNextRect().size.x;
		midright.y = (midright.y - (midright.y % 32))/32;
		midright.x = (midright.x - (midright.x % 32))/32;
		midright.solid = Game::getLevel().isTileSolid(midright.x,midright.y);
		midright.top = Game::getLevel().getTileRect(midright.x,midright.y).position.y;
		midright.left = Game::getLevel().getTileRect(midright.x,midright.y).position.x;
		midright.width = Game::getLevel().getTileRect(midright.x,midright.y).size.x;
		midright.height = Game::getLevel().getTileRect(midright.x,midright.y).size.y;

		Tile bottomleft;
		bottomleft.y = Player::getNextRect().position.y + Player::getNextRect().size.y;
		bottomleft.x = Player::getNextRect().position.x;
		bottomleft.y = (bottomleft.y - (bottomleft.y % 32))/32;
		bottomleft.x = (bottomleft.x - (bottomleft.x % 32))/32;
		bottomleft.solid = Game::getLevel().isTileSolid(bottomleft.x,bottomleft.y);
		bottomleft.top = Game::getLevel().getTileRect(bottomleft.x,bottomleft.y).position.y;
		bottomleft.left = Game::getLevel().getTileRect(bottomleft.x,bottomleft.y).position.x;
		bottomleft.width = Game::getLevel().getTileRect(bottomleft.x,bottomleft.y).size.x;
		bottomleft.height = Game::getLevel().getTileRect(bottomleft.x,bottomleft.y).size.y;

		Tile bottomright;
		bottomright.y = Player::getNextRect().position.y + Player::getNextRect().size.y;
		bottomright.x = Player::getNextRect().position.x + Player::getNextRect().size.x;
		bottomright.y = (bottomright.y - (bottomright.y % 32))/32;
		bottomright.x = (bottomright.x - (bottomright.x % 32))/32;
		bottomright.solid = Game::getLevel().isTileSolid(bottomright.x,bottomright.y);
		bottomright.top = Game::getLevel().getTileRect(bottomright.x,bottomright.y).position.y;;
		bottomright.left = Game::getLevel().getTileRect(bottomright.x,bottomright.y).position.x;
		bottomright.width = Game::getLevel().getTileRect(bottomright.x,bottomright.y).size.x;
		bottomright.height = Game::getLevel().getTileRect(bottomright.x,bottomright.y).size.y;

		//if(bottomleft.solid or bottomright.solid)
		//{
		//	Player::onGround = 1;
		//}
		//else
		//{
		//	Player::onGround = 0;
		//}

		if(topleft.solid or topright.solid)
		{
			if(Player::getVelocity().y <0)
			{
				Player::setVelocity(Player::getVelocity().x,0);
			}
		}

		if(Player::isOnGround())
		{
			if (Player::getVelocity().y > 0)
				Player::setVelocity(Player::getVelocity().x,0);
		}
		if(!Player::isOnGround())
		{
			Player::setVelocity(Player::getVelocity().x,Player::getVelocity().y +(Player::gravity * Game::getDT()));
		}

		if(!topleft.solid && !topright.solid && !midleft.solid && !midright.solid)
		{
			Player::setPosition(Player::getPosition().x + (Player::getVelocity().x * Game::getDT()),Player::getPosition().y + (Player::getVelocity().y * Game::getDT()));
		}
		else if((bottomleft.solid or bottomright.solid) && Player::getVelocity().y > 0)
		{
			Player::setVelocity(Player::getVelocity().x,0);
			Player::setPosition(Player::getPosition().x + (Player::getVelocity().x * Game::getDT()),bottomleft.top);
		}
		else
		{
			Player::setVelocity(0,Player::getVelocity().y);
			Player::setPosition(Player::getPosition().x,Player::getPosition().y + (Player::getVelocity().y * Game::getDT()));
		}




	}


    //Player::setPosition(Player::getPosition().x + (Player::getVelocity().x * Game::getDT()),Player::getPosition().y + (Player::getVelocity().y * Game::getDT()));
}
