#ifndef BULLET
#define BULLET

#include "SFML/Graphics.hpp" 
#include "Globals.h"
#include <iostream>
#include "MyVector2.h"

class Bullet
{
	sf::Sprite sprite;
	sf::Texture textureUp;
	sf::Texture textureDown;
	sf::Texture textureLeft;
	sf::Texture textureRight;
	sf::Vector2f Velocities{};
	sf::Vector2f position{};
	bool isActive;

public:
	Bullet();
	~Bullet();
	void setUpBullet();
	void loadSpriteAndTexture();
	bool setDirection(sf::Sprite t_player, sf::Vector2f t_playerLookDirection);
	void move();
	void changeTexture(sf::Vector2f t_playerLookDirection);
	void enemyFollowerCollision(sf::Sprite t_enemyFollower);
	void enemyCollision(sf::Sprite t_enemy);
	inline sf::Sprite getBody() { return sprite; }
	inline sf::Vector2f getPosition() { return position; }
	inline bool getStatus()  {  return isActive; }
};

#endif

