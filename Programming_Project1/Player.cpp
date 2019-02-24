#include "Player.h"   // include Player header file

Player::Player() // default constructor
{
	// This sets up the player.
	loadSpriteAndTexture();
	setUpPlayer();// load the image file for the sprite
}

Player::~Player()
{

}
/// <summary>
/// This sets up the player.
/// </summary>
void Player::setUpPlayer()
{
	m_cooldown = 10; // This sets the coldown.
	m_isAlive = true; // This sets the bool to true.
	m_lookDirection = sf::Vector2f{ 0.0f, -5.0f }; // This sets the player look direction.
	m_velocity = sf::Vector2f{ 0.0, 0.0 }; // This sets the player velocity.
	m_health = 100; // This sets the player health.
	m_startPoistion = sf::Vector2f{ 365.0f, 500.0f }; // This sets the player start position.
	m_sprite.setPosition(m_startPoistion); // This sets the player start position.
	m_immunityFrameCooldown = 0; // This sets up the immunity frames for player.
}
/// <summary>
/// This sets the player position.
/// </summary>
/// <param name="t_playerPoistion"></param>
void Player::setUpPlayerForTheHelpScreen(sf::Vector2f t_playerPoistion)
{
	m_sprite.setPosition(t_playerPoistion); // This sets the position of the player.
}
/// <summary>
/// This sets the sprite and texture of the player.
/// </summary>
void Player::loadSpriteAndTexture()
{
	if (!m_textureUp.loadFromFile("ASSETS/IMAGES/player_up.png"))
	{
		std::cout << "error with player image file"; // This loads a texture.
	}

	if (!m_textureDown.loadFromFile("ASSETS/IMAGES/player_down.png"))
	{
		std::cout << "error with player image file"; // This loads a texture.
	}

	if (!m_textureLeft.loadFromFile("ASSETS/IMAGES/player_left.png"))
	{
		std::cout << "error with player image file"; // This loads a texture.
	}

	if (!m_textureRight.loadFromFile("ASSETS/IMAGES/player_right.png"))
	{
		std::cout << "error with player image file"; // This loads a texture.
	}

	m_sprite.setTexture(m_textureUp); // This sets the texture to the sprite.
}
/// <summary>
/// This moves the player.
/// </summary>
void Player::move()
{
	m_velocity = sf::Vector2f{ 0.0f, 0.0f }; // This sets the velocity to zero.

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_velocity.x = -5.0f; // This sets the X velocity to -5.0.
		m_sprite.setTexture(m_textureLeft); // This sets the texture to the sprite.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_velocity.x = 5.0f; // This sets the X velocity to 5.0.
		m_sprite.setTexture(m_textureRight); // This sets the texture to the sprite.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_velocity.y = -5.0f; // This sets the Y velocity to -5.0.
		m_sprite.setTexture(m_textureUp); // This sets the texture to the sprite.
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_velocity.y = 5.0f; // This sets the Y velocity to 5.0.
		m_sprite.setTexture(m_textureDown); // This sets the texture to the sprite.
	}

	if (m_velocity.x != 0.0f || m_velocity.y != 0.0f)
	{
		m_lookDirection = m_velocity; // This sets the player look direction to the player vecloity.
	}

	m_sprite.move(m_velocity); // This moves the player.
}
/// <summary>
/// This checks for collsions between the boundary and the player.
/// </summary>
void Player::boundaryCollision()
{
	if (m_sprite.getPosition().x >= 775 - m_sprite.getGlobalBounds().width)
	{
		m_sprite.setPosition(sf::Vector2f{ (m_sprite.getPosition().x - 10), m_sprite.getPosition().y }); // This sets the position of the player.
	}

	if (m_sprite.getPosition().x <= -30 + m_sprite.getGlobalBounds().width)
	{
		m_sprite.setPosition(sf::Vector2f{ (m_sprite.getPosition().x + 10), m_sprite.getPosition().y }); // This sets the position of the player.
	}

	if (m_sprite.getPosition().y <= -65 + m_sprite.getGlobalBounds().height)
	{
		m_sprite.setPosition(sf::Vector2f{ m_sprite.getPosition().x, (m_sprite.getPosition().y + 10) }); // This sets the position of the player.
	}

	if (m_sprite.getPosition().y >= 565 - m_sprite.getGlobalBounds().height)
	{
		m_sprite.setPosition(sf::Vector2f{ m_sprite.getPosition().x , (m_sprite.getPosition().y - 10) }); // This sets the position of the player.
	}

	if (m_sprite.getPosition().y >= 610 - m_sprite.getGlobalBounds().height)
	{
		m_sprite.setPosition(sf::Vector2f{ m_sprite.getPosition().x , (m_sprite.getPosition().y - 10) }); // This sets the position of the player.
	}
}
/// <summary>
/// This checks for collision between the enemy and the player.
/// </summary>
/// <param name="t_enemyFollower"></param>
void Player::enemyFollowerCollision(sf::Sprite t_enemyFollower)
{
	if (m_immunityFrameCooldown <= 1)
	{
		m_sprite.setColor(sf::Color::White); // This sets the color of the sprite to white.
	}
	if (m_immunityFrameCooldown <= 0)
	{
		if (m_sprite.getGlobalBounds().intersects(t_enemyFollower.getGlobalBounds()))
		{
			if (m_health > 0)
			{
				m_health -= 2; // This decreases the players health by 2.
				m_sprite.setColor(sf::Color::Red); // This sets the player color to red.
				m_immunityFrameCooldown = 200; // This sets the immunity frame to 200.
			}
			else
			{
				m_health = 0; // This sets the player health to zero.
			}
		}
	}
	else
	{
		m_immunityFrameCooldown--; // This subtracts one from the immunity frame.
	}
}
/// <summary>
/// This checks for collision between the enemy and the player.
/// </summary>
/// <param name="t_enemy"></param>
void Player::enemyCollision(sf::Sprite t_enemy)
{
	if (m_immunityFrameCooldown <= 200)
	{
		m_sprite.setColor(sf::Color::White); // This sets the color of the sprite to white.
	}
	if (m_immunityFrameCooldown <= 0)
	{
		if (m_sprite.getGlobalBounds().intersects(t_enemy.getGlobalBounds()))
		{
			if (m_health > 0)
			{
				m_health--; // This decreases the players health by 1.
				m_sprite.setColor(sf::Color::Red); // This sets the player color to red.
				m_immunityFrameCooldown = 400; // This sets the immunity frame to 400.
			}
			else
			{
				m_health = 0; // This sets the player health to zero.
			}
		}
	}
	else
	{
		m_immunityFrameCooldown--; // This subtracts one from the immunity frame.
	}
}
