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
	int m_playerSpeed;
	sf::Vector2f m_playerStartPoistion{};
	sf::Vector2f m_playerScale{};

public:
	Player();
	~Player();
	void		setUpPlayer();
	void		loadSpriteAndTexture();
	void		move(sf::Event t_keyboardEvent);
	void		boundaryCollision();
	sf::Sprite	getBody() { return m_playerSprite; }
};

#endif