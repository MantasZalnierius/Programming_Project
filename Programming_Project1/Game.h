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
#include <string>

enum class GameStates
{
	MainMenu,
	Help,
	Exit,
	GamePlay,
	GameOver
};

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
	Player helpPlayer;
	Enemy enemies[MAX_ENEMIES];
	Bullet bullets[MAX_BULLETS];
	EnemyFollower enemyFollower1;
	EnemyFollower enemyFollower2;
	EnemyFollower enemyFollowerHelp;
	Enemy enemiesHelp;
	sf::Font m_font;  // font for writing text
	sf::Text m_firstEnemyFollowerHealth;
	sf::Text m_secondEnemyFollowerHealth;
	sf::Text m_playerHealth;
	sf::Text m_playerScore;	// text to write on the screen
	sf::Text m_Gameplay;
	sf::Text m_help;
	sf::Text m_exit;
	sf::Text m_playerHelpText;
	sf::Text m_enemyFollowerHelpText;
	sf::Text m_bouncingEenemyHelpText;
	sf::Text m_GameObjectiveHelpText;
	sf::Text m_HelpText;
	sf::Text m_highestScore;
	sf::Text m_currentScore;
	sf::Text m_gameOverText;
	GameStates GameScreen = GameStates::MainMenu;
	int cooldown;
	bool m_exitGame;
	int m_score;
	int higestScore = 0;
	int currentScore = 0;
	double ySpeed = -0.5;
	double ySpeeds = -0.5;
	double ySpeedss = -0.5;
	bool changedSpeed = false;
	bool changedSpeedx = false;
	bool changedSpeedy = false;

	std::string playerHealthString = "First Enemy Follower Health: " + std::to_string(enemyFollower1.getHealth());
	std::string playerScoreString = "Player Score: " + std::to_string(m_score);
	std::string MainMenuHelpText = "Controls: Press 2 to see the rules of the game. ";
	std::string mainMenuStartGameString = "New Game: Press 1 to play the game. ";
	std::string mainMenuExitString = "Exit: Press 3 to exit the game ";
	std::string PlayerHelpString = "You Can Move the Player using the The arrow keys W, S, A and D \n You can shoot by pressing the spacebar Key ";
	std::string EnemyFollowerHelpString = "This is a enemey follower.\n This will follow you and when he touches off you it will damage you.\n When you hit this enemy with a bullet it will damage it.\n When it loses all health it will respawn randomly on the top of the screen.\n This enemy will grant you 5 points when you destroy one of the enemy ";
	std::string bouncingEnemyHelpString = "This is a bouncing enemy. These enemies are invincable.\n They move and bounce off the walls.\n When they collide with the player, the player will lose health.\n They will absorb bullets but won't lose any life";
	std::string returnToMainMenuString = "Press 4 to return to Menu ";
	std::string currnetScoreString = "Higest Score: " + std::to_string(higestScore);
	std::string highestScoreString = "Current Score " + std::to_string(currentScore);

public:	  // declaration of member functions	
	Game(); // default constructor
	~Game();
	void	loadContent();
	void	update(sf::Time t_deltaTime);
	void	updateText();
	void	run();
	void	render();
	void	processEvents();
	void	SetupText(sf::Text &t_text, sf::Vector2f t_position, std::string t_textSentence);
};

#endif