#ifndef BULLET
#define BULLET

#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>

class Bullet
{
	sf::Sprite sprite;
	sf::Texture textureUp;
	sf::Texture textureDown;
	sf::Texture textureLeft;
	sf::Texture textureRight;
	int coldown;
	sf::Vector2f size{};
	sf::Vector2f Velocities[MAX_BULLETS];
	sf::Vector2f position{};

public:
	Bullet();
	~Bullet();
	void setUpBullet();
	void loadSpriteAndTexture();
	void collision();
	void setDirection(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection);
	void move(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection);
	void changeTexture(sf::Vector2f t_playerLookDirection);
	inline sf::Sprite getBody() { return sprite; }
	inline sf::Vector2f getPosition() { return position; }

};



#endif
