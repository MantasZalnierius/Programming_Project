
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 

#include "Game.h"   // include Game header file

int main()
{
	srand(time(NULL)); // This is the random seed.
	Game game;
	game.loadContent();
	game.run();
	return 0;
}

Game::Game() : m_window(sf::VideoMode(static_cast<int>(SCREEN_WIDTH), static_cast<int>(SCREEN_HEIGHT)), "Joint Project Game", sf::Style::Default),
m_exitGame{ false }
// Default constructor
{
	setUpStrings();

	ySpeedForNewGameText = -0.5;
	ySpeedForHelpText = -0.5;
	ySpeedForExitText = -0.5;

	changedSpeedOnNewGameText = false;
	changedSpeedOnHelpText = false;
	changedSpeedOnExitText = false;

	speedOfText = -1;

	higestScore = 0;
	currentScore = 0;

	m_score = 0;
	cooldown = 0;
}

void Game::setUpStrings()
{
	playerHealthString = "Health: " + std::to_string(player.getHealth());
	playerScoreString = "Player Score: " + std::to_string(m_score);
	MainMenuHelpText = "Controls: Press 2 to see the rules of the game. ";
	mainMenuStartGameString = "New Game: Press 1 to play the game. ";
	mainMenuExitString = "Exit: Press 3 to exit the game ";
	PlayerHelpString = "You Can Move the Player using the The arrow keys W, S, A and D \n You can shoot by pressing the spacebar Key ";
	EnemyFollowerHelpString = "This is a enemey follower.\n This will follow you and when he touches off you it will damage you.\n When you hit this enemy with a bullet it will damage it.\n When it loses all health it will respawn randomly on the top of the screen.\n This enemy will grant you 5 points when you destroy one of the enemy ";
	bouncingEnemyHelpString = "This is a bouncing enemy. These enemies are invincable.\n They move and bounce off the walls.\n When they collide with the player, the player will lose health.\n They will absorb bullets but won't lose any life";
	returnToMainMenuString = "Press 4 to return to Menu ";
	currnetScoreString = "Higest Score: " + std::to_string(higestScore);
	highestScoreString = "Current Score " + std::to_string(currentScore);
}

Game::~Game()
{
}

void Game::loadContent()
// load the font file & setup the message
{
	if (!m_font.loadFromFile("ASSETS/FONTS/BebasNeue.otf"))
	{
		std::cout << "error with font file file";
	}

	if (!m_backgroundTexture.loadFromFile("ASSETS/IMAGES/floor.png"))
	{
		std::cout << "Did load floor file ";
	}

	m_backgroundSprite.setTexture(m_backgroundTexture);

	SetupText(m_playerHealth, sf::Vector2f{ player.getBody().getPosition() }, playerHealthString);
	SetupText(m_playerScore,  sf::Vector2f{ 50.0f, 530.0f }, playerScoreString);
	SetupText(m_Gameplay,   sf::Vector2f{ 250.0f, 150.0f }, mainMenuStartGameString);
	SetupText(m_help, sf::Vector2f{ 250.0f, 300.0f }, MainMenuHelpText);
	SetupText(m_exit, sf::Vector2f{ 250.0f, 450.0f }, mainMenuExitString);
	SetupText(m_GameObjectiveHelpText, sf::Vector2f{ 250.0f, 450.0f }, returnToMainMenuString);
	SetupText(m_playerHelpText, sf::Vector2f{ 160.0f, 100.0f }, PlayerHelpString);
	SetupText(m_enemyFollowerHelpText, sf::Vector2f{ 120.0f, 200.0f }, EnemyFollowerHelpString);
	SetupText(m_bouncingEenemyHelpText, sf::Vector2f{ 130.0f, 400.0f }, bouncingEnemyHelpString);
	SetupText(m_HelpText, sf::Vector2f{ 290.0f, 530.0f }, returnToMainMenuString);
	SetupText(m_highestScore, sf::Vector2f{ 250.0f, 150.0f }, highestScoreString);
	SetupText(m_currentScore, sf::Vector2f{ 250.0f, 300.0f }, currnetScoreString);
	SetupText(m_gameOverText, sf::Vector2f{ 250.0f, 450.0f }, returnToMainMenuString);
	m_playerHealth.setFillColor(sf::Color::Red);
}

void Game::SetupText(sf::Text &t_text, sf::Vector2f t_position, std::string t_textSentence)
{
	t_text.setFont(m_font);  // set the font for the text
	t_text.setCharacterSize(24); // set the text size
	t_text.setFillColor(sf::Color::White); // set the text colour
	t_text.setPosition(t_position);  // its position on the screen
	t_text.setString(t_textSentence);
}


