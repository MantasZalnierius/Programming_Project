#ifndef ENEMY
#define ENEMY

#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>

class Enemy
{
	// private data members
	sf::Texture m_texture; // This sf::Texture member variable repersents a texture of the enemy sprite.
	sf::Sprite m_sprite; // This sf::Sprite member variable repersents the sprite of an enemy.
	sf::Vector2f m_startPoistion{}; // This sf::Vector2f member variable repersents the start position of a enemy.
	int m_health; // This int member variable repersents a enemy health.
	int m_speedX; // This int member variable repersents a enemy speed on the X axis.
	int m_speedY; // This int member variable repersents a enemy speed on the Y axis.
	bool m_isAlive; // This bool member variable repersents if a enemy if alive or not.


public:
	Enemy(); // This is the default constructor for the enemy class.
	~Enemy(); // This is the default destructor for the enemy class.
	void		setUpEnemy(); // This member function sets up the enemy.
	void		loadSpriteAndTexture(); // This member function loads the sprite and texture.
	void		move(); // This member function moves the enemy.
	void		setUpEnemyForTheHelpScreen(sf::Vector2f t_enemypoistion); // This member function sets up the enemy for the help screen in the main menu.
	inline sf::Sprite	getBody() { return m_sprite; } // This member function gets the sprite of the enemy.
};


#endif