#include "Enemy.h"

Enemy::Enemy()
{
	loadSpriteAndTexture();
	setUpEnemy();
}

Enemy::~Enemy()
{
}

void Enemy::setUpEnemy()
{
	m_enemyIsAlive = true;
	m_enemySpeedX = (rand() % 3) - 3;
	m_enemySpeedY = (rand() % 3) + 1;
	m_enemyHealth = 5;
//	m_enemyScale = sf::Vector2f{ 1.5f, 1.5f };
}

void Enemy::loadSpriteAndTexture()
{
	if (!enemyTexture.loadFromFile("ASSETS/IMAGES/Enemy.PNG"))
	{
		std::cout << "Error loading Alien spaceship file ";
	}

	m_enemyStartPoistion = { sf::Vector2f { static_cast<float>((rand() % 200) + 200), static_cast<float>((rand() % 300 + 100))} };
	m_enemySprite.setTexture(enemyTexture);
	//m_enemySprite.setScale();
	m_enemySprite.setPosition(m_enemyStartPoistion);
}

void Enemy::move()
{

	m_enemySprite.move(m_enemySpeedX, m_enemySpeedY);

	if (m_enemySprite.getPosition().x >= 760 - m_enemySprite.getGlobalBounds().width)
	{
		m_enemySpeedX *= -1;
	}

	if (m_enemySprite.getPosition().x <=  -35 + m_enemySprite.getGlobalBounds().width)
	{
		m_enemySpeedX *= -1;
	}

	if (m_enemySprite.getPosition().y <= -25 + m_enemySprite.getGlobalBounds().height)
	{
		m_enemySpeedY *= -1;
	}

	if (m_enemySprite.getPosition().y >= 570 - m_enemySprite.getGlobalBounds().height)
	{
		m_enemySpeedY *= -1;
	}
}

void Enemy::boundaryCollision()
{
}

sf::Sprite Enemy::getBody()
{
	return m_enemySprite;
}
