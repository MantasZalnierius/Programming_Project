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
	bool isActive;
	bool isFired;
	sf::Vector2f size{};
	sf::Vector2f Velocities;
	sf::Vector2f position{};

public:
	Bullet();
	~Bullet();
	void setUpBullet();
	void loadSpriteAndTexture();
	bool setDirection(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection, int &cooldown);
	void move(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection);
	void changeTexture(sf::Vector2f t_playerLookDirection);
	void enemyFollowerCollision(sf::Sprite t_enemyFollower);
	void enemyCollision(sf::Sprite t_enemy);
	inline void setFired(bool t_isFired) { isFired = t_isFired; }
	inline sf::Sprite getBody() { return sprite; }
	inline sf::Vector2f getPosition() { return position; }
	inline bool getStatus()  {  return isActive; }
	inline bool getFired() { return isFired; }
};

#endif

