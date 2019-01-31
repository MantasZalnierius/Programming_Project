#include "Player.h"   // include Player header file
#include <iostream>

Player::Player() // default constructor
{
	loadSpriteAndTexture();
	setUpPlayer();// load the image file for the sprite
}

Player::~Player()
{

}

void Player::setUpPlayer()
{
	m_playerIsAlive = true;
	m_playerSpeed = 5;
	m_playerHealth = 3;
	m_playerStartPoistion = sf::Vector2f{ 350.0f, 530.0f };
	m_playerSprite.setPosition(m_playerStartPoistion);
}

void Player::loadSpriteAndTexture()
{
	if (!m_playerTextureUp.loadFromFile("ASSETS/IMAGES/player_up.png"))
	{
		std::cout << "error with player image file";
	}

	if (!m_playerTextureDown.loadFromFile("ASSETS/IMAGES/player_down.png"))
	{
		std::cout << "error with player image file";
	}

	if (!m_playerTextureLeft.loadFromFile("ASSETS/IMAGES/player_left.png"))
	{
		std::cout << "error with player image file";
	}

	if (!m_playerTextureRight.loadFromFile("ASSETS/IMAGES/player_right.png"))
	{
		std::cout << "error with player image file";
	}

	m_playerSprite.setTexture(m_playerTextureUp);
}

sf::Sprite Player::getBody() // get the player's body
{
	return m_playerSprite;
}

void Player::move(sf::Event t_keyboardEvent)
{
	if (t_keyboardEvent.key.code == sf::Keyboard::Left)
	{
		m_playerSprite.move(-10, 0);
	}

	if (t_keyboardEvent.key.code == sf::Keyboard::Right)
	{
		m_playerSprite.move(10, 0);
	}

	if (t_keyboardEvent.key.code == sf::Keyboard::Up)
	{
		m_playerSprite.move(0, -10);
	}

	if (t_keyboardEvent.key.code == sf::Keyboard::Down)
	{
		m_playerSprite.move(0, 10);
	}
}

