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
	m_enemySpeed = 4;
	m_enemyHealth = 5;
}

void Enemy::loadSpriteAndTexture()
{
	if (!enemyTexture.loadFromFile("ASSETS/IMAGES/Enemy.PNG"))
	{
		std::cout << "Error loading Alien spaceship file ";
	}

	m_enemyStartPoistion = { sf::Vector2f { static_cast<float>((rand() % 400) + 5), static_cast<float>((rand() % 400 + 5))} };
	m_enemySprite.setTexture(enemyTexture);
	m_enemySprite.setPosition(m_enemyStartPoistion);
}

void Enemy::move()
{
}

void Enemy::boundaryCollision()
{
}

sf::Sprite Enemy::getBody()
{
	return m_enemySprite;
}
