#ifndef PLAYER
#define PLAYER

#include "SFML/Graphics.hpp" 
#include <iostream>

class Player
{
	// private data members
	sf::Texture m_textureUp; // This sf::Texture member variable repersents a texture for the player.
	sf::Texture m_textureDown; // This sf::Texture member variable repersents a texture for the player.
	sf::Texture m_textureLeft; // This sf::Texture member variable repersents a texture for the player.
	sf::Texture m_textureRight; // This sf::Texture member variable repersents a texture for the player.
	sf::Sprite m_sprite; // This sf::Sprite member variable repersents the sprite for the player.
	sf::Vector2f m_velocity{}; // This sf::Vector2f member variable repersensts the velocity of the player.
	sf::Vector2f m_lookDirection{}; // This sf::Vector2f member variable repersensts the look direction of the player.
	sf::Vector2f m_startPoistion{}; // This sf::Vector2f member variable repersensts the start position of the player.
	int m_health; // This int member variable repersents the health of the player.
	int m_cooldown; // This int member variable repersents the coldown of the bullets.
	int m_immunityFrameCooldown; // This int member variable repersents the immunity frame for the player.
	bool m_isAlive; // This bool member variable is to check if the player is alive or not.


public:
	Player(); // This is the default constructor for the player class.
	~Player(); // This is the default destructor for the player class.
	void		setUpPlayer(); // This member function sets up the player.
	void		loadSpriteAndTexture();  // This member function loads the sprite and texture of the player.
	void		move();  // This member function moves the player.
	void		boundaryCollision();  // This member function checks for collision between the boundary and the player.
	void		setUpPlayerForTheHelpScreen(sf::Vector2f t_playerPoistion);  // This member function sets up the player for the help screen.
	void		enemyFollowerCollision(sf::Sprite t_enemyFollower);  // This member function checks for collision betweeen the enemy follower and the player.
	void		enemyCollision(sf::Sprite t_enemy);  // This member function checks for collision betweeen the enemy and the player.
	inline		sf::Sprite	getBody() { return m_sprite; }  // This member function gets the sprite of the player.
	inline		sf::Vector2f getLookDirection() { return m_lookDirection; }  // This member function gets the look direction of the player.
	inline void setCooldown(int t_cooldown) { m_cooldown = t_cooldown; }  // This member function sets the coldown of the bullets.
	inline int  getCooldown() { return m_cooldown; }  // This member function gets the coldown of the bullets.
	inline int  getHealth() { return m_health; }  // This member function gets the health of the player.
	inline void setHealth(int t_playerHealth) { m_health = t_playerHealth; }  // This member function sets the health of the player.
};

#endif