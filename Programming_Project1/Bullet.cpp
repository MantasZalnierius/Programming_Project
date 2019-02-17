#include "Bullet.h"

Bullet::Bullet()
{
	loadSpriteAndTexture();
	setUpBullet();
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

void Bullet::setDirection(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection, int &t_cooldown)
{
	if (t_cooldown <= 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			if (!getStatus() || sprite.getPosition().x == -2000)
			{
				isActive = true;
				sprite.setPosition(t_player.getPosition().x, t_player.getPosition().y);
				Velocities = t_playerLookDirection;
				changeTexture(t_playerLookDirection);
				Velocities.x *= 2;
				Velocities.y *= 2;
				t_cooldown = 60;
			}
		}
	}
	else
	{
		t_cooldown--;
	}
}

void Bullet::move(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection)
{
	if (getStatus())
	{
		sprite.move(Velocities);
		if (!t_screenArea.getGlobalBounds().intersects(sprite.getGlobalBounds()))
		{
			isActive = false;
			sprite.setPosition(sf::Vector2f{ -2000.0f, -2000.0f });
			Velocities = sf::Vector2f{ 0.0f, 0.0f };
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
	}
}

void Bullet::enemyCollision(sf::Sprite t_enemy)
{
	if (sprite.getGlobalBounds().intersects(t_enemy.getGlobalBounds()))
	{
		sprite.setPosition(sf::Vector2f{ -2000.0f, -2000.0f });
		isActive = false;
	}
}