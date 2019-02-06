#include "EnemyFollower.h"

EnemyFollower::EnemyFollower()
{
	loadSpriteAndTexture();
	setUpEnemyFollower();
}

EnemyFollower::~EnemyFollower()
{
}

void EnemyFollower::setUpEnemyFollower()
{
	m_enemyFollowerHealth = 5;
	m_enemyFollowerIsAlive = true;
	m_enemyFollowerSpeedX = 4;
	m_enemyFollowerStartPoistion = sf::Vector2f{ static_cast<float>((rand() % 700) + 1), -100 };
	m_enemyFollowerSprite.setPosition(m_enemyFollowerStartPoistion);
	m_enemyFollowerScale = sf::Vector2f{ 0.2f, 0.2f };
	m_enemyFollowerSprite.setScale(m_enemyFollowerScale);
}

void EnemyFollower::loadSpriteAndTexture()
{
	if (!enemyFollowerTexture.loadFromFile("ASSETS/IMAGES/enemy-png-5.png"))
	{
		std::cout << "Enemy follower texture not loaded correctly ";
	}

	m_enemyFollowerSprite.setTexture(enemyFollowerTexture);
}

void EnemyFollower::move(sf::Vector2f t_playerPoistion)
{
	distanceLine =  t_playerPoistion - m_enemyFollowerSprite.getPosition();
	unitVector = vectorUnitVector(distanceLine);
	m_enemyFollowerSprite.move((unitVector.x * 2), (unitVector.y * 2));
}

void EnemyFollower::playerCollision(sf::Sprite t_playerSprite)
{
	if (m_enemyFollowerSprite.getGlobalBounds().intersects(t_playerSprite.getGlobalBounds()))
	{
		m_enemyFollowerSprite.setPosition(sf::Vector2f{0.0f, 0.0f});
	}
}
