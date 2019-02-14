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
	int m_playerHealth;
	bool m_playerIsAlive;
	sf::Vector2f playerVelocity{};
	sf::Vector2f playerLookDirection{};
	sf::Vector2f m_playerStartPoistion{};
	sf::Vector2f m_playerScale{};

public:
	Player();
	~Player();
	void		setUpPlayer();
	void		loadSpriteAndTexture();
	void		move();
	void		boundaryCollision();
	inline sf::Sprite	getBody() { return m_playerSprite; }
	inline sf::Vector2f getLookDirection() { return playerLookDirection; }
};

#endif