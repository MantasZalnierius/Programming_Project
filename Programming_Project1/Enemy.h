#ifndef ENEMY
#define ENEMY

#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>

class Enemy
{
	// private data members
	sf::Texture enemyTexture;
	sf::Sprite m_enemySprite;
	int m_enemyHealth;
	bool m_enemyIsAlive;
	int m_enemySpeed;
	sf::Vector2f m_enemyStartPoistion{};
	sf::Vector2f m_enemyScale{};

public:
	Enemy();
	~Enemy();
	void		setUpEnemy();
	void		loadSpriteAndTexture();
	void		move();
	void		boundaryCollision();
	sf::Sprite	getBody();
};


#endif