void Game::processEvents()
{
	sf::Event event; // This initialize's, the Event object into memory.
	while (m_window.pollEvent(event))
	{

		if (sf::Event::Closed == event.type) // window message
		{
			m_window.close(); // This closes the window.
		}

		if (sf::Event::KeyPressed == event.type) //user key press
		{
			if (sf::Keyboard::Escape == event.key.code) // This checks if the user escaped the game.
			{
				m_exitGame = true;// This sets the bool to true.
			}

		}
	}
}

void Game::run()
{
	
	sf::Clock clock; // This initialize's the Clock object into memory.
	sf::Time timeSinceLastUpdate = sf::Time::Zero; // This lets the Time object equal to Zero.
	sf::Time timePerFrame = sf::seconds(1.f / 60.f); // 60 fps

	PlayerSpriteForTheHelpScreen.setUpHelpPlayer(sf::Vector2f{ 100.0f, 100.0f });
	enemyFollowerHelp.setUpEnemeyFollowerPoistionHelp(sf::Vector2f{ 50.0f, 200.0f });
	enemiesHelp.setUpEnemyForTheHelpScreen(sf::Vector2f{ 70.0f, 400.0f });
	cooldown = player.getCooldown();

	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart(); // This adds zero to the Time object.
		while (timeSinceLastUpdate > timePerFrame)  // This while loop will run every time, the times update is greater than the time per frame of the program.
		{
			timeSinceLastUpdate -= timePerFrame; // This substracts the time per frame, from the last update of time for this program.
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}

void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}

	if (GameScreen == GameStates::Exit)
	{
		m_exitGame = true;
	}

	updateMainMenuScreen();
	updateHelpScreen();
	updateGamePlayScreen();
	updateGameOverScreen();
}

void Game::updateGamePlayScreen()
{
	if (GameScreen == GameStates::GamePlay)
	{
		m_playerHealth.setPosition(player.getBody().getPosition().x - 10, player.getBody().getPosition().y - 20);
		m_firstEnemyFollowerHealth.setString("Enemy Follower Health: " + std::to_string(enemyFollower1.getHealth()));
		m_secondEnemyFollowerHealth.setString("Second Enemy Follower Health: " + std::to_string(enemyFollower2.getHealth()));
		m_playerHealth.setString("Health: " + std::to_string(player.getHealth()));
		m_playerScore.setString("Player Score: " + std::to_string(m_score));
	}

	if (GameScreen == GameStates::GamePlay)
	{
		player.move();
		player.boundaryCollision();

		player.enemyFollowerCollision(enemyFollower1.getBody());
		player.enemyFollowerCollision(enemyFollower2.getBody());
		enemyFollower1.playerCollision(player.getBody());
		enemyFollower2.playerCollision(player.getBody());

		enemyFollower1.move(player.getBody().getPosition());
		enemyFollower2.move(player.getBody().getPosition());

		player.enemyFollowerCollision(enemyFollower2.getBody());

		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			enemies[i].move();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if (player.getCooldown() <= 0)
			{
				for (int i = 0; i < MAX_BULLETS; i++)
				{
					if (bullets[i].setDirection(player.getBody(), player.getLookDirection()))
					{
						player.setCooldown(10);
						break;
					}
				}
			}
			else
			{
				player.setCooldown(player.getCooldown() - 1);
			}
		}

		if (player.getHealth() <= 0)
		{
			GameScreen = GameStates::GameOver;
			currentScore = m_score;
			if (currentScore > higestScore)
			{
				higestScore = currentScore;
				m_score = 0;
			}
		}


		for (int i = 0; i < MAX_BULLETS; i++)
		{
			bullets[i].move();
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			enemyFollower1.bulletCollision(bullets[i].getBody(), bullets[i].getStatus(), m_score);
			enemyFollower2.bulletCollision(bullets[i].getBody(), bullets[i].getStatus(), m_score);
			bullets[i].enemyFollowerCollision(enemyFollower1.getBody());
			bullets[i].enemyFollowerCollision(enemyFollower2.getBody());
		}

		for (int i = 0; i < MAX_BULLETS; i++)
		{
			for (int j = 0; j < MAX_ENEMIES; j++)
			{
				bullets[i].enemyCollision(enemies[j].getBody());
				player.enemyCollision(enemies[j].getBody());
			}
		}
	}
}

