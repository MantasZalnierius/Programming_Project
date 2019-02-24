#include "EnemyFollower.h"

EnemyFollower::EnemyFollower()
{
	// This sets up the enemy follower.
	loadSpriteAndTexture();
	setUpEnemyFollower();
}

EnemyFollower::~EnemyFollower()
{
}
/// <summary>
/// This sets the enemy follower.
/// </summary>
void EnemyFollower::setUpEnemyFollower()
{
	m_health = 5; // This sets the health.
	m_isAlive = true; // This sets the bool to true.
	m_speedX = 4; // This sets the speed on the X axis.
	m_startPoistion = sf::Vector2f{ static_cast<float>((rand() % 700) + 1), -100 }; // This sets the position.
	m_Sprite.setPosition(m_startPoistion); // This sets the position.
	m_scale = sf::Vector2f{ 0.2f, 0.2f }; // This sets the scale.
	m_Sprite.setScale(m_scale); // This uses the scale to make the sprite smaller.
	m_speed = 1.2; // This sets the speed.
}
/// <summary>
/// This loads the sprite and texture.
/// </summary>
void EnemyFollower::loadSpriteAndTexture()
{
	if (!m_Texture.loadFromFile("ASSETS/IMAGES/enemy-png-5.png"))
	{
		std::cout << "Enemy follower texture not loaded correctly "; // This loads the texture.
	}
	m_Sprite.setTexture(m_Texture); // This sets the texture to the sprite.
}
/// <summary>
/// This moves the enemy follower.
/// </summary>
/// <param name="t_playerPoistion"></param>
void EnemyFollower::move(sf::Vector2f t_playerPoistion)
{
	m_distanceLine = t_playerPoistion - m_Sprite.getPosition(); // This gets the distance between the enemy follower and the player sprite.
	m_unitVector = vectorUnitVector(m_distanceLine); // This gets the unit vector of the distance line.
	m_Sprite.move((m_unitVector.x * m_speed), (m_unitVector.y * m_speed)); // This moves the enemy follower by the unit vector.

}
/// <summary>
/// This checks for collision between the player and the enemy follower.
/// </summary>
/// <param name="t_playerSprite"></param>
void EnemyFollower::playerCollision(sf::Sprite t_playerSprite)
{
	if (m_Sprite.getGlobalBounds().intersects(t_playerSprite.getGlobalBounds()))
	{
		m_Sprite.setPosition(sf::Vector2f{ (static_cast<float>((rand() % 800) + 1)), -300.0f }); // This sets the position of the enemy follower.
		setUpEnemyFollower();

		if (m_speed < MAX_SPEED)
		{
			m_speed += 0.12; // This adds to the speed of the enemy follower.
		}
	}
}
/// <summary>
/// This checks for collision between the bullet and the enemy follower.
/// </summary>
/// <param name="t_bullet"></param>
/// <param name="t_isActive"></param>
/// <param name="t_playerScore"></param>
void EnemyFollower::bulletCollision(sf::Sprite t_bullet, bool t_isActive, int &t_playerScore)
{
	if (t_bullet.getGlobalBounds().intersects(m_Sprite.getGlobalBounds()))
	{
		m_Sprite.move(((rand() % 5) - 5), (rand() % 5) + 1); // This moves the enemy follower by a small amount.

		m_health--; // This decreases the health of the enemy follower.
		if (m_health <= 0)
		{
			setUpEnemyFollower();
			if (m_speed < MAX_SPEED)
			{
				m_speed += 0.12; // This adds to the speed of the enemy follower.
			}
			t_playerScore += 5; // This adds to the player score.
		}
	}
}
/// <summary>
/// This sets up the enemy follower for the help screen.
/// </summary>
/// <param name="t_followerPoistion"></param>
void EnemyFollower::setUpEnemeyFollowerPoistionHelp(sf::Vector2f t_followerPoistion)
{
	m_Sprite.setPosition(t_followerPoistion); // This sets the position of the enemy follower.
}
