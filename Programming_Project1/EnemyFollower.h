#ifndef ENEMY_FOLLOWER
#define ENEMY_FOLLOWER

#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>
#include "MyVector2.h"


class EnemyFollower
{
	// private data members
	sf::Texture enemyFollowerTexture;
	sf::Sprite m_enemyFollowerSprite;
	int m_enemyFollowerHealth;
	int counter = 0;
	bool m_enemyFollowerIsAlive;
	int m_enemyFollowerSpeedX;
	int m_enemyFollowerSpeedY;
	double speed;
	sf::Vector2f m_enemyFollowerStartPoistion{};
	sf::Vector2f m_enemyFollowerScale{};
	sf::Vector2f distanceLine{};
	sf::Vector2f unitVector{};

public:
	EnemyFollower();
	~EnemyFollower();
	void		setUpEnemyFollower();
	void		loadSpriteAndTexture();
	void		move(sf::Vector2f t_playerPoistion);
	void		playerCollision(sf::Sprite t_playerPosition);
	void		bulletCollision(sf::Sprite t_bullet, bool t_isActive, int &t_playerScore);
	void		setUpEnemeyFollowerPoistionHelp(sf::Vector2f t_followerPoistion1);
	inline sf::Sprite	getBody() { return m_enemyFollowerSprite; }
	inline int			getHealth() { return m_enemyFollowerHealth; }
	void collision();
};


#endif