void Game::updateMainMenuScreen()
{
	if (GameScreen == GameStates::MainMenu)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
		{
			GameScreen = GameStates::GamePlay;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
		{
			GameScreen = GameStates::Help;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3))
		{
			GameScreen = GameStates::Exit;
		}
	}

	if (GameScreen == GameStates::MainMenu)
	{
		m_Gameplay.move(0, ySpeedForNewGameText);
		m_help.move(0, ySpeedForHelpText);
		m_exit.move(0, ySpeedForExitText);

		if (m_Gameplay.getPosition().y == 130 && !changedSpeedOnNewGameText)
		{
			ySpeedForNewGameText *= speedOfText;
			changedSpeedOnNewGameText = true;
		}
		if (m_Gameplay.getPosition().y == 150 && changedSpeedOnNewGameText)
		{
			ySpeedForNewGameText *= speedOfText;
			changedSpeedOnNewGameText = false;
		}

		if (m_help.getPosition().y == 280 && !changedSpeedOnHelpText)
		{
			ySpeedForHelpText *= speedOfText;
			changedSpeedOnHelpText = true;
		}

		if (m_help.getPosition().y == 300 && changedSpeedOnHelpText)
		{
			ySpeedForHelpText *= speedOfText;
			changedSpeedOnHelpText = false;
		}

		if (m_exit.getPosition().y == 430 && !changedSpeedOnExitText)
		{
			ySpeedForExitText *= speedOfText;
			changedSpeedOnExitText = true;
		}

		if (m_exit.getPosition().y == 450 && changedSpeedOnExitText)
		{
			ySpeedForExitText *= speedOfText;
			changedSpeedOnExitText = false;
		}
	}
}

void Game::updateHelpScreen()
{
	if (GameScreen == GameStates::Help)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			GameScreen = GameStates::MainMenu;
		}
	}
}

void Game::updateGameOverScreen()
{
	if (GameScreen == GameStates::GameOver)
	{
		m_highestScore.setString("Higest Score: " + std::to_string(higestScore));
		m_currentScore.setString("Current Score " + std::to_string(currentScore));
	}

	if (GameScreen == GameStates::GameOver)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
		{
			GameScreen = GameStates::MainMenu;
			player.setUpPlayer();
			player.loadSpriteAndTexture();
			for (int i = 0; i < MAX_ENEMIES; i++)
			{
				enemies[i].setUpEnemy();
			}
			enemyFollower1.setUpEnemyFollower();
			enemyFollower2.setUpEnemyFollower();
		}
	}
}


void Game::render()
{
	m_window.clear();
	m_window.draw(m_backgroundSprite);
	drawMainMenuScreen();
	drawHelpScreen();
	drawGamePlayScreen();
	drawGameOverScreen();
	m_window.display();
}

void Game::drawMainMenuScreen()
{
	if (GameScreen == GameStates::MainMenu)
	{
		m_window.draw(m_Gameplay);
		m_window.draw(m_help);
		m_window.draw(m_exit);
	}
}

void Game::drawHelpScreen()
{
	if (GameScreen == GameStates::Help)
	{
		m_window.draw(PlayerSpriteForTheHelpScreen.getBody());
		m_window.draw(enemyFollowerHelp.getBody());
		m_window.draw(enemiesHelp.getBody());
		m_window.draw(m_playerHelpText);
		m_window.draw(m_enemyFollowerHelpText);
		m_window.draw(m_bouncingEenemyHelpText);
		m_window.draw(m_HelpText);
	}
}

void Game::drawGamePlayScreen()
{
	if (GameScreen == GameStates::GamePlay)
	{
		m_window.draw(player.getBody());
		for (int i = 0; i < MAX_ENEMIES; i++)
		{
			m_window.draw(enemies[i].getBody());
		}
		for (int i = 0; i < MAX_BULLETS; i++)
		{
			if (bullets[i].getStatus())
			{
				m_window.draw(bullets[i].getBody());
			}
		}
		m_window.draw(enemyFollower1.getBody());
		m_window.draw(enemyFollower2.getBody());
		m_window.draw(m_playerHealth);
		m_window.draw(m_firstEnemyFollowerHealth);
		m_window.draw(m_secondEnemyFollowerHealth);
		m_window.draw(m_playerScore);
	}
}

void Game::drawGameOverScreen()
{
	if (GameScreen == GameStates::GameOver)
	{
		m_window.draw(m_currentScore);
		m_window.draw(m_highestScore);
		m_window.draw(m_gameOverText);
	}
}

