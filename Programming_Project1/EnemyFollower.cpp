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
	speed = 1.2;
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
	m_enemyFollowerSprite.move((unitVector.x * speed), (unitVector.y * speed));

}

void EnemyFollower::playerCollision(sf::Sprite t_playerSprite)
{
	if (m_enemyFollowerSprite.getGlobalBounds().intersects(t_playerSprite.getGlobalBounds()))
	{
		m_enemyFollowerSprite.setPosition(sf::Vector2f{(static_cast<float>((rand() % 800) + 1)), -300.0f});
		if (speed < MAX_SPEED)
		{
			speed += 0.12;
		}
	}
}

void EnemyFollower::bulletCollision(sf::Sprite t_bullet, bool t_isActive, int &t_playerScore)
{
	if (t_bullet.getGlobalBounds().intersects(m_enemyFollowerSprite.getGlobalBounds()) && t_isActive)
	{
		m_enemyFollowerSprite.move(((rand() % 5) - 5), (rand() % 5) + 1);
		m_enemyFollowerHealth--;
		if (m_enemyFollowerHealth <= 0)
		{
			setUpEnemyFollower();
			if (speed < MAX_SPEED)
			{
 				speed += 0.12;
			}
			t_playerScore += 5;
		}
	}
}

void EnemyFollower::setUpEnemeyFollowerPoistionHelp(sf::Vector2f t_followerPoistion)
{
	m_enemyFollowerSprite.setPosition(t_followerPoistion);
}
