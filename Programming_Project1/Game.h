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


enum class GameStates // This is enum for the main menu of the game.
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
	sf::RenderWindow m_window; // This sf::RenderWindow member variable repersents the window of the program.

	sf::Sprite m_backgroundSprite; // This sf::Sprite member variable repersents the background sprite.
	sf::Texture m_backgroundTexture; // This sf::Texture member variable repersents the background texture.
	sf::Sound m_deathSound; // This sf::Sound member variable repersents the death sound of the player.
	sf::SoundBuffer m_deathSoundBuffer; // This sf::SoundBiffer member variable repersents the death sound buffer of the player.
	sf::Music m_mainMenuMusic; // This sf::Music member variable repersents the main menu music of the game.
	sf::Music m_gamePlayMusic; // This sf::Music member variable repersents the gameplay of the game.

	Player player; // This makes an instance of the Player Class.
	Player PlayerSpriteForTheHelpScreen; // This makes an instance of the Player Class.
	Enemy enemies[MAX_ENEMIES]; // This makes an instance of the Enemy Class.
	Bullet bullets[MAX_BULLETS]; // This makes an instance of the bullet Class.
	EnemyFollower enemyFollower1; // This makes an instance of the enemy Follower Class.
	EnemyFollower enemyFollower2; // This makes an instance of the enemy Follower Class.
	EnemyFollower enemyFollowerHelp; // This makes an instance of the enemy Follower Class.
	Enemy enemiesHelp; // This makes an instance of the enemy Class.

	sf::Font m_font;  // font for writing text
	sf::Text m_playerHealth; // This sf::Text member variable repersents health of the player
	sf::Text m_playerScore;	// This sf::Text member variable repersents score of the player
	sf::Text m_Gameplay; // This sf::Text member variable repersents the text on the main menu screen.
	sf::Text m_help; // This sf::Text member variable repersents the text on the main menu screen.
	sf::Text m_exit; // This sf::Text member variable repersents the text on the main menu screen.
	sf::Text m_playerHelpText; // This sf::Text member variable repersents the text on the help screen.
	sf::Text m_enemyFollowerHelpText; // This sf::Text member variable repersents the text on the help screen.
	sf::Text m_bouncingEenemyHelpText; // This sf::Text member variable repersents the text on the help screen.
	sf::Text m_returnToMainMenuText; // This sf::Text member variable repersents the text on the help screen.
	sf::Text m_HelpText; // This sf::Text member variable repersents the text on the help screen.
	sf::Text m_highestScoreText; // This sf::Text member variable repersents the highest score in the game.
	sf::Text m_currentScoreText; // This sf::Text member variable repersents the current score of the player.
	sf::Text m_gameOverText; // This sf::Text member variable repersents the game over text of the game.

	GameStates GameScreen = GameStates::MainMenu;

	int m_score; // This int member variable repersents the score in the game.
	int m_higestScore; // This int member variable repersents the highest score in the game.
	int m_currentScore; // This int member variable repersents the current score in the game.
	int m_speedOfText; // This int member variable repersents the speed of the text in the game.

	double m_ySpeedForNewGameText; // This double member variable repersents the Y axis speed of the new game text.
	double m_ySpeedForHelpText; // This double member variable repersents the Y axis speed of the help text.
	double m_ySpeedForExitText; // This double member variable repersents the Y axis speed of the exit text.

	bool m_changedSpeedOnNewGameText; // This bool member variable checks if the new game text has changed it's speed.
	bool m_changedSpeedOnHelpText; // This bool member variable checks if the help text has changed it's speed.
	bool m_changedSpeedOnExitText; // This bool member variable checks if the exit text has changed it's speed.
	bool m_exitGame; // This bool member variable checks if the program has been exited.

	std::string m_playerHealthString; // This std::string member variable repersents the player health text. 
	std::string m_playerScoreString; // This std::string member variable repersents the player score text.
	std::string m_mainMenuHelpText; // This std::string member variable repersents the main menu help text.
	std::string m_mainMenuStartGameString; // This std::string member variable repersents the main menu start a new game text.
	std::string m_mainMenuExitString; // This std::string member variable repersents the main menu exit text.
	std::string m_playerHelpString; // This std::string member variable repersents the player help text.
	std::string m_enemyFollowerHelpString; // This std::string member variable repersents the enemy follower help text.
	std::string m_bouncingEnemyHelpString; // This std::string member variable repersents the bouncing enemy help text.
	std::string m_returnToMainMenuString; // This std::string member variable repersents the return to main menu text.
	std::string m_currnetScoreString; // This std::string member variable repersents the current score text.
	std::string m_highestScoreString; // This std::string member variable repersents the higest score text.

public:	  // declaration of member functions	
	Game(); // This is the default constructor for the game class.
	~Game(); // This is the default destructor for the game class.
	void	loadContent(); // This is the default constructor for the game class.
	void	setUpStrings(); // This is the default destructor for the game class.
	void	update(sf::Time t_deltaTime); // This member function updates the game every 60th a second.
	void	run(); // This member function runs the game.
	void	render(); // This member function renders the game.
	void	processEvents(); // This member function process user created events.
	void	drawMainMenuScreen(); // This member function draws everything for the main menu screen.
	void	drawHelpScreen(); // This member function draws everything for the help screen.
	void	drawGamePlayScreen(); // This member function draws everything for the gameplay screen.
	void	drawGameOverScreen(); // This member function draws everything for the game over screen.
	void	SetupText(sf::Text &t_text, sf::Vector2f t_position, std::string t_textSentence); // This member function sets up all the text.
	void	updateGamePlayScreen(); // This member function updates the game play screen.
	void	updateMainMenuScreen(); // This member function updates the main menu screen.
	void	updateHelpScreen(); // This member function  updates the help screen.
	void	updateGameOverScreen(); // This member function  updates the game over screen.
	void	setUpSoundsAndMusic(); // This member function sets up the sound and music.
	void	setUpGame(); // This member function sets up the game.
};

#endif