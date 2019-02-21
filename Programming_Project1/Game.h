#ifndef GAME
#define GAME

#include "SFML/Graphics.hpp" 
#include "SFML\Audio.hpp"
#include <string>
#include <iostream>
#include <cstdlib>  // include support for randomizing
#include <ctime>   // supports ctime function
#include "Player.h"   // include Player header file
#include "Globals.h"   // include Global header file
#include "Enemy.h"
#include "EnemyFollower.h"
#include "MyVector2.h"
#include "Bullet.h"


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
	sf::Sound deathSound;
	sf::SoundBuffer deathSoundBuffer;
	sf::Music mainMenuMusic;
	sf::Music GamePlayMusic;
	Player player;
	Player PlayerSpriteForTheHelpScreen;
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
	int m_score;
	int higestScore;
	int currentScore;
	int speedOfText;
	int counter = 0;
	bool m_exitGame;

	double ySpeedForNewGameText;
	double ySpeedForHelpText;
	double ySpeedForExitText;
	bool changedSpeedOnNewGameText;
	bool changedSpeedOnHelpText;
	bool changedSpeedOnExitText;

	std::string playerHealthString;
	std::string playerScoreString;
	std::string MainMenuHelpText;
	std::string mainMenuStartGameString;
	std::string mainMenuExitString;
	std::string PlayerHelpString;
	std::string EnemyFollowerHelpString;
	std::string bouncingEnemyHelpString;
	std::string returnToMainMenuString;
	std::string currnetScoreString;
	std::string highestScoreString;

public:	  // declaration of member functions	
	Game(); // default constructor
	~Game();
	void	loadContent();
	void	setUpStrings();
	void	update(sf::Time t_deltaTime);
	void	run();
	void	render();
	void	processEvents();
	void	drawMainMenuScreen();
	void	drawHelpScreen();
	void	drawGamePlayScreen();
	void	drawGameOverScreen();
	void	SetupText(sf::Text &t_text, sf::Vector2f t_position, std::string t_textSentence);
	void	updateGamePlayScreen();
	void	updateMainMenuScreen();
	void	updateHelpScreen();
	void	updateGameOverScreen();
	void	setUpSoundsAndMusic();
	void	setUpGame();
};

#endif