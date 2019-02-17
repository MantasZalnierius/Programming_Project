#ifndef GAME
#define GAME

#include "Player.h"   // include Player header file
#include "SFML/Graphics.hpp" 
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "Globals.h"   // include Global header file
#include "Enemy.h"
#include "EnemyFollower.h"
#include "MyVector2.h"
#include "Bullet.h"

class Game
{
	// private data members

	// put your game objects here eg player object and 
	// array of enemy objects etc.
	sf::RenderWindow m_window;
	sf::Sprite m_backgroundSprite;
	sf::Texture m_backgroundTexture;
	sf::RectangleShape screenArea;
	Player player;
	Enemy enemies[MAX_ENEMIES];
	Bullet bullets[MAX_BULLETS];
	EnemyFollower enemyFollower1;
	EnemyFollower enemyFollower2;
	sf::Font m_font;  // font for writing text
	sf::Text m_firstEnemyFollowerHealth;
	sf::Text m_secondEnemyFollowerHealth;
	sf::Text m_playerHealth;
	sf::Text m_playerScore;	// text to write on the screen
	int cooldown;
	bool m_exitGame;
	int m_score;

public:	  // declaration of member functions	
	Game(); // default constructor
	~Game();
	void	loadContent();
	void	update(sf::Time t_deltaTime);
	void	updateText();
	void	run();
	void	render();
	void	processEvents();
};

#endif