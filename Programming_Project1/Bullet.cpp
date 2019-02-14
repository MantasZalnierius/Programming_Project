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
	coldown = 5;
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		Velocities[i] = sf::Vector2f{ 0.0f, 0.0f };
	}
	position = sf::Vector2f{ -2000.0f, -2000.0f };
	sprite.setPosition(position);
	
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

void Bullet::setDirection(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection)
{
	if (coldown <= 0)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			for (int i = 0; i < MAX_BULLETS; i++)
			{
				if (sprite.getPosition().x == -2000)
				{
					sprite.setPosition(t_player.getPosition().x, t_player.getPosition().y);
					Velocities[i] = t_playerLookDirection;
					changeTexture(t_playerLookDirection);
					Velocities[i].x *= 2;
					Velocities[i].y *= 2;
					coldown = 10;
					break;
				}
			}
		}
	}
	else
	{
		coldown--;
	}
}

void Bullet::move(sf::RectangleShape t_screenArea, sf::Sprite t_player, sf::Vector2f t_playerLookDirection)
{
	for (int i = 0; i < MAX_BULLETS; i++)
	{
		if (sprite.getPosition().x != -2000)
		{
			sprite.move(Velocities[i]);
			if (!t_screenArea.getGlobalBounds().intersects(sprite.getGlobalBounds()))
			{
				sprite.setPosition(-2000, -2000);
				Velocities[i] = sf::Vector2f{ 0.0f, 0.0f };
			}
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
