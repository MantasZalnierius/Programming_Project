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
	sf::Vector2f m_enemyFollowerStartPoistion{};
	sf::Vector2f m_enemyFollowerScale{};
	sf::Vector2f distanceLine{};
	sf::Vector2f unitVector{};
	int m_enemyFollowerHealth;
	int counter = 0;
	int m_enemyFollowerSpeedX;
	int m_enemyFollowerSpeedY;
	double speed;
	bool m_enemyFollowerIsAlive;
public:
	EnemyFollower();
	~EnemyFollower();
	void		setUpEnemyFollower();
	void		loadSpriteAndTexture();
	void		move(sf::Vector2f t_playerPoistion);
	void		playerCollision(sf::Sprite t_playerPosition);
	void		bulletCollision(sf::Sprite t_bullet, bool t_isActive, int &t_playerScore);
	void		setUpEnemeyFollowerPoistionHelp(sf::Vector2f t_followerPoistion1);
	void		collision();
	inline sf::Sprite	getBody() { return m_enemyFollowerSprite; }
	inline int			getHealth() { return m_enemyFollowerHealth; }
	
};


#endif
