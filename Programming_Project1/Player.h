#ifndef PLAYER
#define PLAYER

#include "SFML/Graphics.hpp" 
#include <iostream>

class Player
{
	// private data members
	sf::Texture m_playerTextureUp;
	sf::Texture m_playerTextureDown;
	sf::Texture m_playerTextureLeft;
	sf::Texture m_playerTextureRight;
	sf::Sprite m_playerSprite;
	sf::Vector2f playerVelocity{};
	sf::Vector2f playerLookDirection{};
	sf::Vector2f m_playerStartPoistion{};
	int m_playerHealth;
	int cooldown;
	int immunityFrameCooldown;
	bool m_playerIsAlive;


public:
	Player();
	~Player();
	void		setUpPlayer();
	void		loadSpriteAndTexture();
	void		move();
	void		boundaryCollision();
	void		setUpPlayerForTheHelpScreen(sf::Vector2f t_playerPoistion);
	void		enemyFollowerCollision(sf::Sprite t_enemyFollower);
	void		enemyCollision(sf::Sprite t_enemy);
	inline		sf::Sprite	getBody() { return m_playerSprite; }
	inline		sf::Vector2f getLookDirection() { return playerLookDirection; }
	inline void setCooldown(int t_cooldown) { cooldown = t_cooldown; }
	inline int  getCooldown() { return cooldown; }
	inline int  getHealth() { return m_playerHealth; }
	inline void setHealth(int t_playerHealth) { m_playerHealth = t_playerHealth; }
};

#endif