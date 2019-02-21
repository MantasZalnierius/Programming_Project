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
	sf::Vector2f m_enemyStartPoistion{};
	int m_enemyHealth;
	int m_enemySpeedX;
	int m_enemySpeedY;
	bool m_enemyIsAlive;


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