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
	int m_enemySpeedX;
	int m_enemySpeedY;
	sf::Vector2f m_enemyStartPoistion{};

public:
	Enemy();
	~Enemy();
	void		setUpEnemy();
	void		loadSpriteAndTexture();
	void		move();
	void		setUpEnemyForTheHelpScreen(sf::Vector2f t_enemypoistion);
	inline sf::Sprite	getBody() { return m_enemySprite; }
};


#endif