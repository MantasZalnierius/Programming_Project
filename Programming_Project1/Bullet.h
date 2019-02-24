#ifndef BULLET
#define BULLET

#include "SFML/Graphics.hpp" 
#include "SFML\Audio.hpp"
#include "Globals.h"
#include <iostream>
#include "MyVector2.h"

class Bullet
{
	sf::Sprite m_sprite; // This sf::Sprite member Variable repersents the sprite of the bullet. 
	sf::Texture m_textureUp; // This sf::Texture member Variable repersents the texture of a bullet going in the forward Direction 
	sf::Texture m_textureDown; // This sf::Texture member Variable repersents the texture of a bullet going in the Down Direction
	sf::Texture m_textureLeft; // This sf::Texture member Variable repersents the texture of a bullet going in the Left Direction
	sf::Texture m_textureRight; // This sf::Texture member Variable repersents the texture of a bullet going in the Right Direction
	sf::Vector2f m_velocity{}; // This is sf::Vector2f member variable repersents the velocity of a bullet.
	sf::Vector2f m_position{}; // This is sf::Vector2f member variable repersents the current poistion of a bullet.
	sf::Sound m_bulletSound; // This sf::Sound member variable repersents the bullet sound effect.
	sf::SoundBuffer m_bulletSoundBuffer; // This sf::SoundBuffer member variable repersents the bullet sound effect buffer.
	sf::Sound m_bulletHitWallSound; // This sf::Sound member variable repersents the bullet hitting the wall sound effect.
	sf::SoundBuffer m_bulletHitWallSoundBuffer; // This sf::SoundBuffer member variable repersents the bullet hitting the wall sound effect buffer.
	sf::Sound m_bulletHitSound; // This sf::Sound member variable repersents the bullet hit sound on the enemy follower.
	sf::SoundBuffer m_bulletHitSoundBuffer; // This sf::SoundBuffer member variable repersents the bullet hit sound on the enemy follower buffer.
	sf::Sound m_bulletHitOtherEenemy; // This sf::SoundBuffer member variable repersents the bullet sound effect on the bouncing enemeies.
	sf::SoundBuffer m_bulletHitOtherEenemyBuffer; // This sf::SoundBuffer member variable repersents the bullet sound effect on the bouncing enemeies buffer.
	bool m_isActive; // This repersents if the bullet is active.

public:
	Bullet(); // This is the default constructor for the bullet class.
	~Bullet(); // This is the default destructor for the bullet class.
	void setUpBullet(); // This member function sets up the bullet.
	void loadSpriteAndTexture(); // This member function Loads the sprite and texture of a bullet
	bool setDirection(sf::Sprite t_player, sf::Vector2f t_playerLookDirection); // This member function sets the direction of the bullet.
	void move(); // This member function moves the bullets.
	void setUpSound(); // This member function sets up the sounds of the bullets
	void changeTexture(sf::Vector2f t_playerLookDirection); // This member function changes the texture of the bullets.
	void enemyFollowerCollision(sf::Sprite t_enemyFollower); // This member function checks collision between a bullet an enemy follower.
	void enemyCollision(sf::Sprite t_enemy); // This member function checks for the collision between the bouncing enemies and the bullet 
	inline sf::Sprite getBody() { return m_sprite; } // This member function gets the sprite of the bullet.
	inline sf::Vector2f getPosition() { return m_position; } // This member function gets the poistion of the bullet.
	inline bool getStatus() { return m_isActive; } // This member function gets the status of the bullet
};

#endif

