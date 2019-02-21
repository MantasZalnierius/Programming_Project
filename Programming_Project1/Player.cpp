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
	cooldown = 10;
	m_playerIsAlive = true;
	playerLookDirection = sf::Vector2f{ 0.0f, -5.0f };
	playerVelocity = sf::Vector2f{ 0.0, 0.0 };
	m_playerHealth = 100;
	m_playerStartPoistion = sf::Vector2f{ 365.0f, 500.0f };
	m_playerSprite.setPosition(m_playerStartPoistion);
	immunityFrameCooldown = 0;
}

void Player::setUpPlayerForTheHelpScreen(sf::Vector2f t_playerPoistion)
{
	m_playerSprite.setPosition(t_playerPoistion);
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

void Player::move()
{
	playerVelocity = sf::Vector2f{ 0.0f, 0.0f };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		playerVelocity.x = -5.0f;
		m_playerSprite.setTexture(m_playerTextureLeft);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		playerVelocity.x = 5.0f;
		m_playerSprite.setTexture(m_playerTextureRight);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		playerVelocity.y = -5.0f;
		m_playerSprite.setTexture(m_playerTextureUp);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		playerVelocity.y = 5.0f;
		m_playerSprite.setTexture(m_playerTextureDown);
	}

	if (playerVelocity.x != 0.0f || playerVelocity.y != 0.0f)
	{
		playerLookDirection = playerVelocity;
	}

	m_playerSprite.move(playerVelocity);
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

void Player::enemyFollowerCollision(sf::Sprite t_enemyFollower)
{
	if (immunityFrameCooldown <= 1)
	{
		m_playerSprite.setColor(sf::Color::White);
	}
	if (immunityFrameCooldown <= 0)
	{
		if (m_playerSprite.getGlobalBounds().intersects(t_enemyFollower.getGlobalBounds()))
		{
			if (m_playerHealth > 0)
			{
				m_playerHealth -= 2;
				m_playerSprite.setColor(sf::Color::Red);
				immunityFrameCooldown = 200;
			}
			else
			{
				m_playerHealth = 0;
			}
		}
	}
	else
	{
		immunityFrameCooldown--;
	}
}

void Player::enemyCollision(sf::Sprite t_enemy)
{
	if (immunityFrameCooldown <= 200)
	{
			m_playerSprite.setColor(sf::Color::White);
	}
	if (immunityFrameCooldown <= 0)
	{
		if (m_playerSprite.getGlobalBounds().intersects(t_enemy.getGlobalBounds()))
		{
			if (m_playerHealth > 0)
			{
				m_playerHealth--;
				m_playerSprite.setColor(sf::Color::Red);
				immunityFrameCooldown = 400;
			}
			else
			{
				m_playerHealth = 0;
			}
		}
	}
	else
	{
		immunityFrameCooldown--;
	}
}
