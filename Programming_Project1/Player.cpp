#include "Player.h"   // include Player header file

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
	m_playerSpeed = 10;
	m_playerHealth = 5;
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

void Player::move(sf::Event t_keyboardEvent)
{

	if (t_keyboardEvent.key.code == sf::Keyboard::Left)
	{
		m_playerSprite.move(-m_playerSpeed, 0);
		m_playerSprite.setTexture(m_playerTextureLeft);
	}

	if (t_keyboardEvent.key.code == sf::Keyboard::Right)
	{
		m_playerSprite.move(m_playerSpeed, 0);
		m_playerSprite.setTexture(m_playerTextureRight);
	}

	if (t_keyboardEvent.key.code == sf::Keyboard::Up)
	{
		m_playerSprite.move(0, -m_playerSpeed);
		m_playerSprite.setTexture(m_playerTextureUp);
	}

	if (t_keyboardEvent.key.code == sf::Keyboard::Down)
	{
		m_playerSprite.move(0, m_playerSpeed);
		m_playerSprite.setTexture(m_playerTextureDown);
	}
}

void Player::boundaryCollision()
{
	if (m_playerSprite.getPosition().x >= 775 - m_playerSprite.getGlobalBounds().width)
	{
		m_playerSprite.setPosition(sf::Vector2f{ (m_playerSprite.getPosition().x - 10), m_playerSprite.getPosition().y });
	}

	if (m_playerSprite.getPosition().x  <= -30 + m_playerSprite.getGlobalBounds().width)
	{
		m_playerSprite.setPosition(sf::Vector2f{ (m_playerSprite.getPosition().x + 10), m_playerSprite.getPosition().y });
	}

	if (m_playerSprite.getPosition().y <= -65 + m_playerSprite.getGlobalBounds().height)
	{
		m_playerSprite.setPosition(sf::Vector2f{ m_playerSprite.getPosition().x, (m_playerSprite.getPosition().y + 10) });
	}

	if (m_playerSprite.getPosition().y >= 565 - m_playerSprite.getGlobalBounds().height)
	{
		m_playerSprite.setPosition(sf::Vector2f{ m_playerSprite.getPosition().x , (m_playerSprite.getPosition().y - 10) });
	}

	if (m_playerSprite.getPosition().y >= 610 - m_playerSprite.getGlobalBounds().height)
	{
		m_playerSprite.setPosition(sf::Vector2f{ m_playerSprite.getPosition().x , (m_playerSprite.getPosition().y - 10) });
	}
}
