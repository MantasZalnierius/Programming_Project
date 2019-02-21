#include "Bullet.h"

Bullet::Bullet()
{
	loadSpriteAndTexture();
	setUpBullet();
	setUpSound();
}

Bullet::~Bullet()
{
}

void Bullet::setUpBullet()
{
	Velocities = sf::Vector2f{ 0.0f, 0.0f };
	position = sf::Vector2f{ -2000.0f, -2000.0f };
	sprite.setPosition(position);
	isActive = false;
}

void Bullet::loadSpriteAndTexture()
{
	if (!textureUp.loadFromFile("ASSETS/IMAGES/fireball_up.png"))
	{
		std::cout << "Error in loading the fireball texture";
	}

	if (!textureDown.loadFromFile("ASSETS/IMAGES/fireball_down.png"))
	{
		std::cout << "Error in loading the fireball texture";
	}

	if (!textureRight.loadFromFile("ASSETS/IMAGES/fireball_right.png"))
	{
		std::cout << "Error in loading the fireball texture";
	}

	if (!textureLeft.loadFromFile("ASSETS/IMAGES/fireball_left.png"))
	{
		std::cout << "Error in loading the fireball texture";
	}

	sprite.setTexture(textureUp);
}

void Bullet::setUpSound()
{
	if (!bulletSoundBuffer.loadFromFile("ASSETS/SOUND/gun-gunshot-02.wav"))
	{
		std::cout << "error with the sound file";
	}
	bulletSound.setBuffer(bulletSoundBuffer);

	if (!bulletHitWallSoundBuffer.loadFromFile("ASSETS/SOUND/zapsplat_impact_head_slam_against_table_13494.wav"))
	{
		std::cout << "error with the sound file";
	}
	bulletHitWallSound.setBuffer(bulletHitWallSoundBuffer);

	if (!bulletHitSoundBuffer.loadFromFile("ASSETS/SOUND/zapsplat_impact_thud_light_squelch_17502.wav"))
	{
		std::cout << "error with the sound file";
	}

	bulletHitSound.setBuffer(bulletHitSoundBuffer);

	if (!bulletHitOtherEenemyBuffer.loadFromFile("ASSETS/SOUND/zapsplat_impact_head_hit_ground_thump_17498 (1).wav"))
	{
		std::cout << "error with the sound file";
	}

	bulletHitOtherEenemy.setBuffer(bulletHitOtherEenemyBuffer);
}

bool Bullet::setDirection( sf::Sprite t_player, sf::Vector2f t_playerLookDirection)
{
	if (!isActive)
	{
		isActive = true;
		sprite.setPosition(t_player.getPosition().x, t_player.getPosition().y);
		Velocities = t_playerLookDirection;
		changeTexture(t_playerLookDirection);
		Velocities = vectorUnitVector(t_playerLookDirection) * 10.0f;
		bulletSound.play();
		return isActive;
	}
	else 
	{
		return false;
	}	
}

void Bullet::move()
{
	if (isActive)
	{
		sprite.move(Velocities);
		if (sprite.getPosition().x > 700)
		{
			isActive = false;
			Velocities = sf::Vector2f{ 0.0f, 0.0f };
			bulletHitWallSound.play();
		}
		else if (sprite.getPosition().x < 40)
		{
			isActive = false;
			Velocities = sf::Vector2f{ 0.0f, 0.0f };
			bulletHitWallSound.play();
		}
		else if (sprite.getPosition().y < 35)
		{
			isActive = false;
			Velocities = sf::Vector2f{ 0.0f, 0.0f };
			bulletHitWallSound.play();
		}
		else if (sprite.getPosition().y > 500)
		{
			isActive = false;
			Velocities = sf::Vector2f{ 0.0f, 0.0f };
			bulletHitWallSound.play();
		}
	}
}

void Bullet::changeTexture(sf::Vector2f t_playerLookDirection)
{
	if (t_playerLookDirection.x > 0.0)
	{
		sprite.setTexture(textureRight);
	}
	else if (t_playerLookDirection.x < 0.0)
	{
		sprite.setTexture(textureLeft);
	}
	else if (t_playerLookDirection.y > 0.0)
	{
		sprite.setTexture(textureDown);
	}
	else if (t_playerLookDirection.y < 0.0)
	{
		sprite.setTexture(textureUp);
	}
}

void Bullet::enemyFollowerCollision(sf::Sprite t_enemyFollower)
{
	if (sprite.getGlobalBounds().intersects(t_enemyFollower.getGlobalBounds()))
	{
		sprite.setPosition(sf::Vector2f{ -2000.0f, -2000.0f });
		isActive = false;
		bulletHitSound.play();
	}
}

void Bullet::enemyCollision(sf::Sprite t_enemy)
{
	if (sprite.getGlobalBounds().intersects(t_enemy.getGlobalBounds()))
	{
		isActive = false;
		sprite.setPosition(sf::Vector2f{ -2000.0f, -2000.0f });
		bulletHitOtherEenemy.play();
	}
}
