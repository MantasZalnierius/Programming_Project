#include "Enemy.h"

Enemy::Enemy()
{
	// This sets up the enemy.
	loadSpriteAndTexture();
	setUpEnemy();
}

Enemy::~Enemy()
{
}
/// <summary>
/// This sets up the enemy.
/// </summary>
void Enemy::setUpEnemy()
{
	m_isAlive = true; // This sets the bool to true.
	m_speedX = (rand() % 3) - 3; // This sets the speed on the X axis to a random value from -3 to 0.
	m_speedY = (rand() % 3) + 1; // This sets the speed on the Y axis to a random value from  1 to 3.
}
/// <summary>
/// This loads the sprite and texture of the enemy.
/// </summary>
void Enemy::loadSpriteAndTexture()
{
	if (!m_texture.loadFromFile("ASSETS/IMAGES/Enemy.PNG"))
	{
		std::cout << "Error loading Alien spaceship file "; // This loads the texture.
	}

	m_startPoistion = { sf::Vector2f { static_cast<float>((rand() % 200) + 200), static_cast<float>((rand() % 300 + 100))} }; // This sets the position of the enemy.
	m_sprite.setTexture(m_texture); // This sets the texture of the sprite.
	m_sprite.setPosition(m_startPoistion); // This sets the position of the enemy.
}
/// <summary>
/// This moves the enemy
/// </summary>
void Enemy::move()
{
	m_sprite.move(m_speedX, m_speedY); // This moves the enemy.

	if (m_sprite.getPosition().x >= 760 - m_sprite.getGlobalBounds().width)
	{
		m_speedX *= -1; // This reverses the X speed value.
	}

	if (m_sprite.getPosition().x <= -35 + m_sprite.getGlobalBounds().width)
	{
		m_speedX *= -1; // This reverses the X speed value.
	}

	if (m_sprite.getPosition().y <= -25 + m_sprite.getGlobalBounds().height)
	{
		m_speedY *= -1; // This reverses the Y speed value.
	}

	if (m_sprite.getPosition().y >= 570 - m_sprite.getGlobalBounds().height)
	{
		m_speedY *= -1; // This reverses the Y speed value.
	}
}
/// <summary>
/// This sets up the enemy for the help screen
/// </summary>
/// <param name="t_enemyPoistion"></param>
void Enemy::setUpEnemyForTheHelpScreen(sf::Vector2f t_enemyPoistion)
{
	m_sprite.setPosition(t_enemyPoistion); // This sets the position of the sprite.
}
