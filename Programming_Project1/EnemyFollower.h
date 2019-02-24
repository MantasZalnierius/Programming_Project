#ifndef ENEMY_FOLLOWER
#define ENEMY_FOLLOWER

#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>
#include "MyVector2.h"


class EnemyFollower
{
	// private data members
	sf::Texture m_Texture; // This sf::Texture member variable repersents the texture of the enemy follower.
	sf::Sprite m_Sprite; // This sf::Sprite member variable repersents the sprite of a enemy follower.
	sf::Vector2f m_startPoistion{};  // This sf::Vector2f member repersents the enemy follower start position.
	sf::Vector2f m_scale{}; // This sf::Vector2f member repersents the scale of the enemy follower.
	sf::Vector2f m_distanceLine{}; // This sf::Vector2f member repersents the distance line between the enemy follower and the player.
	sf::Vector2f m_unitVector{}; // This sf::Vector2f member repersents the unit vector of the distance line.
	int m_health; // This int member variable repersents the health of a enemy follower.
	int m_speedX; // This int member variable repersents the speed of a enemy follower in the X axis. 
	int m_speedY; // This int member variable repersents the speed of a enemy follower in the Y axis.
	bool m_isAlive; // This bool member variable repersents if the enemy follower is alive or not.
	double m_speed; // This double member variable repersents the speed that the enemy can go.
public:
	EnemyFollower(); // This is the default constructor for the enemy follower class.
	~EnemyFollower(); // This is the default destructor for the enemy follower class.
	void		setUpEnemyFollower(); // This member function sets up the enemy follower
	void		loadSpriteAndTexture(); // This member function loads the sprite and texture of the enemy follower
	void		move(sf::Vector2f t_playerPoistion); // This member function moves the enemy follower.
	void		playerCollision(sf::Sprite t_playerPosition); // This member function dectects collision between the player and the enemy follower.
	void		bulletCollision(sf::Sprite t_bullet, bool t_isActive, int &t_playerScore); // This member function detects collision between the bullet and the enemy follower.
	void		setUpEnemeyFollowerPoistionHelp(sf::Vector2f t_followerPoistion1); // This member function sets uo the enemy follower for the help screen on the main menu.
	inline sf::Sprite	getBody() { return m_Sprite; } // This member function gets the sprite of the enemy follower.
	inline int			getHealth() { return m_health; } // This member function gets the health of the enemy follower.

};


#endif
