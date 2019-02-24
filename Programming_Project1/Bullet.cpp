#include "Bullet.h"

Bullet::Bullet()
{
	// This sets up each bullet.
	loadSpriteAndTexture();
	setUpBullet();
	setUpSound();
}

Bullet::~Bullet()
{
}
/// <summary>
/// This sets up the bullet
/// </summary>
void Bullet::setUpBullet()
{
	m_velocity = sf::Vector2f{ 0.0f, 0.0f }; // This sets the velocity of each bullet.
	m_position = sf::Vector2f{ -2000.0f, -2000.0f }; // This sets the position of each bullet.
	m_sprite.setPosition(m_position); // This sets the position of each bullet.
	m_isActive = false; // This sets if the bullets are alive or not.
}
/// <summary>
/// This loads the sprite and texture of each bullet.
/// </summary>
void Bullet::loadSpriteAndTexture()
{
	if (!m_textureUp.loadFromFile("ASSETS/IMAGES/fireball_up.png"))
	{
		std::cout << "Error in loading the fireball texture"; // This loads a texture.
	}

	if (!m_textureDown.loadFromFile("ASSETS/IMAGES/fireball_down.png"))
	{
		std::cout << "Error in loading the fireball texture"; // This loads a texture.
	}

	if (!m_textureRight.loadFromFile("ASSETS/IMAGES/fireball_right.png"))
	{
		std::cout << "Error in loading the fireball texture"; // This loads a texture.
	}

	if (!m_textureLeft.loadFromFile("ASSETS/IMAGES/fireball_left.png"))
	{
		std::cout << "Error in loading the fireball texture"; // This loads a texture.
	}

	m_sprite.setTexture(m_textureUp); // This sets the texture of the player.
}
/// <summary>
/// This sets up the sounds for each bullet.
/// </summary>
void Bullet::setUpSound()
{
	if (!m_bulletSoundBuffer.loadFromFile("ASSETS/SOUND/gun-gunshot-02.wav"))
	{
		std::cout << "error with the sound file"; // This loads a sound file.
	}
	m_bulletSound.setBuffer(m_bulletSoundBuffer); // This loads the sound buffer to the sound.

	if (!m_bulletHitWallSoundBuffer.loadFromFile("ASSETS/SOUND/zapsplat_impact_head_slam_against_table_13494.wav"))
	{
		std::cout << "error with the sound file"; // This loads a sound file.
	}
	m_bulletHitWallSound.setBuffer(m_bulletHitWallSoundBuffer); // This loads the sound buffer to the sound.

	if (!m_bulletHitSoundBuffer.loadFromFile("ASSETS/SOUND/zapsplat_impact_thud_light_squelch_17502.wav"))
	{
		std::cout << "error with the sound file"; // This loads a sound file.
	}

	m_bulletHitSound.setBuffer(m_bulletHitSoundBuffer); // This loads the sound buffer to the sound.

	if (!m_bulletHitOtherEenemyBuffer.loadFromFile("ASSETS/SOUND/zapsplat_impact_head_hit_ground_thump_17498 (1).wav"))
	{
		std::cout << "error with the sound file"; // This loads a sound file.
	}

	m_bulletHitOtherEenemy.setBuffer(m_bulletHitOtherEenemyBuffer); // This loads the sound buffer to the sound.
}
/// <summary>
/// This sets the direction of the bullet.
/// </summary>
/// <param name="t_player"></param>
/// <param name="t_playerLookDirection"></param>
/// <returns></returns>
bool Bullet::setDirection(sf::Sprite t_player, sf::Vector2f t_playerLookDirection)
{
	if (!m_isActive)
	{
		m_isActive = true; // This sets the bool to true.
		m_sprite.setPosition(t_player.getPosition().x, t_player.getPosition().y); // This sets the position of the bullet to the player.
		m_velocity = t_playerLookDirection; // This sets the velocity of the bullet to the player look direction.
		changeTexture(t_playerLookDirection); // This changes the texture of the bullet.
		m_velocity = vectorUnitVector(t_playerLookDirection) * 10.0f; // this moves the bullet by the unit vector by a speed of 10.0f.
		m_bulletSound.play(); // This plays a sound effect.
		return m_isActive; // This returns true.
	}
	else
	{
		return false; // This returns false.
	}
}
/// <summary>
/// This moves the bullet
/// </summary>
void Bullet::move()
{
	if (m_isActive)
	{
		m_sprite.move(m_velocity); // This moves the bullet.
		if (m_sprite.getPosition().x > 700)
		{
			m_isActive = false; // This sets the bool to false.
			m_velocity = sf::Vector2f{ 0.0f, 0.0f }; // This sets the velocity to zero.
			m_bulletHitWallSound.play(); // This plays a sound effect.
		}
		else if (m_sprite.getPosition().x < 40)
		{
			m_isActive = false; // This sets the bool to false.
			m_velocity = sf::Vector2f{ 0.0f, 0.0f }; // This sets the velocity to zero.
			m_bulletHitWallSound.play(); // This plays a sound effect.
		}
		else if (m_sprite.getPosition().y < 35)
		{
			m_isActive = false; // This sets the bool to false.
			m_velocity = sf::Vector2f{ 0.0f, 0.0f }; // This sets the velocity to zero.
			m_bulletHitWallSound.play(); // This plays a sound effect.
		}
		else if (m_sprite.getPosition().y > 500)
		{
			m_isActive = false; // This sets the bool to false.
			m_velocity = sf::Vector2f{ 0.0f, 0.0f }; // This sets the velocity to zero.
			m_bulletHitWallSound.play(); // This plays a sound effect.
		}
	}
}
/// <summary>
/// This changes the texture of each bullet.
/// </summary>
/// <param name="t_playerLookDirection"></param>
void Bullet::changeTexture(sf::Vector2f t_playerLookDirection)
{
	if (t_playerLookDirection.x > 0.0)
	{
		m_sprite.setTexture(m_textureRight); // This changes the texture of the bullet.
	}
	else if (t_playerLookDirection.x < 0.0)
	{
		m_sprite.setTexture(m_textureLeft); // This changes the texture of the bullet.
	}
	else if (t_playerLookDirection.y > 0.0)
	{
		m_sprite.setTexture(m_textureDown); // This changes the texture of the bullet.
	}
	else if (t_playerLookDirection.y < 0.0)
	{
		m_sprite.setTexture(m_textureUp); // This changes the texture of the bullet.
	}
}
/// <summary>
/// This checks for collision between the enemy follower and the bullet
/// </summary>
/// <param name="t_enemyFollower"></param>
void Bullet::enemyFollowerCollision(sf::Sprite t_enemyFollower)
{
	if (m_sprite.getGlobalBounds().intersects(t_enemyFollower.getGlobalBounds()))
	{
		m_sprite.setPosition(sf::Vector2f{ -2000.0f, -2000.0f }); // This sets position of the bullet.
		m_isActive = false; // This sets the bool to false.
		m_bulletHitSound.play(); // This plays a sound effect.
	}
}
/// <summary>
/// This checks for collisions between the enemy and the bullet.
/// </summary>
/// <param name="t_enemy"></param>
void Bullet::enemyCollision(sf::Sprite t_enemy)
{
	if (m_sprite.getGlobalBounds().intersects(t_enemy.getGlobalBounds()))
	{
		m_isActive = false; // This sets the bool to false.
		m_sprite.setPosition(sf::Vector2f{ -2000.0f, -2000.0f }); // This sets position of the bullet.
		m_bulletHitOtherEenemy.play(); // This plays a sound effect.
	}
}
